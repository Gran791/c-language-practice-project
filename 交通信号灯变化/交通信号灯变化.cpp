#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <random>
#include <time.h>
#include <string>

//����80��  ��0-30 ��30-75 ��75-80
using namespace std;

void out()
{

}

int main(int argc, char* argv[])
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> n(0, 79);//���·�ڳ�ʼֵ
	
	int cr1 = n(gen);
	int cr2 = n(gen);
	int cr3 = n(gen);
	int cr4 = n(gen);
	int cr5 = n(gen);
	
	int seconds[5] = { cr1, cr2, cr3, cr4, cr5 };
	int status[5] = { 0 };  //���1 �̵�2 �Ƶ�3
	int temp[5] = { 0 };

	for (int i = 0; i < 600; i++)  //�趨ʱ��
	{
		//�ж�·��״̬��status��
		for (int j = 0; j < 5; j++)
		{
			if (seconds[j] <= 30)  //���
			{
				//printf("��%d��·�ڣ����\n", j + 1);
				status[j] = 1;
			}
			else if (seconds[j] <= 75)  //�̵�
			{
				//printf("��%d��·�ڣ��̵�\n", j + 1);
				status[j] = 2;
			}
			else if (seconds[j] <= 80)  //�Ƶ�
			{
				//printf("��%d��·�ڣ��Ƶ�\n", j + 1);
				status[j] = 3;
			}
			else
				seconds[j] = 0;
		}
		//����·��ʱ��
		for (int j = 0; j < 5; j++)
			seconds[j]++;
		//�ж�·��״̬��temp��
		for (int j = 0; j < 5; j++)
		{
			if (seconds[j] <= 30)  //���
			{
				//printf("��%d��·�ڣ����\n", j + 1);
				temp[j] = 1;
			}
			else if (seconds[j] <= 75)  //�̵�
			{
				//printf("��%d��·�ڣ��̵�\n", j + 1);
				temp[j] = 2;
			}
			else if (seconds[j] <= 80)  //�Ƶ�
			{
				//printf("��%d��·�ڣ��Ƶ�\n", j + 1);
				temp[j] = 3;
			}
		}
		//�ж�·��״̬���£�temp��seconds��
		for (int j = 0; j < 5; j++)
		{
			if (status[j] != temp[j])
			{
				string pre, post;
				if (temp[j] == 1)  //ת���
				{
					pre = "\033[0;43;30m�Ƶ�\033[0m";
					post = "\033[0;41;30m���\033[0m";
				}
				else if (temp[j] == 2)
				{
					pre = "\033[0;41;30m���\033[0m";
					post = "\033[0;42;30m�̵�\033[0m";
				}
				else if (temp[j] == 3)
				{
					pre = "\033[0;42;30m�̵�\033[0m";
					post = "\033[0;43;30m�Ƶ�\033[0m";
				}

				printf("[��%d��]��%d��·�ڣ�%s ת %s\n", i, j + 1, pre.c_str(), post.c_str());
				
			}
		}
	}
}
