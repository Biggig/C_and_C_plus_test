#include<iostream>
using namespace std;

int AdjustArray(int s[],int l,int r)//���ص������׼��λ�� 
{
	int i=l;
	int j=r;
	int x=s[l];//�ڵ�һ���� 
	while(i<j)
	{
		while(i<j&&s[j]<x)//�Ӻ����ұȻ�׼���������� 
			j--;
		if(i<j)//����s[j]>=x����i��j��ָλ�ò�ͬʱ����ӣ���ʱjΪ�¿� 
		{
			s[i]=s[j];
			i++;
		}
		while(i<j&&s[i]>=x)//��ǰ���ұȻ�׼��С�������
			i++;
		if(i<j)//��i��j��ָλ�ò�ͬʱ����ӣ���ʱiΪ�¿�
		{
			s[j]=s[i];
			j--;
		}		
	}
	s[i]=x;
	return i; 
}

void quick_sort(int s[],int l,int r)
{
	if(l<r)
	{
		int i=AdjustArray(s,l,r);//�������� 
		quick_sort(s,l,i-1);//����ǰ�� 
		quick_sort(s,i+1,r);//������ 
	}
} 

int main()
{
	int in1;
	int a[10];
	for(in1=0;in1<10;in1++)
	{
		a[in1]=in1;
	}
	quick_sort(a,0,9);
	for(in1=0;in1<10;in1++)
		cout << a[in1] << endl;
	return 0;	
 } 
