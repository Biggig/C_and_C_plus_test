#include<iostream>
using namespace std;

void insert_heap(int *entry,int low,int high,int current)
{
	int large;
	large=low*2+1;
	while(large<=high)
	{
		if(large<high&&entry[large]>entry[large+1])
			large++;
		if(current<=entry[large])
			break;
		else
		{
			entry[low]=entry[large];
			low=large;
			large=low*2+1;
		}
	}
	entry[low]=current;//entry[low]为空位
}

void build_heap(int *entry,int low ,int high)
{
	int i;
	int count=high-low+1;
	for(i=count/2-1;i>=0;i--)
		insert_heap(entry,i,high,entry[i]);
}

void heap_sort(int *entry,int count)
{
	int i;
	build_heap(entry,0,count-1);
	int in1;
	for(in1=0;in1<count;in1++)
		cout << entry[in1] << " ";
	cout << endl;
	for(i=0;i<count-1;i++)
	{
		int current=entry[count-i-1];
		entry[count-i-1]=entry[0];
		insert_heap(entry,0,count-i-2,current);
	}
}

int main()
{
	int a[8]={55,63,44,38,75,80,31,56};
	heap_sort(a,8);
	int i;
	for(i=0;i<8;i++)
	{
		cout << a[i] << endl;
	}
	return 0;
}
