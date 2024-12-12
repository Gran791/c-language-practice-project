#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
using namespace cv;
using namespace std;

int main()
{
	string filename;
	cout << "�����������ļ�����";
	getline(cin, filename);
	Mat img = imread(filename);
	if (img.empty())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
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
	cout << "��������ֵ(0-255)��";
	int limit;
	cin >> limit;
	while(limit < 0 || limit > 255)
	{
		cout << "�����������������룺";
		cin >> limit;
	}
	threshold(grayimg, binaryimg, limit, 255, THRESH_BINARY);
	imshow("binary", binaryimg);
	waitKey(0);
	return 0;
}