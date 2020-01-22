#include<stdio.h>
int main()
{
	int m,n;
	scanf("%d%d",&n,&m);
	int aaa=1;
	int in1;
	for(in1=1;in1<=365*m;in1++)
	{
		aaa=(aaa*2)%400009;
	}
	int ccc=(365*n)%400009;
	if((aaa-ccc)<0)
		printf("%d\n",(400009+aaa-ccc)%400009);
	else
		printf("%d\n",(aaa-ccc)%400009);
	return 0;
}
