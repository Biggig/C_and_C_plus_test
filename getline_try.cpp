#include<iostream>
#include<sstream>
using namespace std;

int main()
{
	string line;
	getline(cin,line);
	
	istringstream iss(line);
	
	while(iss)
	{
		string str;
		iss >> str;
		cout << str << endl;
	}
	return 0;
 } 
