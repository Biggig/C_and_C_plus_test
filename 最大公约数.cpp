#include<stdio.h>
int main()
{
	long long int num1,num2;
	while(scanf("%lld%lld",&num1,&num2)!=EOF)
	{
		long long int max,min;
		if(num1>num2)
		{
			max=num1;
			min=num2;
		}
		else
		{
			min=num1;
			max=num2;
		}
		long long int yushu=0;
		while(min!=0)
		{
			yushu=max%min;
			max=min;
			min=yushu;
		}
		printf("%lld\n",max);
	}
	return 0;
}
