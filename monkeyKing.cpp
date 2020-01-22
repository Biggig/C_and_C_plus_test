#include<vector>
#include<iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;
	for(int in1=0;in1<num;in1++)
	{
		int tol;
		cin >> tol;
		int counter;
		cin >> counter;
		vector<int> monkey;
		int in2;
		for(in2=0;in2<tol;in2++)
		{
			monkey.push_back(in2+1);
		}
		int location=0;
		while(tol!=1)
		{
			vector<int>::iterator it;
			it=monkey.begin();
			location=(location+counter-1)%tol;
			it=it+location;
			monkey.erase(it);
			tol--;	
		}
		cout << monkey.front() << endl;
	}
	return 0;
}
