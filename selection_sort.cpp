#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;

int max(int* a,int head,int rear)
{
	int in1;
	int ele=head;
	for(in1=head+1;in1<=rear;in1++)
	{
		if(a[in1]>a[ele])
			ele=in1;
	}
	return ele;
}

void swap(int *a,int pos1,int pos2)
{
	int ele=a[pos1];
	a[pos1]=a[pos2];
	a[pos2]=ele;
}

void selection_sort(int *a,int head,int rear)
{
	int in1;
	for(in1=rear;in1>head;in1--)
	{
		int max_=max(a,head,in1);
		swap(a,max_,in1);
	}
}
 
 
int main()
{
	int num;
	cin >> num;
	int in1;
	int a[num];
	for(in1=num-1;in1>=0;in1--)
		a[in1]=num-in1;
	copy(a,a+num,ostream_iterator<int>(cout," "));
	cout << endl;
	selection_sort(a,0,num-1);
	copy(a,a+num,ostream_iterator<int>(cout," "));
	cout << endl;
	return 0;	
} 
