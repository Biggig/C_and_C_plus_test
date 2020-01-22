#include<stdio.h>
int main()
{
	int num;
	scanf("%d ",&num);
	int in1;
	for(in1=0;in1<num;in1++)
	{
		char name[100]={0};
		int in2=0;
		for(in2=0;in2<100;in2++)
		{
			name[in2]=getchar();
			if(name[in2]=='\n')
			break;
		}
		if(name[0]!='_')
		{
			if(name[0]<'A')
			{
				printf("No\n");
				continue;
			}
			if(name[0]>'Z'&&name[0]<'a')
			{
				printf("No\n");
				continue;
			}
			if(name[0]>'z')
			{
				printf("No\n");
				continue;
			}
		}
		int in3;
		for(in3=1;in3<=in2;in3++)
		{
			if(name[in3]=='_')
			continue;
			if(name[in3]<'0'||name[in3]>'z')
			break;
			if(name[in3]>'9'&&name[in3]<'A')
			break;
			if(name[in3]>'Z'&&name[in3]<'a')
			break;
		}
		if(in3==in2)
		printf("Yes\n");
		else
		printf("No\n");     
	}
	return 0;
}
