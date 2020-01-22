#include<stdio.h>
int main()
{
	int tol,start,space;
	scanf("%d%d%d",&tol,&start,&space);
    int light[100];
    int sign[100]={0};
    int in1;
    for(in1=0;in1<tol;in1++)
    light[in1]=in1;
    int offlight=0;
	int turn=space-1;
	int in2;
	for(in2=start;in2<tol;in2++)
	{
		if(sign[in2]==0)
		turn=turn+1;
		if(turn==space)
		{
			printf("%d ",light[in2]);
			turn=0;
			offlight=offlight+1;
			sign[in2]=-1;
		}
		if(in2==tol-1)
		in2=-1;
		if(offlight==tol)
		break;
	}
	printf("\n");
	return 0;   
}
