package com.lab1.helloworld;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        String text = "Hello World!";
        TextView txtResult = (TextView) findViewById(R.id.txtResult);
        txtResult.setText(String.valueOf(text));

        String text2 = "Hello Java's World!";
        TextView txtResult2 = (TextView) findViewById(R.id.txtResult2);
        txtResult2.setText(String.valueOf(text2));

        String text3 = "Hello Hanwen's World!";
        TextView txtResult3 = (TextView) findViewById(R.id.txtResult3);
        txtResult3.setText(String.valueOf(text3));
    }
}
