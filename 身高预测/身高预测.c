#include <stdio.h>

int main() 
{
	char gender;
	float f_height, m_height, pre_height;
	int sport, diet;
	
	printf("�������Ա�(m/f)��");
	scanf("%c", &gender) ;
	printf("�����븸�����(cm)��");
	scanf("%f", &f_height) ;
	printf("������ĸ�����(cm)��");
	scanf("%f", &m_height) ;
	printf("�Ƿ�ϲ������(1/0)��");
	scanf("%d", &sport) ;
	printf("�Ƿ������õ���ʳϰ��(1/0)��");
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
		
	printf("Ԥ����ߣ�%.2f", pre_height);
}

