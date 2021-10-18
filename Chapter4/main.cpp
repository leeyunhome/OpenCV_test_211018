#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void sunAndMeanOfImage();
void minMaxLocOp();

int main()
{
	std::cout << "Hello OpenCV " << CV_VERSION << std::endl;

	sunAndMeanOfImage();
	minMaxLocOp();

	return 0;
}

void sunAndMeanOfImage()
{
	Mat img = imread("../../images/rx78.png", IMREAD_GRAYSCALE);
	Point pt1(243, 156);

	cv::circle(img, pt1, 10, Scalar(255, 0, 0), -1);
	cout << "Sum: " << (int)sum(img)[0] << endl;
	cout << "Mean: " << (int)mean(img)[0] << endl;

	imshow("img", img);

	int ch = waitKey();

	destroyAllWindows();
}

void minMaxLocOp()
{
	Mat img = imread("../../images/rx78.png", IMREAD_GRAYSCALE);

	double minVal, maxVal;
	Point minPos, maxPos;
	minMaxLoc(img, &minVal, &maxVal, &minPos, &maxPos);

	cout << "minVal: " << minVal << " at " << minPos << endl;
	cout << "maxVal: " << maxVal << " at " << maxPos << endl;
}