#include<stdio.h>
int main()
{
	int num;
	scanf("%d",&num);
	int dig[1000];
	int in1,in2;
	int tol=0;
	while(num>9)
	{
		for(in1=0;in1<1000;in1++)
	   {
		    dig[in1]=num%10;
		    num=num/10;
		    if(num==0)
		    break;
	   }
	   for(in2=0;in2<=in1;in2++)
	   {
	       tol=tol+dig[in2];
	   }
	   num=tol;
	   tol=0;
	}
	printf("%d\n",num);
    return 0;
}
