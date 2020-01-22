#include<stdio.h>
#include<string.h>
int main()
{
	char str[10000];
	int in1=0;
	scanf("%s",str);
	in1 = strlen(str);
		char check[1000]={0};
		int in2,in3=0;
		for(in2=0;in2<in1;in2++)
		{
			if(str[in2]=='('||str[in2]=='{'||str[in2]=='[')
			{
				check[in3]=str[in2];
				in3=in3+1;
				continue;
			}
			else if(str[in2]==check[in3-1]+1||str[in2]==check[in3-1]+2)
			{
				check[in3-1]=0;
				in3=in3-1;
			}
		}
		int in4;
		for(in4=0;in4<1000;in4++)
		{
			if(check[in4]!=0)
			break;
		}
		if(in4==1000)
		printf("True\n");
		else
		printf("False\n");
	return 0;       
}
