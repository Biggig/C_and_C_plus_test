#include<iostream>
using namespace std;

int AdjustArray(int s[],int l,int r)//返回调整后基准数位置 
{
	int i=l;
	int j=r;
	int x=s[l];//挖第一个坑 
	while(i<j)
	{
		while(i<j&&s[j]<x)//从后面找比基准数大的数填坑 
			j--;
		if(i<j)//表明s[j]>=x；当i、j所指位置不同时，填坑，此时j为新坑 
		{
			s[i]=s[j];
			i++;
		}
		while(i<j&&s[i]>=x)//从前面找比基准数小的数填坑
			i++;
		if(i<j)//当i、j所指位置不同时，填坑，此时i为新坑
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
		int i=AdjustArray(s,l,r);//调整数组 
		quick_sort(s,l,i-1);//调整前部 
		quick_sort(s,i+1,r);//调整后部 
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
