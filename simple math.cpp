#include<stdio.h>
int main()
{
	int aaa[10000];
	int in1=0;
	while(scanf("%d",&aaa[in1])!=EOF)
	{
        in1=in1+1;
	}
	int in2;
	int tol=0;
	for(in2=0;in2<in1;in2++)
	{
		tol=tol+aaa[in2];
	}
	double aver=(double)tol/in1;
	int max=0;
	for(int in3=0;in3<in1;in3++)
	{
		if(aaa[in3]>max)
		max=aaa[in3];
	}
	int min=max;
	for(int in4=0;in4<in1;in4++)
	{
		if(aaa[in4]<min)
		min=aaa[in4];
	}
	printf("%d\n%.2lf\n%d\n%d\n",tol,aver,max,min);
	return 0;	
}
