package com.maxst.www.zxingcpptest;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.Window;
import android.view.WindowManager;

public class MainActivity extends AppCompatActivity {
    static {
        System.loadLibrary("NativeManager");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_NO_TITLE);

        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        setContentView(R.layout.activity_main);
        if (null == savedInstanceState) {
            getFragmentManager().beginTransaction().replace(R.id.container, Camera2Fragment.newInstance()).commit();
        }
    }
}
