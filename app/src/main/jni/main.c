#include <jni.h>
/* Header for class umeng_com_jnitech_JniInterface */
#include <stddef.h>
#ifndef _Included_umeng_com_jnitech_JniInterface
#define _Included_umeng_com_jnitech_JniInterface
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     umeng_com_jnitech_JniInterface
 * Method:    sayHello
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_umeng_com_jnitech_JniInterface_sayHello
        (JNIEnv *env, jclass object){
    return (*env)->NewStringUTF(env,"hello umeng");
}
JNIEXPORT void JNICALL Java_umeng_com_jnitech_JniInterface_test
        (JNIEnv *env, jclass object){
    jint a;
    jint i ;
    for ( i = 0;i<100000;i++){
       a = i*i;
    }
}
JNIEXPORT jint JNICALL Java_umeng_com_jnitech_JniInterface_sum
        (JNIEnv *env, jclass object, jint a, jint b){
    return (a+b);
}
JNIEXPORT jint JNICALL Java_umeng_com_jnitech_JniInterface_sumCallBack
        (JNIEnv *env, jclass object, jint a, jint b){
    jclass dpclazz = (*env)->FindClass(env,"umeng/com/jnitech/JniInterface");
    if(dpclazz==0){
        return 0;
    }
    jmethodID method1 = (*env)->GetStaticMethodID(env,dpclazz,"sumCallBackJava","(II)I");
    if(method1==0){
        return 0;
    }
    jint result =  (*env)->CallStaticIntMethod(env,object,method1,a,b);
//    return (*env)->NewStringUTF(env,"hello umeng");
    return result;
}

JNIEXPORT jstring JNICALL Java_umeng_com_jnitech_JniInterface_testArray
        (JNIEnv *env, jclass object, jobjectArray a, jobjectArray b){
    jsize count1 = (*env)->GetArrayLength(env,a);
    jsize count2 = (*env)->GetArrayLength(env,b);
    jstring aa = (jstring) (*env)->GetObjectArrayElement(env,a, count1-1);
    jstring bb = (jstring) (*env)->GetObjectArrayElement(env,b, count2-1);


    return (*env)->NewStringUTF(env,"数组收到");
}
JNIEXPORT jstring JNICALL Java_umeng_com_jnitech_JniInterface_callJavaString
        (JNIEnv *env, jclass object){
    jclass dpclazz = (*env)->FindClass(env,"umeng/com/jnitech/JniInterface");
    if(dpclazz==0){
        return;
    }
    jmethodID method1 = (*env)->GetStaticMethodID(env,dpclazz,"hello","()Ljava/lang/String;");
    if(method1==0){
        return;
    }
    jstring result =  (jstring)(*env)->CallStaticObjectMethod(env,object,method1);
//    return (*env)->NewStringUTF(env,"hello umeng");
    return result;

}
JNIEXPORT jstring JNICALL Java_umeng_com_jnitech_JniInterface_callJavaStringSum
        (JNIEnv *env, jclass object,jstring a,jstring b){
    jclass dpclazz = (*env)->FindClass(env,"umeng/com/jnitech/JniInterface");
    if(dpclazz==0){
        return;
    }
    jmethodID method1 = (*env)->GetStaticMethodID(env,dpclazz,"sumStringCallBackJava","(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
    if(method1==0){
        return;
    }
    jstring result =  (jstring)(*env)->CallStaticObjectMethod(env,object,method1,a,b);
//    return (*env)->NewStringUTF(env,"hello umeng");
    return result;

}
JNIEXPORT jstring JNICALL Java_umeng_com_jnitech_JniInterface_callNonStaticJavaString
        (JNIEnv *env, jclass object){
    jclass dpclazz = (*env)->FindClass(env,"umeng/com/jnitech/JniInterface");
    if(dpclazz==0){
        return;
    }
    jmethodID method1 = (*env)->GetMethodID(env,dpclazz,"helloNoStatic","()Ljava/lang/String;");
    if(method1==0){
        return;
    }
    jstring result =  (jstring)(*env)->CallObjectMethod(env,object,method1);
//    return (*env)->NewStringUTF(env,"hello umeng");
    return result;

}
#ifdef __cplusplus
}

#endif
#endif