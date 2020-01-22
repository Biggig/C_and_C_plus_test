#include<iostream>
#include<stack>
#include<string>
using namespace std;


int main()
{
	int num;
	cin >> num;
	while(num!=0)
	{
		num--;
		string in;
		cin >> in;
		const char* all = in.c_str();
		int con = in.size();
		stack<char> out;
		for(int in1=0;in1<con;in1++)
		{
			if(in1==con-1)
			{
				out.push(all[in1]);
				while(!out.empty())
				{
					cout << out.top();
					out.pop();
				}				
			}
			else
			{
				if(all[in1]!='_')
					out.push(all[in1]);
				else
				{
					while(!out.empty())
					{
						cout << out.top();
						out.pop();
					}
					cout << '_';
				}				
			}	
		}
		cout << endl;
	}
	return 0;
}
