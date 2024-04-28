package com.example.leanlog.database

import androidx.room.Entity
import androidx.room.PrimaryKey

@Entity(tableName = "gridItems")
data class GridItem(
    @PrimaryKey(autoGenerate = true) val id: Int = 0,
    val date: String,
    val weight: Float,
    val username: String
)

