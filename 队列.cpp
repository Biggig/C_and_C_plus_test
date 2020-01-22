#include<stdio.h>
int main()
{
	int num;
	scanf("%d",&num);
	int in1;
	int numb[3000];
	for(in1=0;in1<num;in1++)
	    numb[in1]=in1+1;
	int front=0,rear=num;
	while(front<rear)
	{
		if(front==rear-1)
		   printf("%d\n",numb[front++]);
		else
		   printf("%d ",numb[front++]);
		   numb[rear++]=numb[front++];
	}
	return 0;    
}
