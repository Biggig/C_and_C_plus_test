#include<stdio.h>

int main()
{
	int num;//菱形的边长
	scanf("%d",&num);
	int counter=0;//计数变量
	int i=0;//计数变量
	int n=0;//计数变量	
	for(counter=1;counter<=num;counter++)//打印上半部分 
	{
		
		for(i=0;i<num-counter;i++)//打印空格 
			printf(" ");
		for(n=0;n<counter*2-1;n++)//打印* 
			printf("*");
		printf("\n");	 
	} 
	for(counter=1;counter<num;counter++)//打印下半部分 
	{
		
		for(i=0;i<counter;i++)//打印空格 
			printf(" ");
		for(n=0;n<(num-counter)*2-1;n++)//打印* 
			printf("*");
		printf("\n");	 
	}
	return 0; 
}
