#include<stack>
#include<iostream>
using namespace std;

int main()
{
	stack<char> input;
	char element;
	cin >> element;
	while(element!='a')
	{
		if(input.empty())
			input.push(element);
		else
		{
			if(input.top()=='{'&&element=='}')
				input.pop();
			else if(input.top()=='['&&element==']')
				input.pop();
			else if(input.top()=='('&&element==')')
				input.pop();		
			else
				input.push(element);	 
		}
		cin >> element;	
	}
	if(input.empty())
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	while(!input.empty())
	{
		cout << input.top() << " ";
		input.pop();
	}
	cout << endl;	
	return 0;	 	
} 
