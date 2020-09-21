package com.ms.module.ndk.md5;

public class MD5 {

    static {
        System.loadLibrary("md5-lib");
    }

    public native static String md5(String strText);

}
