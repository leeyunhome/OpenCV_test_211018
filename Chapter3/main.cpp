#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void ScalarOp()
{
	Scalar gray = 0;
	cout << "gray: " << gray << endl;

	Scalar yellow(0, 255, 255);
	cout << "yellow: " << yellow << endl;

	Mat img0(50, 50, CV_8UC1, gray);
	Mat img1(256, 256, CV_8UC3, yellow);

	for (int r = 0; r < 4; r++)
	{
		cout << yellow[r] << endl;
	}

	imshow("img1", img1);
	imshow("img0", img0);

	int ch = waitKey();

	destroyAllWindows();
}

void VectorOp();

int main()
{
	std::cout << "Hello OpenCV " << CV_VERSION << std::endl;

	//ScalarOp();
	VectorOp();

	return 0;
}

void VectorOp()
{
	Vec3b p1, p2(0, 0, 255);

	p1.val[0] = 100;
	p1[0] = 200;

	cout << p1 << ", " << p2 << endl;
}