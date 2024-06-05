import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.width
import androidx.compose.foundation.shape.AbsoluteCutCornerShape
import androidx.compose.material.MaterialTheme
import androidx.compose.material.Surface
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.layout.layoutId
import androidx.compose.ui.platform.testTag
import androidx.compose.ui.semantics.contentDescription
import androidx.compose.ui.semantics.semantics
import androidx.compose.ui.unit.dp
import model.BirdImage
import org.jetbrains.compose.resources.ExperimentalResourceApi
import org.jetbrains.compose.resources.painterResource

@Composable
fun BirdAppTheme(
    content: @Composable () -> Unit
) {
    MaterialTheme(
        colors = MaterialTheme.colors.copy(primary = Color.White), shapes = MaterialTheme.shapes.copy(
            small = AbsoluteCutCornerShape(0.dp), medium = AbsoluteCutCornerShape(0.dp),
            large = AbsoluteCutCornerShape(0.dp)
        )
    ) {
        content()
    }
}

@OptIn(ExperimentalResourceApi::class)
@Composable
fun App() {
    Surface(color = Color(0xFFFFFFFF)) {
        Column(Modifier.layoutId("测试 Layout1")) {
            Text("Letter 1", Modifier.padding(top = 50.dp).layoutId("测试 Layout2"), color = Color.Red)
            Text(
                "Hello world!",
                color = Color.Black
            )
            Text("Number", Modifier.padding(top = 20.dp).testTag("测试 view1"), color = Color.Red)
            Text(
                "2023.10.13 20:20",
                color = Color.Black
            )
            Text("Chinese", Modifier.padding(top = 20.dp).testTag("测试 view2"), color = Color.Red)
            Text(
                "你好，世界！",
                color = Color.Black
            )
            Text(
                "Symbol", Modifier.padding(top = 20.dp).semantics { contentDescription = "测试 semantics" },
                color = Color.Red
            )
            Text(
                "~!@#$%^&*()_+{}:<>?|",
                color = Color.Black
            )
        }
    }
//    BirdAppTheme {
//        val birdsViewModel = getViewModel(Unit, viewModelFactory { BirdsViewModel() })
//        BirdsPage(birdsViewModel)

//    }
}

//@Composable
//fun BirdsPage(viewModel: BirdsViewModel) {
//    val uiState by viewModel.uiState.collectAsState()
//    Column(
//        Modifier.fillMaxSize(),
//        horizontalAlignment = Alignment.CenterHorizontally,
//        verticalArrangement = Arrangement.Center
//    ) {
//
//        Row(
//            Modifier.fillMaxWidth().padding(5.dp),
//            horizontalArrangement = Arrangement.spacedBy(5.dp)
//        ) {
//            for (category in uiState.categories) {
//                Button(
//                    onClick = {
//                        viewModel.selectCategory(category)
//                    },
//                    modifier = Modifier.aspectRatio(1.0f).fillMaxSize().weight(1.0f),
//                    elevation = ButtonDefaults.elevation(
//                        defaultElevation = 0.dp,
//                        focusedElevation = 0.dp
//                    )
//                )
//                {
//                    Text(category)
//                }
//            }
//        }
//        AnimatedVisibility(uiState.selectedImages.isNotEmpty()) {
//            LazyVerticalGrid(
//                columns = GridCells.Fixed(2),
//                horizontalArrangement = Arrangement.spacedBy(5.dp),
//                verticalArrangement = Arrangement.spacedBy(5.dp),
//                modifier = Modifier.fillMaxSize().padding(horizontal = 5.dp),
//                content = {
//                    items(uiState.selectedImages) {
//                        BirdImageCell(it)
//                    }
//                }
//            )
//        }
//    }
//}

@OptIn(ExperimentalResourceApi::class)
@Composable
fun BirdImageCell(image: BirdImage) {
//    val path = "https://s1.yy.com/guild/header/10001.jpg"
//    KamelImage(
//        asyncPainterResource(path),
//        "${image.category} by ${image.author}",
//        contentScale = ContentScale.Crop,
//        modifier = Modifier.fillMaxWidth().aspectRatio(1.0f)
//    )
    Image(
        painterResource("drawable-xxhdpi/test.jpg"), contentDescription = null,
        modifier = Modifier.width(30.dp).height(30.dp)
    )
}

expect fun getPlatformName(): String
