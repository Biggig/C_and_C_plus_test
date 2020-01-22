#include<stdio.h>
int main()
{
	int num;
	scanf("%d",&num);
	int in1;
	for(in1=0;in1<num;in1++)
	{
		int money;
		int times;
		scanf("%d%d",&money,&times);
		int in2;
		for(in2=0;in2<times;in2++)
		{
			int price;
			int numb;
			scanf("%d%d",&price,&numb);
			money=money-price*numb;
		}
		if(money>=0)
		  printf("%d\n",money);
		else
		printf("Not enough\n");  
	}
	return 0;
}
