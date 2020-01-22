#include<stdio.h>
#include<math.h>

int compute(int in1,int *digit,int *wrong);

int main()
{
	int fakenum;
	scanf("%d",&fakenum);
	int wrong[9]={0};
	wrong[0]=0;
	int in3;
	for(in3=1;in3<8;in3++)
	{
		wrong[in3]=8*wrong[in3-1]+2*pow(10,in3-1);
	}
	while(fakenum!=0)
	{
		int fakenum1=fakenum;
		int digit[10]={0};
		int in1;
		for(in1=0;in1<9;in1++)
		{
			digit[in1]=fakenum1%10;
			fakenum1=fakenum1/10;
			if(fakenum1==0)
			    break;
		}
		int mistake=0;
        mistake=compute(in1,digit,wrong);
		if(digit[0]<=7&&digit[0]>2)
		    mistake=mistake+1;
		if(digit[0]==9)
		    mistake=mistake+2;
		printf("%d: %d\n",fakenum,fakenum-mistake);
		scanf("%d",&fakenum);	    
	}
	return 0;
}

int compute(int in1,int *digit,int *wrong)
{
		int in2;
		int mistake=0;
		for(in2=1;in2<=in1;in2++)
		{
			if(digit[in2]<=2)
			   mistake=mistake+digit[in2]*wrong[in2];
			else if(digit[in2]>2&&digit[in2]<=7)
			   mistake=mistake+pow(10,in2)+(digit[in2]-1)*wrong[in2];
			else if(digit[in2]==9)
			   mistake=mistake+2*pow(10,in2)+(digit[in2]-2)*wrong[in2];               
		}
		return mistake;
}
