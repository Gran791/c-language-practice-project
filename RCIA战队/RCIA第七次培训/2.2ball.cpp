#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
using namespace std;

int main()
{
	cv::VideoCapture cap("CyanBall.mp4");
    if (!cap.isOpened())
    {
        cout << "无法加载视频" << endl;
        return -1;
    }

    cv::namedWindow("Video", cv::WINDOW_AUTOSIZE);
    cv::Mat frame;
    cv::Mat processed;
    cout << "Ready" << endl;

    for (; ; )
    {
        cap >> frame;
        if (frame.empty())
            break;

        //二值化
        cv::cvtColor(frame, processed, cv::COLOR_BGR2GRAY);
        cv::threshold(processed, processed, 10, 255, cv::THRESH_BINARY);

        //开运算
        cv::Mat core = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
        cv::morphologyEx(processed, processed, cv::MORPH_OPEN, core);

        vector<vector<cv::Point>> contours;
        vector<cv::Vec4i> hierarchy;
        vector<cv::Vec3f> circles;

        //轮廓绘制
        cv::findContours(processed, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
        cv::drawContours(frame, contours, -1, cv::Scalar(0, 0, 255), 2, cv::LINE_8, hierarchy, 2, cv::Point(0, 0));

        //霍夫圆检测
        cv::blur(processed, processed, cv::Size(5, 5));
        cv::HoughCircles(processed, circles, cv::HOUGH_GRADIENT, 1, 50, 100, 15, 10, 50);

        //画出圆心
        int x = 0, y = 0;
        for (size_t i = 0; i < circles.size(); i++)
        {
            cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
            x = center.x;
            y = center.y;
            //调试用//x:x坐标，y:y坐标，r:圆半径，f:帧数，c:检测到圆的数量
            cout << "x:" << x << "\ty:" << y << "\tr:" << cvRound(circles[i][2]) << "\tf:" << cap.get(cv::CAP_PROP_POS_FRAMES) << "\tc:" << circles.size() << endl;
            cv::line(frame, cv::Point(x - 10, y), cv::Point(x + 10, y), cv::Scalar(0, 255, 255), 2, 8, 0);
            cv::line(frame, cv::Point(x, y - 10), cv::Point(x, y + 10), cv::Scalar(0, 255, 255), 2, 8, 0);
        }

        //显示坐标
        string str_x = "x:" + to_string(x);
        string str_y = "y:" + to_string(y);
        cv::putText(frame, str_x, cv::Point(10, 430), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 255), 1);
        cv::putText(frame, str_y, cv::Point(10, 460), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 255), 1);

        cv::imshow("Video", frame);
        if (cv::waitKey(30) >= 0)
            break;
    }
    
    cap.release();

    return 0;
}