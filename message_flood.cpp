#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n,m;
	cin >> n;
	while(n!=0)
	{
		cin >> m;
		int in1;
		vector<string> friends;
		string fri;
		string message;
		for(in1=0;in1<n;in1++)
		{
			cin >> fri;
			friends.push_back(fri);
		}
		for(in1=0;in1<m;in1++)
		{
			cin >> message;
			vector<string>::iterator is;
			for(is=friends.begin();is!=friends.end();is++)
			{
				if(*is==message)
					friends.erase(is);
			}
		}
		cout << friends.size() << endl;
		friends.clear();
		cin >> n;
	}
	return 0;
} 
