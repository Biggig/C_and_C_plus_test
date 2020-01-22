#include<stdio.h>
#include<math.h>
int main()
{
	int num,x;
	scanf("%d%d",&num,&x);
	int coe[10],deg[20];
	int in1;
	for(in1=0;in1<num;in1++)
	scanf("%d%d",&coe[in1],&deg[in1]);
	int in2;
	long long res=0;
	for(in2=0;in2<num;in2++)
	{
		if(deg[in2]==0)
		res=res+0;
		else if(deg[in2]==1)
		res=res+coe[in2];
		else
		res=res+coe[in2]*deg[in2]*pow(x,deg[in2]-1);
	}
	printf("%lld\n",res);
	return 0;
}
