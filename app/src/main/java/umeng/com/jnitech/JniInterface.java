package umeng.com.jnitech;

import android.util.Log;

/**
 * Created by wangfei on 2017/11/20.
 */

public class JniInterface {
    static {
        System.loadLibrary("JniTest");
    }
    public static native String sayHello();
    public static native int sum(int a,int b);
    public static native int sumCallBack(int a,int b);
    public static native String callJavaStringSum(String a,String b);
    public static native String testArray(String[] a,String[] b);
    public static native String callJavaString();
    public static native void test();
    public  native String callNonStaticJavaString();
    public static String hello(){
        return "这个字符串来自java静态，穿越c，展示在这里";
    }
    public  String helloNoStatic(){
        return "这个字符串来自java非静态，穿越c，展示在这里";
    }
    public static int sumCallBackJava(int a,int b){
        Log.e("xxxxxx","a+b="+a+b);
        return a+b;
    }
    public static String sumStringCallBackJava(String a,String b){

        return a+b;
    }
}
