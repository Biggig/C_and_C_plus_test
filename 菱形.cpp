#include<stdio.h>

int main()
{
	int num;//���εı߳�
	scanf("%d",&num);
	int counter=0;//��������
	int i=0;//��������
	int n=0;//��������	
	for(counter=1;counter<=num;counter++)//��ӡ�ϰ벿�� 
	{
		
		for(i=0;i<num-counter;i++)//��ӡ�ո� 
			printf(" ");
		for(n=0;n<counter*2-1;n++)//��ӡ* 
			printf("*");
		printf("\n");	 
	} 
	for(counter=1;counter<num;counter++)//��ӡ�°벿�� 
	{
		
		for(i=0;i<counter;i++)//��ӡ�ո� 
			printf(" ");
		for(n=0;n<(num-counter)*2-1;n++)//��ӡ* 
			printf("*");
		printf("\n");	 
	}
	return 0; 
}
