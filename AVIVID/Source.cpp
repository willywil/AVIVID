#include "opencv\highgui.h"

int main(int argc, char** argv) {
	IplImage* img = cvLoadImage("Robot_Blue.jpg");
	cvNamedWindow("ex", CV_WINDOW_AUTOSIZE);
	cvShowImage("ex", img);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvDestroyWindow("ex");

	
	
	cvNamedWindow("hello", CV_WINDOW_AUTOSIZE);
	CvCapture* capture = cvCreateFileCapture("mic test2.avi");
	IplImage* frame;
	while (1) {
		frame = cvQueryFrame(capture);
		if (!frame) break;
		cvShowImage("hello", frame);
		char c = cvWaitKey(33); //Update the current frame with the next frame in the file
		if (c == 27) break;
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("hello");
	
}