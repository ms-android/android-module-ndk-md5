/**
 * 基于c语言的md5加密
 */

#include <jni.h>
#include <stdio.h>
#include <string.h>
#include "md5.h"

JNIEXPORT jstring JNICALL
Java_com_ms_module_ndk_md5_MD5_md5(JNIEnv *env, jobject thiz, jstring strText) {
    char *szText = (char *) (*env)->GetStringUTFChars(env, strText, 0);

    MD5_CTX context = {0};
    MD5Init(&context);
    MD5Update(&context, szText, strlen(szText));
    unsigned char dest[16] = {0};
    MD5Final(dest, &context);
    (*env)->ReleaseStringUTFChars(env, strText, szText);

    int i = 0;
    char szMd5[33] = {0};
    for (i = 0; i < 16; i++) {
        sprintf(szMd5, "%s%02x", szMd5, dest[i]);
    }

    return (*env)->NewStringUTF(env, szMd5);
}