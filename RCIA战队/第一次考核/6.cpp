#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	string filename;
	cout << "�����ļ����ƣ�";
	getline(cin, filename);
	filename += ".png";
	Mat src = imread(filename); //��ȡͼƬ
	Mat small_src;
	Mat grey_src;
	resize(src, small_src, Size(), 0.5, 0.5);//��Сһ��ߴ�
	cvtColor(src, grey_src, COLOR_BGR2GRAY);//ת��Ϊ�Ҷ�ͼ
	imshow("input", src); //��ʾ���ڣ����ƣ�
	imshow("0.5 input", small_src); //��ʾһ��ߴ細�ڣ����ƣ�
	imshow("grey input", grey_src);
	waitKey(0); //�ȴ��رմ���
	destroyAllWindows(); //�������д���
	return 0;
}