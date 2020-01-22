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
	for(in2=0;in2<in1;in2=in2+3)
	{
		if(code[in2]==48)
		{
			if(code[in2+1]==48&&code[in2+2]==48)
			printf(" ");
			else
			{
				printf("%c",97+(code[in2+1]-48)*10+code[in2+2]-49);
			}
		}
		else
		{
			printf("%c",65+(code[in2+1]-48)*10+code[in2+2]-49);
		}
	}
	printf("\n");
	return 0;
}
