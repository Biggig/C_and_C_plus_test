#include<stdio.h>
int main()
{
	int aaa,bbb;
	scanf("%d%d",&aaa,&bbb);
	int in1,in2;
	for(in1=aaa;in1<=bbb;in1++)
	{
		for(in2=1;in2<=in1;in2++)
		{
			if(in2==in1)
			printf("%d*%d=%d\n",in2,in1,in2*in1);
			else
			printf("%d*%d=%d  ",in2,in1,in2*in1);
		}
	}
	return 0;
}
