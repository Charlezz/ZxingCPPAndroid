package com.maxst.www.zxingcpptest;

/**
 * Created by Charles on 11/1/16.
 */
public class NativeManager {

    private static NativeManager ourInstance = new NativeManager();

    public static NativeManager getInstance() {
        return ourInstance;
    }

    private NativeManager() {

    }


    public native String tryToRecognize(int width, int height, byte[] buffer);

}
