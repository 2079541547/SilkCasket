package eternal.future.silkcasket;

import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import java.io.File;

import eternal.future.silkcasket.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // 用于加载 'silkcasket' 库在应用程序启动时。
    static {
        System.loadLibrary("exexample");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        new File(this.getExternalFilesDir(null), "").mkdirs();

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
    }

    public void onMyButtonClick(View view) {
        new Thread(() -> {
            // 调用本地方法
            func();

            // 使用Handler将结果传递给主线程
            new Handler(Looper.getMainLooper()).post(new Runnable() {
                @Override
                public void run() {
                    // 打印日志
                    Log.d("MainActivity", "func() has been executed successfully");

                    // 显示Toast消息
                    Toast.makeText(MainActivity.this, "func() has been executed successfully", Toast.LENGTH_SHORT).show();
                }
            });
        }).start();
    }

    /**
     * 由 'silkcasket' 原生库实现的一个原生方法，
     * 这个库与该应用程序一起打包。
     */
    public native void func();
}