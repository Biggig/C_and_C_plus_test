#include<stdio.h>
int main()
{
	char str[100];
	int in1=0;
    for(in1=0;in1<100;in1++)
    {
    	scanf("%c",&str[in1]);
    	if(str[in1]=='\n')
    	break;
	}
	printf("%c",str[0]);
	int in2,in3;
	for(in2=1;in2<in1;in2++)
	{
		int cou=0;
		for(in3=0;in3<in2;in3++)
		{
			if(str[in2]!=str[in3])
			cou=cou+1;
		}
		if(in2==cou)
		printf("%c",str[in2]);
	}
	printf("\n");
	return 0;
}
