#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void contours_basic();

int main()
{
	std::cout << "Hello OpenCV " << CV_VERSION << std::endl;

	contours_basic();

	return 0;
}

void contours_basic()
{
	Mat src = imread("../../images/nu.png", IMREAD_GRAYSCALE);

	if (src.empty())
	{
		cerr << "Failed to load an image" << endl;
		return;
	}

	vector<vector<Point>> contours;
	findContours(src, contours, RETR_LIST, CHAIN_APPROX_NONE);

	Mat dst;
	cvtColor(src, dst, COLOR_GRAY2BGR);

	for (int row = 0; row < contours.size(); row++)
	{
		Scalar c(rand() & 255, rand() & 255, rand() & 255);
		drawContours(dst, contours, row, c, 2);
	}
	
	imshow("src", src);
	imshow("dst", dst);

	waitKey(0);
	destroyAllWindows();
}