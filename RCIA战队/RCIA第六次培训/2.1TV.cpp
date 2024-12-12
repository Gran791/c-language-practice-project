#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <opencv2/opencv.hpp>
#include <time.h>

using namespace std;

int main()
{
	cv::Mat pic = cv::imread("TV.png");
	if (!pic.data)
	{
		cout << "ͼƬ��ʧ��" << endl;
		return -1;
	}
	cv::Mat content = cv::Mat::zeros(530 - 100, 725 - 85, CV_8UC3); //��������

	float width = (725 - 85) / 7.0;//���� ��
	float width1 = (725 - 85) / 6.0;//�׾��� ��
	float hight = (530 - 100) * 0.6;//������ ��
	float hight1 = (530 - 100) * 0.1;//�̾��� ��
	float hight2 = (530 - 100) * 0.2;//�׾��� ��
	//������
	cv::rectangle(content, cv::Point(0, 0), cv::Point(width, hight), cv::Scalar(230, 218, 230), -1);
	cv::rectangle(content, cv::Point(width, 0), cv::Point(width * 2, hight), cv::Scalar(14, 210, 240), -1);
	cv::rectangle(content, cv::Point(width * 2, 0), cv::Point(width * 3, hight), cv::Scalar(206, 245, 66), -1);
	cv::rectangle(content, cv::Point(width * 3, 0), cv::Point(width * 4, hight), cv::Scalar(8, 234, 16), -1);
	cv::rectangle(content, cv::Point(width * 4, 0), cv::Point(width * 5, hight), cv::Scalar(255, 0, 255), -1);
	cv::rectangle(content, cv::Point(width * 5, 0), cv::Point(width * 6, hight), cv::Scalar(198, 0, 12), -1);
	cv::rectangle(content, cv::Point(width * 6, 0), cv::Point(width * 7, hight), cv::Scalar(0, 0, 170), -1);
	//�̾���
	cv::rectangle(content, cv::Point(0, hight), cv::Point(width, hight + hight1), cv::Scalar(0, 0, 170), -1);
	cv::rectangle(content, cv::Point(width, hight), cv::Point(width * 2, hight + hight1), cv::Scalar(0, 0, 0), -1);
	cv::rectangle(content, cv::Point(width * 2, hight), cv::Point(width * 3, hight + hight1), cv::Scalar(255, 0, 255), -1);
	cv::rectangle(content, cv::Point(width * 3, hight), cv::Point(width * 4, hight + hight1), cv::Scalar(0, 0, 0), -1);
	cv::rectangle(content, cv::Point(width * 4, hight), cv::Point(width * 5, hight + hight1), cv::Scalar(206, 240, 66), -1);
	cv::rectangle(content, cv::Point(width * 5, hight), cv::Point(width * 6, hight + hight1), cv::Scalar(0, 0, 0), -1);
	cv::rectangle(content, cv::Point(width * 6, hight), cv::Point(width * 7, hight + hight1), cv::Scalar(230, 218, 230), -1);
	//�׾���
	cv::rectangle(content, cv::Point(width1, hight + hight1), cv::Point(width1 * 2, hight + hight1 + hight2), cv::Scalar(230, 218, 230), -1);
	cv::rectangle(content, cv::Point(width1 * 2, hight + hight1), cv::Point(width1 * 3, hight + hight1 + hight2), cv::Scalar(240, 0, 240), -1);
	//ʱ��
	cv::rectangle(content, cv::Point(width1 , 165), cv::Point(width1 * 5, 235), cv::Scalar(0, 0, 0), -1);
	//content -> pic
	cv::Rect rect(85, 100, 725 - 85, 530 - 100);
	content.copyTo(pic(rect));
	//����ʱ��
	struct tm* ptr;
	time_t lt;
	char str[80];
	
	while (1)
	{
		cv::Mat picm = pic.clone();

		lt = time(NULL);
		ptr = localtime(&lt);
		strftime(str, 100, "%H:%M:%S", ptr);

		cv::putText(picm, "No Signal", cv::Point(width1 * 2, 310), cv::FONT_HERSHEY_PLAIN, 2, cv::Scalar(255, 255, 255), 4, 8);
		cv::putText(picm, str, cv::Point(width1 * 2 + 240, 310), cv::FONT_HERSHEY_PLAIN, 2, cv::Scalar(255, 255, 255), 4, 8);

		cv::imshow("content", picm);
		cv::waitKey(500);
	}
	return 0;
}