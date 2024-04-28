package com.example.leanlog.ui.grid

import GridScreenViewModelFactory
import android.widget.Toast
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.lazy.grid.GridCells
import androidx.compose.foundation.lazy.grid.LazyVerticalGrid
import androidx.compose.foundation.lazy.grid.items
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.Add
import androidx.compose.material.icons.filled.Notifications
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import androidx.navigation.NavController
import com.example.leanlog.database.GridItem
import com.example.leanlog.viewModel.GridScreenViewModel
import androidx.lifecycle.viewmodel.compose.viewModel
import androidx.compose.ui.Alignment
import androidx.compose.ui.platform.LocalContext
import com.example.leanlog.ui.dialog.AddItemDialog
import com.google.accompanist.permissions.ExperimentalPermissionsApi
import com.google.accompanist.permissions.PermissionStatus
import com.google.accompanist.permissions.rememberPermissionState
import android.Manifest
import android.app.NotificationChannel
import android.app.NotificationManager
import android.content.Context
import android.os.Build
import android.util.Log
import androidx.activity.compose.rememberLauncherForActivityResult
import androidx.activity.result.contract.ActivityResultContracts
import androidx.compose.runtime.livedata.observeAsState
import androidx.core.app.NotificationCompat
import com.example.leanlog.R

@OptIn(ExperimentalMaterial3Api::class, ExperimentalPermissionsApi::class)
@Composable
fun GridScreen(navController: NavController, username: String) {
    val context = LocalContext.current
    val factory = GridScreenViewModelFactory(context, username)
    val viewModel: GridScreenViewModel = viewModel(factory = factory)
    val gridItems by viewModel.gridItems.observeAsState(initial = listOf())
    val smsPermissionState = rememberPermissionState(permission = Manifest.permission.POST_NOTIFICATIONS)
    var showDialog by remember { mutableStateOf(false) }
    var showGoalWeightDialog by remember { mutableStateOf(false) }

    LaunchedEffect(key1 = Unit) {
        viewModel.getUserGoalWeight()
    }

    val userGoalWeight by viewModel.userGoalWeight.observeAsState()

    val confirmGoalWeight: (Float) -> Unit = { goalWeight ->
        viewModel.saveGoalWeight(goalWeight)
    }

    val requestPermissionLauncher = rememberLauncherForActivityResult(
        contract = ActivityResultContracts.RequestPermission()
    ) { isGranted ->
        if (isGranted) {
            Toast.makeText(context, "SMS permission granted.", Toast.LENGTH_SHORT).show()
        } else {
            Toast.makeText(context, "SMS permission denied.", Toast.LENGTH_SHORT).show()
        }
    }

    Scaffold { padding ->
        Box(modifier = Modifier.padding(padding).fillMaxSize()) {
            GridContent(gridItems = gridItems, onDeleteItem = viewModel::deleteItem, padding = PaddingValues())

            FloatingActionButton(
                onClick = { showDialog = true },
                modifier = Modifier
                    .align(Alignment.BottomEnd)
                    .padding(16.dp),
                containerColor = MaterialTheme.colorScheme.secondary
            ) {
                Icon(imageVector = Icons.Filled.Add, contentDescription = "Add")
            }

            FloatingActionButton(
                onClick = {
                    when (smsPermissionState.status) {
                        is PermissionStatus.Granted -> {
                            showGoalWeightDialog = true
                        }
                        else -> {
                            requestPermissionLauncher.launch(Manifest.permission.POST_NOTIFICATIONS)
                        }
                    }
                },
                modifier = Modifier
                    .align(Alignment.BottomStart)
                    .padding(16.dp),
                containerColor = MaterialTheme.colorScheme.secondary
            ) {
                Icon(imageVector = Icons.Default.Notifications, contentDescription = "Request SMS Permission")
            }
        }

        if (showDialog) {
            Log.d("DialogState", "Dialog is displayed")
            AddItemDialog(
                onDismissRequest = {
                    Log.d("DialogState", "Dismissing dialog")
                    showDialog = false
                },
                onConfirm = { date, weight ->
                    Log.d("DialogState", "Confirming addition: Date = $date, Weight = $weight")
                    viewModel.addNewItem(date, weight)
                    showDialog = false
                    Log.d("DialogState", "Dialog should be closed now")

                    val goalWeight = userGoalWeight ?: 0f

                    if (weight < goalWeight) {
                        Log.d("DialogState", "Goal weight met sending Notification")
                        sendSMSNotification(context, "Weight Goal Met", "Great Job!!!")
                    } else {
                        Log.d("DialogState", "Goal weight not met$goalWeight")
                    }
                }
            )
        }

        if (showGoalWeightDialog) {
            val currentGoalWeight by viewModel.userGoalWeight.observeAsState()
            GoalWeightDialog(
                currentGoalWeight = currentGoalWeight ?: 0f,
                onDismissRequest = {
                    showGoalWeightDialog = false
                },
                onConfirm = { goalWeight ->
                    viewModel.saveGoalWeight(goalWeight)
                    showGoalWeightDialog = false
                }
            )
        }
    }
}

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun GoalWeightDialog(
    currentGoalWeight: Float,
    onDismissRequest: () -> Unit,
    onConfirm: (Float) -> Unit
) {
    var goalWeight by remember { mutableStateOf(currentGoalWeight.toString()) }
    var showError by remember { mutableStateOf(false) }

    AlertDialog(
        onDismissRequest = onDismissRequest,
        title = { Text(text = "Set Goal Weight") },
        text = {
            Column {
                Text(text = "Enter your goal weight:")
                TextField(
                    value = goalWeight,
                    onValueChange = { goalWeight = it },
                    modifier = Modifier.fillMaxWidth()
                )
            }
        },
        confirmButton = {
            Button(
                onClick = {
                    if (goalWeight.isNotEmpty()) {
                        val weight = goalWeight.toFloatOrNull()
                        weight?.let {
                            onConfirm(it)

                            onDismissRequest()
                        } ?: run {
                            showError = true
                        }
                    } else {
                        showError = true
                    }
                }
            ) {
                Text(text = "Confirm")
            }
        },
        dismissButton = {
            Button(
                onClick = { onDismissRequest() }
            ) {
                Text(text = "Cancel")
            }
        }
    )

    // Show a Snackbar if showError is true
    if (showError) {
        Snackbar(
            modifier = Modifier.padding(8.dp),
            action = {
                TextButton(onClick = { showError = false }) {
                    Text(text = "Dismiss")
                }
            }
        ) {
            Text(text = "Please enter a valid goal weight.")
        }
    }
}


@Composable
fun GridContent(gridItems: List<GridItem>, onDeleteItem: (GridItem) -> Unit, padding: PaddingValues) {
    LazyVerticalGrid(
        columns = GridCells.Fixed(2),
        contentPadding = padding,
        modifier = Modifier.padding(8.dp)
    ) {
        items(gridItems) { item ->
            GridItemCard(item = item, onDeleteItem = onDeleteItem)
        }
    }
}

@Composable
fun GridItemCard(item: GridItem, onDeleteItem: (GridItem) -> Unit) {
    Card(
        modifier = Modifier
            .padding(8.dp)
            .fillMaxWidth(),
        elevation = CardDefaults.cardElevation(8.dp)
    ) {
        Column(modifier = Modifier.padding(16.dp)) {
            Text(text = "Date: ${item.date}", style = MaterialTheme.typography.bodyLarge)
            Text(text = "Weight: ${item.weight}lbs", style = MaterialTheme.typography.bodyLarge)
            Spacer(modifier = Modifier.height(8.dp))
            Button(onClick = { onDeleteItem(item) }) {
                Text("Delete")
            }
        }
    }
}


fun sendSMSNotification(context: Context, title: String, message: String) {
    val notificationManager = context.getSystemService(Context.NOTIFICATION_SERVICE) as NotificationManager?

    if (notificationManager == null) {
        Log.e("SMSNotificationDebug", "Failed to get NotificationManager")
        return
    }

    val channelId = "sms_activity_channel"
    val channelName = "SMS Activity"
    val channelDescription = "Notifications for SMS activities"

    if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
        val importance = NotificationManager.IMPORTANCE_HIGH
        val channel = NotificationChannel(channelId, channelName, importance)
        channel.description = channelDescription
        notificationManager.createNotificationChannel(channel)
        Log.d("SMSNotificationDebug", "Notification channel created or already exists: $channelId")
    }

    val notificationBuilder = NotificationCompat.Builder(context, channelId)
        .setContentTitle(title)
        .setContentText(message)
        .setSmallIcon(R.drawable.ic_notification)
        .setPriority(NotificationCompat.PRIORITY_HIGH)

    Log.d("SMSNotificationDebug", "Sending SMS notification: $title - $message")
    notificationManager.notify(channelId.hashCode(), notificationBuilder.build())
}
