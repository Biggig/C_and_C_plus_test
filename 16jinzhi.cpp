#include<stdio.h>
int main()
{
	int num;
	scanf("%d",&num);
	int dig[100];
	int in1;
	for(in1=0;in1<99;in1++)
	{
		dig[in1]=num%16;
		num=num/16;
		if(num==0)
		break;
	}
	for(int in2=0;in2<=in1;in2++)
	{
		if(dig[in2]==10)
		   printf("A");
		else if(dig[in2]==11)
		   printf("B");
		else if(dig[in2]==12)
		   printf("C");
		else if(dig[in2]==13)
		   printf("D");
		else if(dig[in2]==14)
		   printf("E");
		else if(dig[in2]==15)
		   printf("F");
		else
		   printf("%d",dig[in2]);               
	}
	printf("\n");
	return 0;      
}
