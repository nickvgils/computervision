#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
		Mat image;

		VideoCapture cap;
		cap.open(0);

		namedWindow("window", 1);
	
		while(true)
		{
			cap >> image;

			cvtColor(image, image, CV_BGR2GRAY);

			threshold(image, image, 50, 1, CV_THRESH_BINARY);

			imshow("window", 255*image);

			waitKey(33);
		}

	return 0;
}
