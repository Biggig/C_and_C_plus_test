#include<iostream>
#include<string>
using namespace std;

int main()
{	
	string input;
	while(getline(cin,input))
	{	
		const char* add=input.c_str();
		int num=input.size();
		int counter=10;
		int in1;
		int tol=0;
		for(in1=0;in1<num;in1++)
		{
			if(add[in1]>='0'&&add[in1]<='9')
			{
				tol=tol+(add[in1]-'0')*counter;
				counter--;
			}
			if(counter<2)
				break;
		}
		int in2=0;
		char output;
		for(in2=0;in2<11;in2++)
		{
			if((in2+tol)%11==0)
			{
				if(in2==10)
					output='X';
				else
					output='0'+in2;	
			}
		}
		cout << input << '-' << output << endl;
	}
	return 0;
}
