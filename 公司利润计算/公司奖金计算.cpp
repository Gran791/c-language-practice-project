#include <stdio.h>

//企业发放的奖金根据利润提成。

//利润（prifit）低于或等于10万元时，奖金可提10%；

//利润高于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，可提成7.5%；20万到40万之间时，高于20万元的部分，可提成5%；

//40万到60万之间时高于40万元的部分，可提成3%；

//60万到100万之间时，高于60万元的部分，可提成1.5%，高于100万元时，超过100万元的部分按1%提成，

//从键盘输入当月利润profit，求应发放奖金总数 

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
 	
 	printf("获得的奖金（万元）：%f", reward);
	return 0;
 }

