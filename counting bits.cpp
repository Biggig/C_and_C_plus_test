#include<stdio.h>
int main()
{
	int num;
	scanf("%d",&num);
	int in1;
	for(in1=0;in1<=num;in1++)
	{
		int aaa[100];
		int in2;
		int hold=in1;
		for(in2=0;in2<100;in2++)
		{
			aaa[in2]=hold%2;
			hold=hold/2;
			if(hold==0)
			break;
		}
		int in3;
		int counter=0;
		for(in3=0;in3<=in2;in3++)
		{
			if(aaa[in3]==1)
			counter=counter+1;
		}
		if(in1==num)
		printf("%d\n",counter);
		else
		printf("%d,",counter);
	}
	return 0;
}
