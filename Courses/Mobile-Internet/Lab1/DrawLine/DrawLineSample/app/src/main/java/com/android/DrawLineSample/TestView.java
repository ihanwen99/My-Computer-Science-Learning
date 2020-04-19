package com.android.DrawLineSample;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.view.MotionEvent;
import android.view.View;

class TestView extends View {

    public Canvas canvas;
    public Paint p;
    private Bitmap bitmap;
    float x, y;
    int bgColor;
    int time;

    public TestView(Context context) {
        super(context);
        bgColor = Color.WHITE;               //设置背景颜色
        bitmap = Bitmap.createBitmap(1080, 1920, Bitmap.Config.ARGB_8888);    //设置位图，线就画在位图上面，第一二个参数是位图宽和高
        canvas = new Canvas();
        canvas.setBitmap(bitmap);
        p = new Paint(Paint.DITHER_FLAG);
        p.setAntiAlias(true);                //设置抗锯齿，一般设为true
        p.setColor(Color.RED);              //设置线的颜色
        p.setStrokeCap(Paint.Cap.ROUND);     //设置线的类型
        p.setStrokeWidth(8);                //设置线的宽度
        time = 0;
    }


    //触摸事件
    @Override
    public boolean onTouchEvent(MotionEvent event) {
        if (event.getAction() == MotionEvent.ACTION_MOVE) {    //拖动屏幕
            canvas.drawLine(x, y, event.getX(), event.getY(), p);   //画线，x，y是上次的坐标，event.getX(), event.getY()是当前坐标
            invalidate();
        }

        if (event.getAction() == MotionEvent.ACTION_DOWN) {    //按下屏幕
            x = event.getX();
            y = event.getY();
            canvas.drawPoint(x, y, p);                //画点
            invalidate();
        }
        if (event.getAction() == MotionEvent.ACTION_UP) {    //松开屏幕
            switch (time) {
                case 0:
                    p.setColor(Color.GREEN);
                    break;
                case 1:
                    p.setColor(Color.BLUE);
                    break;
                case 2:
                    p.setColor(Color.RED);
                    break;
            }
            time = (time + 1) % 3;
            invalidate();
        }

        x = event.getX();   //记录坐标
        y = event.getY();
        return true;
    }

    @Override
    public void onDraw(Canvas c) {
        c.drawBitmap(bitmap, 0, 0, null);
    }
}
