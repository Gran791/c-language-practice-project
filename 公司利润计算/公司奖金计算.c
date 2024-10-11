#include <stdio.h>
#include <stdlib.h>

int main()
{
	float profit, reward, 
	reward1 = 10 * 0.100, 
	reward2 = reward1 + 10 * 0.075, 
	reward3 = reward2 + 20 * 0.050, 
	reward4 = reward3 + 20 * 0.030, 
	reward5 = reward4 + 40 * 0.015;
	
	
	printf("输入公司利润（万元）：");
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
 	
 	printf("获得的奖金（万元）：%f\n", reward);
 	
 	system("pause") ;
	return 0;
 }

