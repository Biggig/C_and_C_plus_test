#include <stdio.h>
void add(char[], char[], char[]);
int main() {
  char lhs[8] = {}, rhs[8] = {}, sum[10] = {};
  scanf("%s %s", lhs, rhs);
  add(lhs, rhs, sum);
  printf("%s\n", sum);
  return 0;
}

#include<math.h>
#include<string.h>
void add(char lhs[],char rhs[],char sum[])
{
	int in1;
	long long int num1=0,num2=0;
	for(in1=strlen(lhs)-1;in1>=0;in1--)
	{
		num1=num1+pow(10,strlen(lhs)-1-in1)*(lhs[in1]-48);
	}
	int in2;
	for(in2=strlen(rhs)-1;in2>=0;in2--)
	{
		num2=num2+pow(10,strlen(rhs)-1-in2)*(rhs[in2]-48);
	}
	long long int tol=num1+num2;
	int in3,in6;
	for(int in6=0;in6<10;in6++)
	    sum[in6]='\0';
	for(in3=0;in3<10;in3++)
	{
		sum[in3]=tol%10+48;
		tol=tol/10;
		if(tol==0)
		break;
	}
	int in4,in5=0;
	char hold;
	for(in4=in3;in4>=in5;in4--,in5++)
	{
		hold=sum[in4];
		sum[in4]=sum[in5];
		sum[in5]=hold;
	}
}
