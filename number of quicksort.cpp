#include<iostream>
using namespace std;

/*int partition(int* a,int left,int right)
{
	int p=a[left];
	int i,j;
	i=left+1;
	for(j=left+1;j<=right;j++)
	{
		if(a[j]<p)
		{
			int exc=a[j];
			a[j]=a[i];
			a[i]=exc;
			i++;	
		}
	}
	a[left]=a[i-1];
	a[i-1]=p;
	return i-1;
} */

/*void quicksort(int *a,int head,int rear)
{
	if(head<rear)
	{
		int p=partition(a,head,rear);
		quicksort(a,head,p-1);
		quicksort(a,p+1,rear);
	}
}*/


int main()
{
	int in1;
	int a[10];
	for(in1=0;in1<10;in1++)
	{
		a[in1]=in1;
	}
	//quick_sort(a,0,9);
	for(in1=0;in1<10;in1++)
		cout << a[in1] << endl;
	return 0;	
}
