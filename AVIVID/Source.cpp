#include "opencv\cv.h"
#include "opencv\highgui.h"

int g_slider_position = 0;
CvCapture* g_capture = NULL;
void onTrackbarSlide(int pos);

int main(int argc, char** argv) {
	/*
	//Open an image file
	IplImage* img = cvLoadImage("Robot_Blue.jpg");
	cvNamedWindow("ex", CV_WINDOW_AUTOSIZE);
	cvShowImage("ex", img);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvDestroyWindow("ex");

	//Open a AVI video file
	cvNamedWindow("hello", CV_WINDOW_AUTOSIZE);
	CvCapture* capture = cvCreateFileCapture("mic test2.avi");
	IplImage* frame;
	while (1) {
		frame = cvQueryFrame(capture);
		if (!frame) break;
		cvShowImage("hello", frame);
		char c = cvWaitKey(33); //Update the current frame with the next frame in the file
		if (c == 27) break; //Break when ESC key is pressed
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("hello");
	*/
	//Move through a video frame by frame
	
	
		cvNamedWindow("hello", CV_WINDOW_AUTOSIZE);
		g_capture = cvCreateFileCapture("mic test2.avi");
		int frames = (int)cvGetCaptureProperty(
			g_capture,
			CV_CAP_PROP_FRAME_COUNT
		);
		if (frames != 0) {
			cvCreateTrackbar(
				"Position",
				"hello",
				&g_slider_position,
				frames,
				onTrackbarSlide
			);
		}
		IplImage* frame;
		// While loop (as in Example 2) capture & show video
	
		while (1) {
			frame = cvQueryFrame(g_capture);
			if (!frame) break;
			cvShowImage("hello", frame);
			char c = cvWaitKey(33); //Update the current frame with the next frame in the file
			if (c == 27) break; //Break when ESC key is pressed
		}
		cvReleaseCapture(&g_capture);
		cvDestroyWindow("hello");
			
			return(0);
}


void onTrackbarSlide(int pos) {
	cvSetCaptureProperty(
		g_capture,
		CV_CAP_PROP_POS_FRAMES,
		pos
	);
}