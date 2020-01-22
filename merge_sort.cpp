#include<iostream>
using namespace std;

void merge(int a[],int start,int mid,int end)//合并两个子数组 
{
	int *tmp=new int[end-start+1];
	int i=start;
	int j=mid+1;
	int k=0;
	while(i<=mid&&j<=end)
	{
		if(a[i]>=a[j])
			tmp[k++]=a[i++];
		else
			tmp[k++]=a[j++];	
	}
	while(i<=mid)
		tmp[k++]=a[i++];
	while(j<=end)
		tmp[k++]=a[j++];
	int in1;
	for(in1=0;in1<k;in1++)
		a[start+in1]=tmp[in1];
	delete tmp;			
}

void merge_sort_up2down(int a[],int start,int end)//递归实现分割数组 
{
	if(a==NULL||start>=end)
		return;
	int mid=(start+end)/2;
	merge_sort_up2down(a,start,mid);
	merge_sort_up2down(a,mid+1,end);
	merge(a,start,mid,end);
}

int main()
{
	int in1;
	int a[10];
	for(in1=0;in1<10;in1++)
		a[in1]=in1;
	merge_sort_up2down(a,0,9);
	for(in1=0;in1<10;in1++)
		cout << a[in1] << endl;
	return 0;		
}
