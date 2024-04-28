package com.example.leanlog.viewModel

import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel

class LoginViewModel : ViewModel() {
    private val _loginState = MutableLiveData<LoginState>()

    private val _username = MutableLiveData<String>()
    val username: LiveData<String> = _username


    private fun validateCredentials(username: String, password: String): Boolean {
        return username.isNotBlank() && password.isNotBlank() && password.length > 5
    }

    sealed class LoginState {
        object Success : LoginState()
        data class Error(val message: String) : LoginState()
    }
}


