#include <opencv2/opencv.hpp>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#include <string>
#include <conio.h>

using namespace cv;
using namespace std;

vector<vector<int>> map_game;
int in = 0;

/*
ʹ��˵����
1.��������ص�����ͼƬ����cpp�ļ������ļ����ڣ���8��ͼƬ��
2.ֻ��Ҫ�����ͼ��ţ����������ͼͼƬ��ǰ׺��Map���ͺ�׺��.png��

һЩ���⣺
1.����֮��һЩ��������ͨ���������ݣ���Ȼ���ò��ˣ�
2.opencvʶ��ͼ��Ĵ����ظ��ʸߣ���ѧϰ����
3.��Ϊ�󲿷ִ��붼�������磬��˿���������Һ��ӣ������
4.��ͼ��ÿһ�����Ӵ�С������200*200�������ʶ�����
*/

//void display(int px, int py, int map_length, int goldx, int goldy, vector<vector<int>> map_game)
//{
//	for (int y = 0; y < map_length; y++)
//	{
//		for (int x = 0; x < map_length; x++)
//		{
//			if (x == px && y == py)
//				cout << "\033[0;42;30m Me \033[0m\t";
//			else if (x == goldx && y == goldy)
//				cout << "\033[0;43;30mGold\033[0m\t";
//			else if (map_game[y][x] == 1)
//				cout << "\033[0;45;30mRoad\033[0m\t";
//			else if (map_game[y][x] == 2)
//				cout << "\033[0;41;30mWall\033[0m\t";
//			else if (map_game[y][x] == 3)
//				cout << "\033[0;44;30mJump\033[0m\t";
//		}
//		cout << endl << endl;
//	}
//}

Mat display(Mat src, Mat road, Mat me, int px, int py, int map_length, int opx, int opy)
{
	Mat out = src.clone();
	int original_x = opx, original_y = opy;
	road.copyTo(out(Rect(original_x * 200, original_y * 200, 200, 200)));//ԭ��ͼMe�滻ΪRoad
	me.copyTo(out(Rect(px * 200, py * 200, 200, 200)));//Me�����긲��
	return out;
}

int isMovable(int x, int y, vector<vector<int>> map_game, int map_length)
{
	if (x >= 0 && y >= 0 && x < map_length && y < map_length)
	{
		int s = map_game[y][x];
		if (s == 1 || s == 3)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

int isJumpable(int x, int y, char decide, vector<vector<int>> map_game, int map_length)
{
	if (map_game[y][x] == 3)
	{
		switch (decide)
		{
		case 'w':
			if (isMovable(x, y - 2, map_game, map_length))
				return 1;
			break;
		case 's':
			if (isMovable(x, y + 2, map_game, map_length))
				return 1;
			break;
		case 'a':
			if (isMovable(x - 2, y, map_game, map_length))
				return 1;
			break;
		case 'd':
			if (isMovable(x + 2, y, map_game, map_length))
				return 1;
			break;
		default:
			break;
		}
	}
	return 0;
}

int main()
{
	int px = 0, py = 0;
	int goldx, goldy;
	string filename;
	filename += "Map ";
	in++;
	filename += to_string(in);
	filename += ".png";

	Mat src = imread(filename); //��ȡͼƬ
	Mat org = src.clone();
	if (src.empty())
	{
		cout << "ͼƬ��ȡʧ��" << endl;
		return -1;
	}
	else
		cout << "ͼƬ��ȡ�ɹ�" << endl;

	Mat gold = imread("Gold.png");
	Mat Me = imread("Me.png");
	Mat jump = imread("Jump.png");
	Mat wall = imread("Wall.png");
	Mat road = imread("Road.png");
	resize(gold, gold, Size(200, 200));
	resize(Me, Me, Size(200, 200));
	resize(jump, jump, Size(200, 200));
	resize(wall, wall, Size(200, 200));
	resize(road, road, Size(200, 200));
	// ת��Ϊ�Ҷ�ͼ��
	Mat grayImage;
	cvtColor(src, grayImage, COLOR_BGR2GRAY);
	//imshow("�Ҷ�ͼ", grayImage);
	waitKey(0);

	// ʹ���˲���ȥ��
	Mat blurImage = grayImage;
	// GaussianBlur(grayImage, blurImage, Size(9, 9), 2, 2); // ��˹�˲�
	// medianBlur(grayImage, blurImage, 7); // ��ֵ�˲�
	blur(grayImage, blurImage, Size(2, 4)); // ��ֵ�˲�
	//imshow("ģ���˲�", blurImage);
	waitKey(0);

	// ʹ�� Canny ��Ե���
	Mat edgesImage;
	Canny(blurImage, edgesImage, 40, 80);
	//imshow("��Ե���", edgesImage);

	vector<Vec3f> circles;
	int minDist = 150;   // ��С����
	int param1 = 80;     // Canny��Ե������ֵ  # ���ֺͺ�ǰ��Canny����ֵһ��
	int param2 = 15;     // Hough�任����ֵ
	int minRadius = 50;   // ��С�뾶
	int maxRadius = 80;   // ���뾶
	HoughCircles(blurImage, circles, HOUGH_GRADIENT, 1, minDist, param1, param2, minRadius, maxRadius);

	int map_length = sqrt(circles.size());

	//int (*map)[5] = new int[5][5];
	vector<vector<int>> map_game(map_length, vector<int>(map_length));
	Mat outimage;
	int opx, opy;

	for (size_t i = 0; i < circles.size(); i++)
	{
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		circle(src, center, 3, Scalar(0, 0, 0), -1, 8, 0); // ����Բ��
		circle(src, center, radius, Scalar(100, 100, 100), 3, 8, 0); //���ƿ���Բ

		//��ȡ������
		Rect rect(circles[i][0] - 100, circles[i][1] - 100, 200, 200);
		Mat roi = src(rect);

		//imshow("roi", roi);

		Mat diff_gold, diff_Me, diff_jump, diff_wall, diff_road;
		absdiff(gold, roi, diff_gold);
		absdiff(Me, roi, diff_Me);
		absdiff(jump, roi, diff_jump);
		absdiff(wall, roi, diff_wall);
		absdiff(road, roi, diff_road);
		double mse_gold = mean(diff_gold)[0];
		double mse_Me = mean(diff_Me)[0];
		double mse_jump = mean(diff_jump)[0];
		double mse_wall = mean(diff_wall)[0];
		double mse_road = mean(diff_road)[0];

		double mse[5] = { mse_gold, mse_Me, mse_jump, mse_wall, mse_road };
		double similarity = *min_element(mse, mse + 5);

		int c_x, c_y;//Ϊʲôvs���������ֵ��(�ð�releaseģʽ����Щ�Ƕ��������ģ�

		c_x = (((center.x + 100) / 200) - 1);
		c_y = (((center.y + 100) / 200) - 1);

		if (similarity == mse_gold)
		{
			goldx = c_x;
			goldy = c_y;
			map_game[c_y][c_x] = 1;
		}
		else if (similarity == mse_Me)
		{
			px = c_x;
			py = c_y;
			opx = c_x;
			opy = c_y;
			map_game[c_y][c_x] = 1;
		}
		else if (similarity == mse_jump)
			map_game[c_y][c_x] = 3;
		else if (similarity == mse_wall)
			map_game[c_y][c_x] = 2;
		if (similarity == mse_road)
			map_game[c_y][c_x] = 1;

	}

	//������
	for (int i = 0; i < map_length; i++)
	{
		for (int j = 0; j < map_length; j++)
		{
			cout << map_game[i][j] << " ";
		}
		cout << endl;
	}
	cout << "��ͼʶ�����" << endl;
	system("pause");
	while (px != goldx || py != goldy)
	{
		system("cls");
		//display(px, py, map_length, goldx, goldy, map_game);
		outimage = display(org, road, Me, px, py, map_length, opx, opy);
		cout << "Move(w,s,a,d): ";
		namedWindow("input", WINDOW_NORMAL);
		imshow("input", outimage); //��ʾ����
		char move = cv::waitKey(0); //�ȴ�����

		//����̨���벿�֣��ѷ���
		//char move;
		//move = _getch();
		//cin >> move;

		switch (move)
		{
		case 'w':
		{
			if (isMovable(px, py - 1, map_game, map_length))
				py--;
			if (isJumpable(px, py, 'w', map_game, map_length))
				py -= 2;
			break;
		}
		case 's':
		{
			if (isMovable(px, py + 1, map_game, map_length))
				py++;
			if (isJumpable(px, py, 's', map_game, map_length))
				py += 2;
			break;
		}
		case 'a':
			if (isMovable(px - 1, py, map_game, map_length))
				px--;
			if (isJumpable(px, py, 'a', map_game, map_length))
				px -= 2;
			break;
		case 'd':
		{
			if (isMovable(px + 1, py, map_game, map_length))
				px++;
			if (isJumpable(px, py, 'd', map_game, map_length))
				px += 2;
			break;
		}
		default:
			break;
		}
	}
	system("cls");
	//display(px, py, map_length, goldx, goldy, map_game);
	outimage = display(org, road, Me, px, py, map_length, opx, opy);
	cout << "You Win!!!" << endl;
	imshow("input", outimage);
	waitKey(0);

	//������
	//namedWindow("input", WINDOW_NORMAL);
	//imshow("input", src); //��ʾ����
	//waitKey(0); //�ȴ��رմ���
	destroyAllWindows(); //�������д���

	if (in < 3)
	{
		cout << "׼��������һ��..." << endl;
		system("pause");
		system("cls");
		main();
	}
	cout << "����������йؿ���" << endl;
	return 0;
}