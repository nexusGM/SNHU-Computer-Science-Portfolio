package com.example.leanlog.viewModel

import android.app.Application
import android.content.Context
import android.util.Log
import androidx.lifecycle.AndroidViewModel
import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import androidx.lifecycle.ViewModelProvider
import androidx.lifecycle.viewModelScope
import com.example.leanlog.database.DatabaseManager
import com.example.leanlog.database.GridItem
import com.example.leanlog.database.User
import kotlinx.coroutines.launch

class GridScreenViewModel(private val context: Context, private val username: String) : ViewModel() {
    private val db = DatabaseManager.getDatabase(context)

    val gridItems: LiveData<List<GridItem>> = db.gridItemDao().getGridItemsByUser(username)

    private val _userGoalWeight = MutableLiveData<Float>()
    val userGoalWeight: LiveData<Float>
        get() = _userGoalWeight

    fun addNewItem(date: String, weight: Float) {
        viewModelScope.launch {
            try {
                db.gridItemDao().insertGridItem(GridItem(0, date, weight, username))
                Log.d("DatabaseInsert", "Item inserted successfully")
            } catch (e: Exception) {
                Log.e("DatabaseError", "Error inserting item", e)
            }
        }
    }

    fun deleteItem(gridItem: GridItem) {
        viewModelScope.launch {
            db.gridItemDao().deleteGridItem(gridItem)
        }
    }

    fun getUserGoalWeight() {
        viewModelScope.launch {
            _userGoalWeight.value = db.userDao().getGoalWeight(username)
        }
    }

    fun saveGoalWeight(weight: Float) {
        viewModelScope.launch {
            try {
                db.userDao().updateGoalWeight(username, weight)
                _userGoalWeight.postValue(weight)
                Log.d("GoalWeight", "Goal weight saved successfully: $weight")
            } catch (e: Exception) {
                Log.e("GoalWeight", "Error saving goal weight", e)
            }
        }
    }

}
