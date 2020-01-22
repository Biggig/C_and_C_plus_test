#include<stdio.h>
int main()
{
	int num;
	scanf("%d",&num);
	int in1;
	for(in1=0;in1<num;in1++)
	{
		int num2;
		scanf("%d",&num2);
		int aaa[50];
		int in2;
		for(in2=0;in2<num2;in2++)
		{
			scanf("%d",&aaa[in2]);
		}
		for(in2=0;in2<num2;in2++)
		{
			int tidai=num2-in2;
			int in3;
			int counter=0;
			for(in3=0;in3<tidai-1;in3++)
			{
				if(aaa[in3]>aaa[in3+1])
				{
					int hold=0;
					hold=aaa[in3];
					aaa[in3]=aaa[in3+1];
					aaa[in3+1]=hold;
					counter++;
				}
				int in4;
				for(in4=0;in4<num2;in4++)
				{
					printf("%d ",aaa[in4]);   
				}
				printf("\n");
			}
			if(counter==0)
		        break; 
		}
	}
	return 0;
} 
