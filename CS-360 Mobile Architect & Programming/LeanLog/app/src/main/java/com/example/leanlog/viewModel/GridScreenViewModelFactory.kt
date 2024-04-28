import android.content.Context
import androidx.lifecycle.ViewModel
import androidx.lifecycle.ViewModelProvider
import com.example.leanlog.viewModel.GridScreenViewModel

class GridScreenViewModelFactory(private val context: Context, private val username: String) : ViewModelProvider.Factory {
    override fun <T : ViewModel> create(modelClass: Class<T>): T {
        if (modelClass.isAssignableFrom(GridScreenViewModel::class.java)) {
            return GridScreenViewModel(context, username) as T
        }
        throw IllegalArgumentException("Unknown ViewModel class")
    }
}
