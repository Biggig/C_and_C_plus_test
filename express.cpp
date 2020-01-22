#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char str[1000];
	int num[1000];
	char numb[50]={'\0'};
	char fuhao[1000];
	scanf("%s",str);
	int in1,in2=0,in3=0,in4=0;
	for(in1=0;in1<strlen(str);in1++)
	{
		if(str[in1]>='0'&&str[in1]<='9')
		{
			int in5;
			for(in5=in1;in5<strlen(str);in5++)
			{
				numb[in4]=str[in5];
				in4=in4+1;
			}
			if(in4>4)
			{
				char num2={numb[in4-4],numb[in4-3],numb[in4-2],numb[in4-1]};
				num[in2]=atoi(num2);
			}
			else
			num[in2]=atoi(numb);
			in4=0;
			in2=in2+1;
			int in6;
			for(in6=0;in6<in4;in6++)
			numb[in6]='\0';
		}
		
		else
		{
			fuhao[in3]=str[in1];
			in3=in3+1;
		}
	}
	int in7;
	for(in7=in2-1;in7>=1;in7--)
	{
		switch(fuhao[in7-1])
		{
			case '+':num[in7-1]=num[in7]+num[in7-1];break;
			case '-':num[in7-1]=
		}
	}
}
