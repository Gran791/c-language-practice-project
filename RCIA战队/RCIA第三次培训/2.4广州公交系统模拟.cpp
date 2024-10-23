#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <random>
#include <time.h>
#include <string>
#include <windows.h>
#include <iostream>

using namespace std;

double calculate_price(int station, int type)
{
    double price = 0;
    //站点数判断
    if (station <= 3)
        price = 3;
    else
        price = 3 + (station - 3) * 0.5;
    //优惠类型判断
    if (type == 2)
        price = 0;
    else if (type == 3)
        price *= 0.2;
    else if (type == 4)
        price *= 0.5;
    else if (type == 5)
        price *= 0.8;

    //调试用 调试用 调试用 调试用 调试用 
    cout << "---优惠类型：" << type << "，乘坐站点数：" << station << "，价格：" << price << endl;

    return price;
}

int main(int argc, char* argv[])
{
	random_device rd;
	mt19937 gen(rd());
    
    // 站点名称数组，包含星号
    string stations[6] = {
        "*Canton_tower*",       // 广州塔，始发站
        "*Lin_he_dong*",        // 林和东
        "*Tao_jin*",            // 桃金
        "*Zhu_jiang_xin_chen*", // 珠江新城
        "*Tian_he*",            // 天河
        "*Shi_pai*"             // 石牌桥
    };

    // 处理站点名称数组stations到name
    string name[6];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < stations[i].size(); j++)
        {
            if ((stations[i])[j] == '*') // 删除“*”
            {
                (stations[i]).erase(j, 1);
            }
            if ((stations[i])[j] == '_') // 替换“_”为空格
            {
                stations[i].replace(j, 1, " ");
            }
            (stations[i])[j] = tolower((stations[i])[j]); // 转换为小写
        }
        name[i] = stations[i];
    }

    // 乘客人员容器pass
    // 优惠类型：1原价  2老人卡免费  3学生卡2折  4一卡通5折  5普通优惠卡8折
    vector<int> pass;
    int remain = 10;  // 剩余乘客计数
    for (int i = 0; i < 10; i++)
    {
        uniform_int_distribution<> dis(1, 5);
        pass.push_back(dis(gen));  // 随机优惠类型
    }

    // 抽取下车人数并计费
    double total = 0;  // 总收费计数
    for (int i = 1; i < 6; i++)  // 起始站不下车，站点计数从1开始
    {
        
        if (i != 5)
        {
            uniform_int_distribution<> le(0, remain);  
            int left = le(gen);  // 随机下车人数
            remain -= left;
            cout << "站点：" << name[i] << "，下车人数：" << left << endl;
            for (int j = 0; j < left; j++)
            {
                total += calculate_price(i, pass.back());
                pass.pop_back();
            }
        }
        else // 终点站全部下车
        {
            cout << "站点：" << name[i] << "，下车人数：" << remain << endl;
            for (int j = 0; j < remain; j++)
            {
                total += calculate_price(i, pass.back());
                pass.pop_back();
            }
        }
        
    }
    
    cout << "总收费：" << total << "元" << endl;
}