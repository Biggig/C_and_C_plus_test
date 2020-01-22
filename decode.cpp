#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	string input;
	cin >> input;
	while(input!="XXX")
	{
		const char* in=input.c_str();
		stack<char> x;
		int num=input.size();
		int in1;
		for(in1=num-1;in1>=0;in1--)
		{
			x.push(in[in1]);
		}
		char head=x.top();
		x.pop();
		int count=0;
		if(x.empty())//只有一个字母 
			cout << head;
		while(!x.empty())
		{
			if(x.top()>='0'&&x.top()<='9')//有数字 
			{
				count=count*10+x.top()-'0';
				x.pop();
				if(x.empty())//以数字结尾 
				{
					int in2;
					for(in2=0;in2<count;in2++)
						cout << head;
				}
			}
			else
			{
				if(count==0)//字母紧跟字母 
				{
					cout << head;
					head=x.top();
					x.pop();
					if(x.empty())//字母结尾 
						cout << head; 
				}
				else
				{
					int in2;
					for(in2=0;in2<count;in2++)
					{
						cout << head;
					}
					head=x.top();
					x.pop();
					count=0;
					if(x.empty())//字母结尾 
						cout << head;
				} 
			}
		}
		cout << endl;
		cin >> input;
	}
	return 0;
}
