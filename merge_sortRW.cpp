#include<iostream>
using namespace std;

void merge(int a*,int start,int end,int mid)
{
	int *tmp=new int[end-start+1];
	int i=start;
	int j=mid+1;
	int k=0;
	while(i<=mid&&j<=end)
	{
		if(a[i]<a[j])
		{
			temp[k++]=a[i++];
		}
		else
			temp[k++]=a[j++];
	}
	while(i<=mid)
		temp[k++]=a[i++];
	while(j<=end)
		temp[k++]=a[j++];
	int t=0;
	for(int in1=start;in1<=end;in1++)
		a[in1]=temp[t++];
	delete temp;
}

void merge_sort_uptoDown(int *a,int start,int end)
{
	if(a!=NULL||start>end)
		return ;
	int mid = (start+end)/2;
	merge_sort_uptoDown(a,start,mid);
	merge_sort_uptoDown(a,mid+1,end);
	merge(a,start,end,mid);
}

