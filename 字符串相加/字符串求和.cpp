#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//字符串求和 by 黄冉阳 

int error()
{
	printf("输入有误，请重新运行\n");
	system("pause");
	exit(1);
}

int jisuan(char shu[])
{
	int s = 0;
	//将字符转为数值 
	for (int i = 0; i < 4; i++)
	{
		int temp = (shu[i]-'0')*pow(2,3-i);
		s += temp;
	 } 
	return s;
}

int shuru(char in[])
{
    //获取第一个输入 
	scanf("%4s",in);
	int f = atoi(in);
	if(f < 1 || f > 1000)  //范围判断 
	{
		error();
	}
	for (int i = 0; in[i]!='\0'; i++) 
	{
		//printf("%c\n",first[i]);
		if (in[i] != '0' && in[i] != '1')  //二进制判断 
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
    
    printf("仅限四位二进制数，范围0001~1000\n");  //范围可变 

	//获取十进制输入 
    printf("请输入第1个二进制数：") ; 
	s1 = shuru(first);
    printf("请输入第2个二进制数：") ; 
	s2 = shuru(second);
	
	//计算并输出十进制总和 
	int total = s1 + s2;
	printf("十进制总和:%d\n",total);
	
	//计算二进制总和 
	int out[5];
	out[0] = total / 16;
	out[1] = total % 16 / 8;
	out[2] = total % 16 % 8 / 4;
	out[3] = total % 16 % 8 % 4 / 2;
	out[4] = total % 16 % 8 % 4 % 2 / 1;
	
	//输出二进制总和 
	printf("二进制总和:%d",out[0]);
	printf("%d",out[1]);
	printf("%d",out[2]);
	printf("%d",out[3]);
	printf("%d\n",out[4]);
	
	system("pause");
	
	return 0; 
}
