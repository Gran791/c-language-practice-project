#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	string filename;
	cout << "输入文件名称：";
	getline(cin, filename);
	filename += ".png";
	Mat src = imread(filename); //读取图片
	Mat small_src;
	Mat grey_src;
	resize(src, small_src, Size(), 0.5, 0.5);//缩小一半尺寸
	cvtColor(src, grey_src, COLOR_BGR2GRAY);//转换为灰度图
	imshow("input", src); //显示窗口（名称）
	imshow("0.5 input", small_src); //显示一半尺寸窗口（名称）
	imshow("grey input", grey_src);
	waitKey(0); //等待关闭窗口
	destroyAllWindows(); //销毁所有窗口
	return 0;
}