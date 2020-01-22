#include<iostream>
using namespace std;

int main()
{
	int m,n;
	cin >> m >> n;
	int *num=new int[m+n];
	int in1;
	for(in1=0;in1<m+n;in1++)
	{
		cin >> num[in1];
	}
	int exchange;
	int in2;
	for(in1=0;in1<m+n-1;in1++)
	{
		for(in2=0;in2<m+n-1;in2++)
		{
			if(num[in2]>num[in2+1])
			{
				exchange=num[in2];
				num[in2]=num[in2+1];
				num[in2+1]=exchange;
			} 
		}
	}
	for(in1=0;in1<m+n;in1++)
	{
		cout << num[in1] << " ";
	}
	cout << endl;
	delete []num;
	return 0;
} 
