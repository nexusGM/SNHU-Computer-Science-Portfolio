package com.example.leanlog.ui.grid

import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import com.example.leanlog.database.GridItem

@Composable
fun GridItemView(item: GridItem) {
    Text(text = "Item ${item.id}")
}
