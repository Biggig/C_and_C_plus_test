#include<stdio.h>
int main()
{
	int num;
	scanf("%d",&num); 
	for(int in1=0;in1<num;in1++)
	{
		int pro;
		float bon;
		scanf("%d",&pro);
		if(pro<=100000)
		   bon=pro*0.1;
		if(pro>100000&&pro<=200000)
		   bon=10000+(pro-100000)*0.075;
		if(pro>200000&&pro<=400000)
		   bon=17500+(pro-200000)*0.05;
		if(pro>400000&&pro<=600000)
		   bon=27500+(pro-400000)*0.03;
		if(pro>600000&&pro<=1000000)
		   bon=33500+(pro-600000)*0.015;
		if(pro>1000000)
		   bon=39500+(pro-1000000)*0.01;
		printf("%.0f\n",bon);
	}
	return 0;
}
