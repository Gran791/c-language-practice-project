#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
using namespace std;

int main()
{
	cv::Mat pic = cv::imread("Various.png");
    if (pic.empty())
    {
        cout << "ÎÞ·¨¼ÓÔØÍ¼Æ¬" << endl;
        return -1;
    }

    // Threshold
    cv::Mat pic_b = pic.clone();
    cv::cvtColor(pic, pic_b, cv::COLOR_BGR2GRAY);
    cv::threshold(pic_b, pic_b, 10, 255, cv::THRESH_BINARY);
    
    // HSV
    cv::Mat hsv;
    cv::cvtColor(pic, hsv, cv::COLOR_BGR2HSV);//to hsv

    //cv::imshow("Original", pic);
    //cv::imshow("Thresholded", pic);

    cv::Mat core = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));

    // Blue
    cv::Mat mask_blue;
    cv::Scalar light_blue_lower(88, 86, 46);
    cv::Scalar light_blue_upper(99, 255, 255);
    cv::inRange(hsv, light_blue_lower, light_blue_upper, mask_blue);
    cv::morphologyEx(mask_blue, mask_blue, cv::MORPH_OPEN, core);
    //cv::imshow("Blue Mask", mask_blue);
    {
        vector<vector<cv::Point>> contours;
        vector<cv::Vec4i> hierarchy;
        cv::findContours(mask_blue, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
        cv::drawContours(pic, contours, -1, cv::Scalar(0, 0, 255), 5, cv::LINE_8, hierarchy, 2, cv::Point(0, 0));
    }

    // Yellow
    cv::Mat mask_yellow;
    cv::Scalar yellow_lower(26, 43, 45);
    cv::Scalar yellow_upper(34, 255, 255);
    cv::inRange(hsv, yellow_lower, yellow_upper, mask_yellow);
    cv::morphologyEx(mask_yellow, mask_yellow, cv::MORPH_OPEN, core);
    //cv::imshow("Yellow Mask", mask_yellow);
    {
        vector<vector<cv::Point>> contours;
        vector<cv::Vec4i> hierarchy;
        cv::findContours(mask_yellow, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
        cv::drawContours(pic, contours, -1, cv::Scalar(255, 0, 0), 5, cv::LINE_8, hierarchy, 2, cv::Point(0, 0));
    }

    // Purple
    cv::Mat mask_purple;
    cv::Scalar purple_lower(125, 43, 46);
    cv::Scalar purple_upper(155, 255, 255);
    cv::inRange(hsv, purple_lower, purple_upper, mask_purple);
    cv::morphologyEx(mask_purple, mask_purple, cv::MORPH_OPEN, core);
    //cv::imshow("Purple Mask", mask_purple);
    {
        vector<vector<cv::Point>> contours;
        vector<cv::Vec4i> hierarchy;
        cv::findContours(mask_purple, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
        cv::drawContours(pic, contours, -1, cv::Scalar(0, 255, 0), 5, cv::LINE_8, hierarchy, 2, cv::Point(0, 0));
    }

    cv::resize(pic, pic, cv::Size(), 0.5, 0.5);
    cv::imshow("Contours", pic);
    cv::waitKey(0);
    return 0;
}