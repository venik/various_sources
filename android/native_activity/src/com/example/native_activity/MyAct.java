package com.MyAct;

import android.hardware.Camera;
import android.util.Log;

class MyActClass implements Camera.PreviewCallback {

	static final String TAG = "AndroidL9HardwareCamera";

	MyActClass() {
		Log.d(TAG, "==========> inside constructor");
	}
	
	void simpleLog() {
		Log.d(TAG, "==========> call method");
	}

	static public void dumpCameraInfo() {
		Log.d(TAG, "MANUFACTURER" + android.os.Build.MANUFACTURER + 
				"BOARD" + android.os.Build.BOARD +
				"MODEL"	+ android.os.Build.MODEL +
				"PRODUCT" + android.os.Build.PRODUCT +
				"DEVICE" + android.os.Build.DEVICE);

		int n = Camera.getNumberOfCameras();
		for (int i = 0; i < n; ++i) {
			Camera.CameraInfo info = new Camera.CameraInfo();
			Camera.getCameraInfo(i, info);
			try
			{
				Camera camera = Camera.open(i);
				Camera.Parameters params = camera.getParameters();
				Log.d(TAG,String.format("dumpCameraParams: cid %d facing %d, orientation: %d, PARAMS %s",i, info.facing, info.orientation, params.flatten()));				
				camera.release();
			} catch (Exception e)
			{
				Log.e(TAG, "dumpCameraParams error -- " + e.toString());
			}
		}
	}

	@Override
	public void onPreviewFrame(byte[] data, Camera camera) {
	}

}
