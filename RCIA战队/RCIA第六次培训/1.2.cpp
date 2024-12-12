#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
using namespace cv;
using namespace std;

int main()
{
	Mat image = imread("Ride the wind and waves.png");
	imshow("image", image);
	int c = 1;
	while (c)
	{
		int X, Y, W, H;
		string name;
		system("cls");
		cout << "������X��";
		cin >> X;
		cout << "������Y��";
		cin >> Y;
		cout << "������W��";
		cin >> W;
		cout << "������H��";
		cin >> H;
		cin.ignore();
		cout << "�����뱣���ļ�����";
		getline(cin, name);
		if (name == "back")
			break;
		else if (name == "quit")
		{
			c = 0;
			cout << "��ͼƬ���ڰ�������˳�" << endl;
		}
		else
		{
			name += ".png";
			Mat out;
			out = image(Rect(X, Y, W, H));
			imshow("out", out);
			imwrite(name, out);
			cout << "�ѱ���" << endl;
			system("pause");
		}
	}
	waitKey(0);
	return 0;
}