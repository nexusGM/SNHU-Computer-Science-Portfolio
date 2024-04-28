package com.example.leanlog.database.dao

import androidx.room.*
import com.example.leanlog.database.User

@Dao
interface UserDao {

    @Insert
    suspend fun insertUser(user: User)

    @Query("SELECT * FROM users WHERE username = :username AND password = :password LIMIT 1")
    suspend fun authenticate(username: String, password: String): User?

    @Query("UPDATE users SET goalWeight = :goalWeight WHERE username = :username")
    suspend fun updateGoalWeight(username: String, goalWeight: Float)

    @Query("SELECT goalWeight FROM users WHERE username = :username")
    suspend fun getGoalWeight(username: String): Float?
}
