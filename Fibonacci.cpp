#include<stdio.h>
#include<math.h>
int main()
{
	int test;
	scanf("%d",&test);
	int in1;
	for(in1=0;in1<test;in1++)
	{
		double aaa,num;
		double ccc=pow(5,0.5);
		scanf("%lf",&num);
		if(num==0)
		{
			printf("1\n");
			continue;
		}
		else
		{
			int in2;
			for(in2=1;in2<10000;in2++)
			{
				aaa=1/ccc*(pow(((1+ccc)/2),in2)-pow(((1-ccc)/2),in2));
				if((num-aaa)<(1e-5)&&(aaa-num)<(1e-5))
				{
					printf("%d\n",in2+1);
					break;
				}
				if(num<aaa)
				{
					printf("0\n");
					break;
				}	
			}
		}
	}
	return 0;
}
