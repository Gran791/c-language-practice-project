#include <stdio.h>

//��ҵ���ŵĽ������������ɡ�

//����prifit�����ڻ����10��Ԫʱ���������10%��

//�������10��Ԫ������20��Ԫʱ������10��Ԫ�Ĳ��ְ�10%��ɣ�����10��Ԫ�Ĳ��֣������7.5%��20��40��֮��ʱ������20��Ԫ�Ĳ��֣������5%��

//40��60��֮��ʱ����40��Ԫ�Ĳ��֣������3%��

//60��100��֮��ʱ������60��Ԫ�Ĳ��֣������1.5%������100��Ԫʱ������100��Ԫ�Ĳ��ְ�1%��ɣ�

//�Ӽ������뵱������profit����Ӧ���Ž������� 

int main()
{
	float profit, reward, 
	reward1 = 10 * 0.100, 
	reward2 = reward1 + 10 * 0.075, 
	reward3 = reward2 + 20 * 0.050, 
	reward4 = reward3 + 20 * 0.030, 
	reward5 = reward4 + 40 * 0.015;
	
	
	printf("���빫˾������Ԫ����");
	scanf("%f", &profit);
	
	if (profit <= 10)
		reward = profit * 0.1;
	else if (profit <= 20)
		reward = reward1 + (profit - 10) * 0.075;
	else if (profit <= 40)
		reward = reward2 + (profit - 20) * 0.050;
 	else if (profit <= 60)
 		reward = reward3 + (profit - 40) * 0.030;
 	else if (profit <= 100)
 		reward = reward4 + (profit - 60) * 0.015;
 	else
 		reward = reward5 + (profit - 100) * 0.010;
 	
 	printf("��õĽ�����Ԫ����%f", reward);
	return 0;
 }

