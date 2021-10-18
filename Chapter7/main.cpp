#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void filter_median();

int main()
{
	std::cout << "Hello OpenCV " << CV_VERSION << std::endl;

	filter_median();

	return 0;
}

void filter_median()
{
	Mat src = imread("../../images/zephy.jpg", IMREAD_GRAYSCALE);

	if (src.empty())
	{
		cerr << "Failed to load an image." << endl;
		return;
	}

	int num = (int)(src.total() * 0.1);
	for (int n = 0; n < num; n++)
	{
		int x = rand() % src.cols;
		int y = rand() % src.rows;
		src.at<uchar>(y, x) = (n % 2) * 255;
	}

	Mat dst1;
	GaussianBlur(src, dst1, Size(), 1);

	Mat dst2;
	medianBlur(src, dst2, 3);

	imshow("src", src);
	imshow("dst1", dst1);
	imshow("dst2", dst2);

	waitKey();
	destroyAllWindows();
}