package umeng.com.jnitech;

import android.os.Bundle;


import android.support.v7.app.AppCompatActivity;

import android.view.View;
import android.view.View.OnClickListener;

import android.widget.Toast;

public class MainActivity extends AppCompatActivity {



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        findViewById(R.id.callstring).setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View view) {
                Toast.makeText(MainActivity.this,JniInterface.sayHello(),Toast.LENGTH_SHORT).show();
            }
        });
        findViewById(R.id.callmethod).setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View view) {
                Toast.makeText(MainActivity.this,"3+4="+JniInterface.sum(3,4),Toast.LENGTH_SHORT).show();
            }
        });
        findViewById(R.id.callarray).setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View view) {
                String[] a = {"aaa","aaaaaa","aaaaaaaaa"};
               String[] b = { "bbb","bbbb","bbbbbb"};
                Toast.makeText(MainActivity.this,JniInterface.testArray(a,b),Toast.LENGTH_SHORT).show();
            }
        });
        findViewById(R.id.calljavastring).setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View view) {

                Toast.makeText(MainActivity.this,JniInterface.callJavaString(),Toast.LENGTH_SHORT).show();
            }
        });
        findViewById(R.id.calljavanostaticstring).setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View view) {

                Toast.makeText(MainActivity.this,new JniInterface().callNonStaticJavaString(),Toast.LENGTH_SHORT).show();
            }
        });
        findViewById(R.id.calljavamethod).setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View view) {

                Toast.makeText(MainActivity.this,"5+7="+JniInterface.sumCallBack(5,7),Toast.LENGTH_SHORT).show();
            }
        });
        findViewById(R.id.calljavastringsum).setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View view) {

                Toast.makeText(MainActivity.this,"a+b="+JniInterface.callJavaStringSum("a","b"),Toast.LENGTH_SHORT).show();
            }
        });

    }

}
