#include<stdio.h>
int main()
{
	int num;
	scanf("%d",&num);
	for(int in1=0;in1<num;in1++)
	{
		int div;
		scanf("%d ",&div);
		char num1[10000];
		int in2;
		for(in2=0;in2<100000;in2++)
		{
			scanf("%c",&num1[in2]);
			if(num1[in2]=='\n')
			   break;
		}
		int aaa=0;
		for(int in3=in2-1;in3>=0;in3--)
		{
		    aaa=(aaa*10+(num1[in3]-48))%div;
		}
		
		printf("%d\n",aaa%div);
	}
	return 0;
}
