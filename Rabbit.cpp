#include<iostream>
#include<cmath>
using namespace std;

int counting(int d,int m)
{
	if(d<=m)
	return d+1;
	else
	return counting(d-1,m)+counting(d-m,m);	
}

int main()
{
	int mmm,ddd;
	cin >> mmm >> ddd; 
	while(mmm!=0||ddd!=0)
	{
		int num=0;
		if(mmm==1)
		num=pow(2,ddd);
		else
		{
			num=counting(ddd,mmm);
		}
		cout << num << endl;
		cin >> mmm >> ddd;
	}
	return 0; 
}
