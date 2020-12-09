#include "pch.h"

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void detectAndDraw(Mat& img, CascadeClassifier& cascade, double scale)
{	
	std::vector<Rect> people;
	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);

	cascade.detectMultiScale(gray, people, 1.1, 1, 0 | CASCADE_SCALE_IMAGE, Size(100, 100));

	for (const auto rect : people)
	{
		Scalar color = Scalar(255, 0, 0);
		rectangle(img, Point(cvRound(rect.x * scale), cvRound(rect.y * scale)), Point(cvRound((rect.x +
			rect.width - 1) * scale), cvRound((rect.y + rect.height - 1) * scale)), color, 3, 8, 0);
	}

	imshow("People Detection", img);
}

TEST(TestCaseName, TestName)
{
	CascadeClassifier full_body_cascade;
	
	ASSERT_TRUE(full_body_cascade.load("haarcascade_fullbody.xml"));
	
	Mat image = imread("test_image.jpg");
	Mat image2 = imread("test_image2.jpg");

	const String window_name = "People Detection"; //Name of the window

	namedWindow(window_name); // Create a window

	detectAndDraw(image2, full_body_cascade, 1);

	waitKey(0); // Wait for any keystroke in the window

	detectAndDraw(image, full_body_cascade, 1);
	
	waitKey(0); // Wait for any keystroke in the window
	destroyWindow(window_name); //destroy the created window
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}