#include<iostream>
using namespace std;

int main()
{
	int move;
	int finpos;
	cin >> move >> finpos;
	if(finpos==1)
	{
		if(move%3==1)
		cout << 0 << endl;
		if(move%3==2)
		cout << 2 << endl;
		if(move%3==0)
		cout << 1 << endl;
	}
	if(finpos==2)
	{
		if(move%6==1||move%6==0)
		cout << 2 << endl;
		if(move%6==2||move%6==3)
		cout << 0 << endl;
		if(move%6==4||move%6==5)
		cout << 1 << endl;
	}
	else
	{
		if(move%6==1||move%6==2)
		cout << 1 << endl;
		if(move%6==3||move%6==4)
		cout << 2 << endl;
		if(move%6==5||move%6==0)
		cout << 0 << endl;
	}
	return 0;
}
