package com.example.leanlog.ui.login

import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.*
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.text.input.PasswordVisualTransformation
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.navigation.NavController
import androidx.room.Room
import com.example.leanlog.R
import com.example.leanlog.database.AppDatabase
import com.example.leanlog.database.User
import com.example.leanlog.viewModel.LoginViewModel
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun LoginScreen(navController: NavController, loginViewModel: LoginViewModel) {
    val context = LocalContext.current
    var username by remember { mutableStateOf("") }
    var password by remember { mutableStateOf("") }
    var loginFailed by remember { mutableStateOf(false) }
    var showRegistrationMessage by remember { mutableStateOf(false) }
    var registeredUser by remember { mutableStateOf("") }

    // Initialize the database
    val db = remember {
        Room.databaseBuilder(
            context,
            AppDatabase::class.java, "database-name"
        ).fallbackToDestructiveMigration().build()
    }
    val userDao = remember { db.userDao() }

    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(16.dp),
        verticalArrangement = Arrangement.Top,
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Text(
            text = "Lean Log",
            style = MaterialTheme.typography.headlineMedium.copy(
                fontWeight = FontWeight.Bold,
                fontSize = 80.sp
            ),
            modifier = Modifier.align(Alignment.CenterHorizontally)
        )
        Image(
            painter = painterResource(id = R.drawable.bitmap),
            contentDescription = "Login Icon",
            modifier = Modifier
                .size(350.dp)
                .align(Alignment.CenterHorizontally)
        )

        if (loginFailed) {
            Text("Login failed. Please try again.", color = MaterialTheme.colorScheme.error)
            Spacer(modifier = Modifier.height(8.dp))
        }

        if (showRegistrationMessage) {
            Text("Registered user: $registeredUser", color = MaterialTheme.colorScheme.primary)
            Spacer(modifier = Modifier.height(8.dp))
        }

        OutlinedTextField(
            value = username,
            onValueChange = { username = it },
            label = { Text("Username") },
            singleLine = true,
            modifier = Modifier.fillMaxWidth()
        )
        Spacer(modifier = Modifier.height(8.dp))

        OutlinedTextField(
            value = password,
            onValueChange = { password = it },
            label = { Text("Password") },
            visualTransformation = PasswordVisualTransformation(),
            singleLine = true,
            modifier = Modifier.fillMaxWidth()
        )
        Spacer(modifier = Modifier.height(16.dp))

        Button(
            onClick = {
                CoroutineScope(Dispatchers.IO).launch {
                    val user = userDao.authenticate(username, password)
                    withContext(Dispatchers.Main) {
                        if (user != null) {
                            // Pass username to GridScreen
                            navController.navigate("gridScreen/$username")
                        } else {
                            loginFailed = true
                        }
                    }
                }
            },
            modifier = Modifier.fillMaxWidth()
        ) {
            Text("Log In")
        }
        Spacer(modifier = Modifier.height(8.dp))

        Button(
            onClick = {
                CoroutineScope(Dispatchers.IO).launch {
                    userDao.insertUser(User(username, password))
                    withContext(Dispatchers.Main) {
                        registeredUser = username
                        showRegistrationMessage = true
                        loginFailed = false
                    }
                }
            },
            modifier = Modifier.fillMaxWidth()
        ) {
            Text("Register")
        }
    }
}
