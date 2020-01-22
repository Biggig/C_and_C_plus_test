#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "table.h2.0"


int main()
{
	int num;
	scanf("%d\n",&num);
    table *aaa;
    aaa=(table *)malloc(sizeof(table)*num);
    input(num,aaa);
	int action;
	scanf("%d",&action);
	while(action!=-1)
	{
		if(action==0)
		{
            output(num,aaa);	
		}
		if(action==2)
		{
            action2(num,aaa);
		}
		if(action==3)
		{
            action3(0,num,aaa);
		}
		if(action==4)
		{
            action4(num,aaa);
		}
		if(action==1)
		{
            action1(num,aaa);
		}
		scanf("%d",&action);
	}
	free(aaa);
	return 0;
} 
