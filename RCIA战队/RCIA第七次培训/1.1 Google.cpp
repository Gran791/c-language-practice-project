#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

using namespace std;

int main()
{
	cv::Mat noisy_google = cv::imread("NoisyGoogle.png");
    if(noisy_google.empty())
    {
        cout << "无法打开图像" << endl;
        return -1;
    }
	cv::Mat google;
	cv::medianBlur(noisy_google, google, 9);
    //cv::imshow("Google", google);
	//cv::imshow("Noisy Google", noisy_google);
	vector<cv::Mat> channels;
    cv::split(google, channels);
	cv::Mat B, G, R;
    B = channels[0];
    G = channels[1];
    R = channels[2];
    
    cv::threshold(B, B, 150, 255, cv::THRESH_BINARY);
    cv::threshold(G, G, 150, 255, cv::THRESH_BINARY);
    cv::threshold(R, R, 150, 255, cv::THRESH_BINARY);
    //cv::imshow("Blue Channel", B);
    //cv::imshow("Green Channel", G);
    //cv::imshow("Red Channel", R);

    cv::Mat img_w = B & G & R;
    cv::Mat frame = B - img_w;
    //cv::imshow("Watermark", frame);

    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    cv::Mat img_open;
    cv::morphologyEx(frame, img_open, cv::MORPH_OPEN, kernel);
    cv::imshow("Opening", img_open);

    vector<vector<cv::Point>> contours;
    vector<cv::Vec4i> hierarchy;
    cv::findContours(img_open, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
    cv::drawContours(google, contours, -1, cv::Scalar(0, 0, 255), 5, cv::LINE_8, hierarchy, 2, cv::Point(0, 0));
    cv::imshow("Contours", google);
    cv::waitKey(0);
    return 0;
}