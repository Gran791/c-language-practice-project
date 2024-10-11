#include <stdio.h>

int main() 
{
	char gender;
	float f_height, m_height, pre_height;
	int sport, diet;
	
	printf("请输入性别(m/f)：");
	scanf("%c", &gender) ;
	printf("请输入父亲身高(cm)：");
	scanf("%f", &f_height) ;
	printf("请输入母亲身高(cm)：");
	scanf("%f", &m_height) ;
	printf("是否喜爱锻炼(1/0)：");
	scanf("%d", &sport) ;
	printf("是否有良好的饮食习惯(1/0)：");
	scanf("%d", &diet) ;
	
	if (gender == 'm')
	{
		pre_height = (f_height + m_height) * 0.54;
	}
	
	else if (gender == 'f')
	{
		pre_height = (f_height * 0.923 + m_height) / 2;
	}

	if (sport == 1)
	{
		pre_height *= 1.020;
	} 
	
	if (diet == 1)
	{
		pre_height *= 1.015;
	}
		
	printf("预测身高：%.2f", pre_height);
}

