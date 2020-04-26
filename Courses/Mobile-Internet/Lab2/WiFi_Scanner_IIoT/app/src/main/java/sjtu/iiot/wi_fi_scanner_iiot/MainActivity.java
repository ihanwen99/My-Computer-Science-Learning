package sjtu.iiot.wi_fi_scanner_iiot;

import android.Manifest;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.support.v4.app.ActivityCompat;
import android.view.View;

import java.util.Vector;

import android.app.Activity;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends Activity {
    private SuperWiFi rss_scan = null;
    Vector<String> RSSList = null;
    private String testlist = null;
    public static int testID = 0;//The ID of the test result

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        final EditText ipText = (EditText) findViewById(R.id.ipText);//The textlist of the average of the result
        final Button changactivity = (Button) findViewById(R.id.button1);//The start button
        final Button cleanlist = (Button) findViewById(R.id.button2);//Clear the textlist
        verifyStoragePermissions(this);
        rss_scan = new SuperWiFi(this);
        testlist = "";
        testID = 0;
        changactivity.setOnClickListener(new Button.OnClickListener() {
            public void onClick(View v) {
                testID = testID + 1;
                rss_scan.ScanRss();
                while (rss_scan.isscan()) {//Wait for the end
                }
                RSSList = rss_scan.getRSSlist();//Get the test result
                final EditText ipText = (EditText) findViewById(R.id.ipText);
                //testlist = "?5G?"+String.valueOf(rss_scan.support5G)+"\n"+testlist + "testID:" + testID + "\n" + RSSList.toString() + "\n";
                testlist = testlist + "testID:" + testID + "\n" + RSSList.toString() + "\n";
                ipText.setText(testlist);//Display the result in the textlist
            }
        });
        cleanlist.setOnClickListener(new Button.OnClickListener() {
            public void onClick(View v) {
                testlist = "";
                ipText.setText(testlist);//Clear the textlist
                testID = 0;
            }
        });
    }

    // Storage Permissions
    private static final int REQUEST_EXTERNAL_STORAGE = 1;
    private static String[] PERMISSIONS_STORAGE = {
            Manifest.permission.READ_EXTERNAL_STORAGE,
            Manifest.permission.WRITE_EXTERNAL_STORAGE,
            Manifest.permission.ACCESS_NETWORK_STATE,
            Manifest.permission.CHANGE_WIFI_STATE,
            Manifest.permission.ACCESS_WIFI_STATE,
            Manifest.permission.CHANGE_WIFI_MULTICAST_STATE,
            Manifest.permission.INTERNET,
            Manifest.permission.ACCESS_FINE_LOCATION};

    /**
     * Checks if the app has permission to write to device storage
     * If the app does not has permission then the user will be prompted to
     * grant permissions
     *
     * @param activity
     */
    public static void verifyStoragePermissions(Activity activity) {
// Check if we have write permission
        int permission = ActivityCompat.checkSelfPermission(activity,
                Manifest.permission.WRITE_EXTERNAL_STORAGE);

        if (permission != PackageManager.PERMISSION_GRANTED) {
// We don't have permission so prompt the user
            ActivityCompat.requestPermissions(activity, PERMISSIONS_STORAGE,
                    REQUEST_EXTERNAL_STORAGE);
        }
    }
}