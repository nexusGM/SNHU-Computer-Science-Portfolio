package com.example.leanlog.database.dao

import androidx.lifecycle.LiveData
import androidx.room.Dao
import androidx.room.Delete
import androidx.room.Insert
import androidx.room.Query
import com.example.leanlog.database.GridItem


@Dao
interface GridItemDao {
    @Insert
    suspend fun insertGridItem(gridItem: GridItem)

    @Delete
    suspend fun deleteGridItem(gridItem: GridItem): Int

    @Query("SELECT * FROM gridItems WHERE username = :username")
    fun getGridItemsByUser(username: String): LiveData<List<GridItem>>
}
