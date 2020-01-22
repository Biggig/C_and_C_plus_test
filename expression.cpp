#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int num[50];
	char fuhao[50];
	char shizi[1000];
	scanf("%s",shizi);
	int in1=strlen(shizi);
	int in2;
	int in4,in5;
	in4=in5=0;
	for(in2=0;in2<=in1;in2++)
	{
		if(shizi[in2]>='0'&&shizi[in2]<='9')
		{
			int in3;
			int truenum=0;
			for(in3=in2;in3<=in1;in3++)
			{
				truenum=truenum*10+shizi[in3]-48;
				if(shizi[in3+1]<'0'||shizi[in3+1]>'9')
				   break;
			}
			if(in3-in2<=3)
			{
				num[in4]=truenum;
				in4++;
				in2=in3;
			}
			else
			{
				int in6;
				truenum=0;
				for(in6=in3-3;in6<=in3;in6++)
				{
					truenum=truenum*10+shizi[in6]-48;
				}
				num[in4]=truenum;
				in4++;
				in2=in3;
			}
		}
		else
		{
			fuhao[in5]=shizi[in2];
			in5++;
		}
	}//ÊäÈëÍê³É
	 
	return 0;	
}
