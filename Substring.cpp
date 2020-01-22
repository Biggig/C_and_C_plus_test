#include<iostream>
#include<string>
using namespace std;

int main()
{
	int samples;
	cin >> samples;
	int in1;
	for(in1=0;in1<samples;in1++)
	{
		int num;
		cin >> num;
		string tol[num];
		int in2;
		for(in2=0;in2<num;in2++)
		{
			cin >> tol[in2];
		}
		for(in2=0;in2<num-1;in2++)
		{
			int in3;
			for(in3=in2+1;in3<num;in3++)
			{
				if(tol[in2]>tol[in3])
				{
					string change=tol[in2];
					tol[in2]=tol[in3];
					tol[in3]=change;				
				}
			}
		}
		for(in2=0;in2<num;in2++)
			cout << tol[in2];
		cout << endl;	 
	} 
	return 0;
}
