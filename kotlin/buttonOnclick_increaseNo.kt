package com.example.login

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.Button
import androidx.compose.material3.Text
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableIntStateOf
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp


class StateActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            var count by remember { mutableIntStateOf(0) }
            var stateshow by remember { mutableStateOf(true) }
            var clickEnabled by remember { mutableStateOf(false) }
            Column {
                Row {
                    Button(
                        onClick = {
                            count++
                        }) {
                        Text(text = "저장 ")
                        Text(text = "$count")
                    }

                    Button(
                        enabled = count > 0,
                        onClick = {
                            count--
                        }) {
                        Text(text = "삭제 ")
                        Text(text = "$count")
                    }

                    Button(
                        onClick = {
                            count = 0
                        }) {
                        Text(text = "초기화")
                    }

                    Button(
                        onClick = {
                            stateshow = !stateshow
                        })
                    {
                        Text(text = if (stateshow) "결과 숨김" else "결과 보임")
                    }
                }
                if (stateshow) {
                    for (i in 1..count) {
                        Text(text = "$i: 저장했어요.")
                    }
                } else {
                    Text(text = "")
                }
            }
        }
    }
}
