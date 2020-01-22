#include<stdio.h>
int main()
{ 
	int n,m;
	scanf("%d%d",&n,&m);
	if(n==1)
	printf("1\n");
	else
	{
	    int s=0;
		for(int in1=2;in1<=n;in1++)
		{s=(s+m)%in1;
		printf("%d\n",s+1);} 
	}
	return 0;
}
