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
		cout << "请输入X：";
		cin >> X;
		cout << "请输入Y：";
		cin >> Y;
		cout << "请输入W：";
		cin >> W;
		cout << "请输入H：";
		cin >> H;
		cin.ignore();
		cout << "请输入保存文件名：";
		getline(cin, name);
		if (name == "back")
			break;
		else if (name == "quit")
		{
			c = 0;
			cout << "在图片窗口按任意键退出" << endl;
		}
		else
		{
			name += ".png";
			Mat out;
			out = image(Rect(X, Y, W, H));
			imshow("out", out);
			imwrite(name, out);
			cout << "已保存" << endl;
			system("pause");
		}
	}
	waitKey(0);
	return 0;
}