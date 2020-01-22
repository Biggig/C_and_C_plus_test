#include<stdio.h>
int main()
{
	long int vec1[10];
	long int vec2[10];
	int in1;
	for(in1=0;in1<3;in1++)
	{
		scanf("%lld",&vec1[in1]);
	}
	for(int in3=0;in3<3;in3++)
	{
		scanf("%lld",&vec2[in3]);
	}
	int in2;
	long long int total=0;
	for(in2=0;in2<3;in2++)
	total=total+vec1[in2]*vec2[in2];
	if(total!=0)
	printf("Xite!\n");
	else
    printf("Oh yes!\n");
}
