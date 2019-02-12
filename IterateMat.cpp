#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(void)
{
	//創建Mat
	Mat image(300,400, CV_8UC3);
	int es = image.elemSize();
	int Size = image.rows*image.cols*es;
	
	//用data訪問image的元素
	for (int i = 0; i < Size; i+=es) {
		image.data[i] = 255; //B
		image.data[i + 1] = 0; //G
		image.data[i + 2] = 0; //R
	}

	imshow("image data", image);

	//使用ptr模板函數訪問image
	for (int row = 0; row < image.rows; row++) {
		for (int col = 0; col < image.cols; col++) {
			Vec3b *a = image.ptr<Vec3b>(row, col);
			a->val[0] = 0; //B
			a->val[1] = 255; //G
			a->val[2] = 0; //R
		}
	}
	imshow("image ptr", image);

	//使用at訪問image
	for (int row = 0; row < image.rows; row++) {
		for (int col = 0; col < image.cols; col++) {
			Vec3b &b = image.at<Vec3b>(row, col);
			b[0] = 0; //B
			b[1] = 0; //G
			b[2] = 255; //R

		}
	}
	imshow("image at", image);

	waitKey(0);
	return 0;

}
