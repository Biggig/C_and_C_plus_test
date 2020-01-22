#include<stdio.h>
void swap(int *aaa,int *bbb)
{
	int mmm;
	mmm=*aaa;
	*aaa=*bbb;
	*bbb=mmm;
}

void swap1(int aaa[],int ccc,int bbb)
{
	            int in3,in4;
				for(in3=ccc;in3<bbb;in3++)
			{
				for(in4=ccc;in4<bbb;in4++)
				{
					if(aaa[in4]>aaa[in4+1])
					   swap(&aaa[in4],&aaa[in4+1]);
				}
				
			} 
}

int operation(int aaa[],int num1,int num2)
{
	if(num1>num2)
	{
		int in1;
		for(in1=0;in1<=num2;in1++)
		{
			if(in1==num2)
				printf("%d\n",aaa[in1]);
			else
				printf("%d ",aaa[in1]);
		}
	}
	else
	{
		int in2;
		for(in2=num1;in2<=num2;in2++)
		{
			swap(&aaa[in2],&aaa[num1]);
            swap1(aaa,num1+1,num2);
			operation(aaa,num1+1,num2);
	        swap1(aaa,num1,num2);
		}
	}
	return 0;
}
int main()
{
	int aaa[10];
	int num;
	scanf("%d",&num);
	int in3;
	for(in3=0;in3<num;in3++)
		aaa[in3]=in3+1;
	operation(aaa,0,num-1);
    return 0;
}
