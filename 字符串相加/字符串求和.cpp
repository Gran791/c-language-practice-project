#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//�ַ������ by ��Ƚ�� 

int error()
{
	printf("������������������\n");
	system("pause");
	exit(1);
}

int jisuan(char shu[])
{
	int s = 0;
	//���ַ�תΪ��ֵ 
	for (int i = 0; i < 4; i++)
	{
		int temp = (shu[i]-'0')*pow(2,3-i);
		s += temp;
	 } 
	return s;
}

int shuru(char in[])
{
    //��ȡ��һ������ 
	scanf("%4s",in);
	int f = atoi(in);
	if(f < 1 || f > 1000)  //��Χ�ж� 
	{
		error();
	}
	for (int i = 0; in[i]!='\0'; i++) 
	{
		//printf("%c\n",first[i]);
		if (in[i] != '0' && in[i] != '1')  //�������ж� 
		{
			error();
		}
	}
	
	int s = jisuan(in);
	return s;
 } 

int main()
{
    char first[4], second[4];
    int s1, s2;
    
    printf("������λ������������Χ0001~1000\n");  //��Χ�ɱ� 

	//��ȡʮ�������� 
    printf("�������1������������") ; 
	s1 = shuru(first);
    printf("�������2������������") ; 
	s2 = shuru(second);
	
	//���㲢���ʮ�����ܺ� 
	int total = s1 + s2;
	printf("ʮ�����ܺ�:%d\n",total);
	
	//����������ܺ� 
	int out[5];
	out[0] = total / 16;
	out[1] = total % 16 / 8;
	out[2] = total % 16 % 8 / 4;
	out[3] = total % 16 % 8 % 4 / 2;
	out[4] = total % 16 % 8 % 4 % 2 / 1;
	
	//����������ܺ� 
	printf("�������ܺ�:%d",out[0]);
	printf("%d",out[1]);
	printf("%d",out[2]);
	printf("%d",out[3]);
	printf("%d\n",out[4]);
	
	system("pause");
	
	return 0; 
}
