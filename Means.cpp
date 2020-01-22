#include<iostream>
using namespace std;

double mean()
{
	int num;
	cin >> num;
	int value[num];
	double pro;
	double mean=0;
	int in1;
	for(in1=0;in1<num;in1++)
	{
		cin >> value[in1];
	}
	for(in1=0;in1<num;in1++)
	{
		cin >> pro;
		mean=mean+pro*value[in1];
	}
	return mean;
}

int main()
{
	cout << mean() << endl;
	return 0;
}
