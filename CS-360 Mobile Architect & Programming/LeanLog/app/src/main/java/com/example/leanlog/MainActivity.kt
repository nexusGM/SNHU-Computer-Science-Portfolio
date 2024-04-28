package com.example.leanlog

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.runtime.*
import androidx.lifecycle.viewmodel.compose.viewModel
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable
import androidx.navigation.compose.rememberNavController
import com.example.leanlog.ui.grid.GridScreen
import com.example.leanlog.ui.login.LoginScreen
import com.example.leanlog.ui.theme.LeanLogTheme
import com.example.leanlog.viewModel.LoginViewModel

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            LeanLogTheme {
                AppNavigation()
            }
        }
    }
}

@Composable
fun AppNavigation() {
    val navController = rememberNavController()
    val loginViewModel: LoginViewModel = viewModel()

    NavHost(navController = navController, startDestination = "loginScreen") {
        composable("loginScreen") {
            LoginScreen(navController, loginViewModel)
        }
        composable("gridScreen/{username}") {
            val username = it.arguments?.getString("username") ?: ""
            GridScreen(navController, username)
        }
    }
}