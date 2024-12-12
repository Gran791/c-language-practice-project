#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
using namespace cv;
using namespace std;

int main()
{
	string filename;
	cout << "请输入完整文件名：";
	getline(cin, filename);
	Mat img = imread(filename);
	if (img.empty())
	{
		cout << "文件打开失败！" << endl;
		return -1;
	}
	imshow("file", img);
	waitKey(0);
	Mat resiezedimg;
	resize(img, resiezedimg, Size(), 0.5, 0.5);
	imshow("resized", resiezedimg);
	waitKey(0);
	Mat grayimg;
	cvtColor(resiezedimg, grayimg, COLOR_BGR2GRAY);
	imshow("gray", grayimg);
	waitKey(0);
	Mat binaryimg;
	cout << "请输入阈值(0-255)：";
	int limit;
	cin >> limit;
	while(limit < 0 || limit > 255)
	{
		cout << "输入有误，请重新输入：";
		cin >> limit;
	}
	threshold(grayimg, binaryimg, limit, 255, THRESH_BINARY);
	imshow("binary", binaryimg);
	waitKey(0);
	return 0;
}