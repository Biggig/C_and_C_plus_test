#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		stack<char> xi;
		stack<char> zh;
		stack<char> da;
		string in;
		cin >> in;
		const char* a=in.c_str();
		int num=in.size();
		for(int in1=0;in1<num;in1++)
		{
			if(a[in1]=='['||a[in1]==']')
			{
				if(zh.empty())
					zh.push(a[in1]);
				else
				{
					if(zh.top()=='['&&a[in1]==']')
						zh.pop();
					else
						zh.push(a[in1]);	
				}	
			}
			else if(a[in1]=='('||a[in1]==')')
			{
				if(xi.empty())
					xi.push(a[in1]);
				else
				{
					if(xi.top()=='('&&a[in1]==')')
						xi.pop();
					else
						xi.push(a[in1]);	
				}				
			}
			else if(a[in1]=='{'||a[in1]=='}')
			{
				if(da.empty())
					da.push(a[in1]);
				else
				{
					if(da.top()=='{'&&a[in1]=='}')
						da.pop();
					else
						da.push(a[in1]);	
				}			
			}
		}
		if(xi.empty()&&zh.empty()&&da.empty())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;	 
	}
	return 0;
}

	
