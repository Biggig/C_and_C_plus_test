#include<iostream>
using namespace std;

int binarySearch(int *num,int start,int end,int key)
{
	int mid=(start+end)/2;
	if(num[mid]==key)
		return mid;
	if(start>end)
		return -1;		
	if(num[mid]>key)
		binarySearch(num,start,mid-1,key);
	else
		binarySearch(num,mid,end,key);	
} 

int main()
{
	int in1;
	int a[10];
	for(in1=0;in1<10;in1++)
		a[in1]=in1;
	int result=binarySearch(a,0,9,2);
	cout << result << endl;
	return 0;	
}
