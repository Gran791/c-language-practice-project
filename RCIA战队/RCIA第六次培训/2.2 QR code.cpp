#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
using namespace std;



int main()
{
	cv::Mat pic = cv::imread("QR code.png");
	 if (!pic.data)
	{
		cout << "Í¼Æ¬¶ÁÈ¡Ê§°Ü" << endl;
		return -1;
	}
	cv::namedWindow("image");

	cv::Mat pic2;
	pic2 = pic * 85;

	cv::resize(pic2, pic2, cv::Size(), 0.5, 0.5);

	cv::Mat struct1 = cv::getStructuringElement(0, cv::Size(5, 5));
	cv::erode(pic2, pic2, struct1);
	//cv::imshow("image", pic2);

	cv::Mat pic3;
	cv::threshold(pic2, pic3, 245, 255, 0);

	cv::imshow("image", pic3);
	cv::waitKey(0);
	return 0;
}