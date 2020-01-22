#include<stdio.h>
int main()
{
	int num;
	scanf("%d",&num);
	int in1;
	int aaa[100000];
	for(in1=0;in1<num;in1++)
	    scanf("%d",&aaa[in1]);
	int value;
	scanf("%d",&value);
	int in2,counter=0;
	for(in2=0;in2<num;in2++)
	{
		if(aaa[in2]!=value)
		counter=counter+1;
	}
	printf("%d\n",counter);
	return 0;	 
} 
