#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int num;
	cin >> num;
	while(num!=0)
	{
		num--;
		int total;
		cin >> total;
		if(total==0)
			continue;
		vector<string> str;
		string nom;
		int in1;
		for(in1=0;in1<total;in1++)
		{
			cin >> nom;
			str.push_back(nom);
		}
		stable_sort(str.begin(),str.end());
		string all=str[0];
		for(in1=1;in1<total;in1++)
			all=all+str[in1];
		cout << all;
		if(num!=0)
			cout << endl;		
	}
	return 0;
} 
