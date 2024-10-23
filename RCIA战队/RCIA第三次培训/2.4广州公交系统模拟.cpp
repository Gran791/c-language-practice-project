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
    //վ�����ж�
    if (station <= 3)
        price = 3;
    else
        price = 3 + (station - 3) * 0.5;
    //�Ż������ж�
    if (type == 2)
        price = 0;
    else if (type == 3)
        price *= 0.2;
    else if (type == 4)
        price *= 0.5;
    else if (type == 5)
        price *= 0.8;

    //������ ������ ������ ������ ������ 
    cout << "---�Ż����ͣ�" << type << "������վ������" << station << "���۸�" << price << endl;

    return price;
}

int main(int argc, char* argv[])
{
	random_device rd;
	mt19937 gen(rd());
    
    // վ���������飬�����Ǻ�
    string stations[6] = {
        "*Canton_tower*",       // ��������ʼ��վ
        "*Lin_he_dong*",        // �ֺͶ�
        "*Tao_jin*",            // �ҽ�
        "*Zhu_jiang_xin_chen*", // �齭�³�
        "*Tian_he*",            // ���
        "*Shi_pai*"             // ʯ����
    };

    // ����վ����������stations��name
    string name[6];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < stations[i].size(); j++)
        {
            if ((stations[i])[j] == '*') // ɾ����*��
            {
                (stations[i]).erase(j, 1);
            }
            if ((stations[i])[j] == '_') // �滻��_��Ϊ�ո�
            {
                stations[i].replace(j, 1, " ");
            }
            (stations[i])[j] = tolower((stations[i])[j]); // ת��ΪСд
        }
        name[i] = stations[i];
    }

    // �˿���Ա����pass
    // �Ż����ͣ�1ԭ��  2���˿����  3ѧ����2��  4һ��ͨ5��  5��ͨ�Żݿ�8��
    vector<int> pass;
    int remain = 10;  // ʣ��˿ͼ���
    for (int i = 0; i < 10; i++)
    {
        uniform_int_distribution<> dis(1, 5);
        pass.push_back(dis(gen));  // ����Ż�����
    }

    // ��ȡ�³��������Ʒ�
    double total = 0;  // ���շѼ���
    for (int i = 1; i < 6; i++)  // ��ʼվ���³���վ�������1��ʼ
    {
        
        if (i != 5)
        {
            uniform_int_distribution<> le(0, remain);  
            int left = le(gen);  // ����³�����
            remain -= left;
            cout << "վ�㣺" << name[i] << "���³�������" << left << endl;
            for (int j = 0; j < left; j++)
            {
                total += calculate_price(i, pass.back());
                pass.pop_back();
            }
        }
        else // �յ�վȫ���³�
        {
            cout << "վ�㣺" << name[i] << "���³�������" << remain << endl;
            for (int j = 0; j < remain; j++)
            {
                total += calculate_price(i, pass.back());
                pass.pop_back();
            }
        }
        
    }
    
    cout << "���շѣ�" << total << "Ԫ" << endl;
}