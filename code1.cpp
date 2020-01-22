#include<stdio.h>
int main()
{
	char code[1000];
	int in1;
	for(in1=0;in1<1000;in1++)
	{
		code[in1]=getchar();
		if(code[in1]=='\n')
		break;
	}
	int in2;
	for(in2=0;in2<in1;in2++)
	{
		if(code[in2]==' ')
		printf("000");
		else if(code[in2]>='a'&&code[in2]<='z')
		{
			if((code[in2]-96)<=9)
			printf("00%d",code[in2]-96);
			else
			printf("0%d",code[in2]-96);
		}
		else
		{
			if((code[in2]-64)<=9)
			printf("10%d",code[in2]-64);
			else
			printf("1%d",code[in2]-64);
		}
	}
	printf("\n");
	return 0;
}
