#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
	int num;
	cin >> num;
	int in1;
	for(in1=0;in1<num;in1++)
	{
		string name;
		string code;
		double cost;
		cin >> name;
		cin >> code;
		cin >> cost;
		cout << setw(15) << left << name << setw(15) << left << code << " " ;
		cout << setw(10) << setprecision(2) << fixed << cost << endl;
	}
	return 0; 
} 
