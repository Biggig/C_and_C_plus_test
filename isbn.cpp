#include<iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;
	char str[13];
	int in1;
	for(in1=0;in1<num;in1++)
	{
		int in2;
		for(in2=0;in2<11;in2++)
		{
			cin >> str[in2];
		}
		int cou=10;
		int tol=0;
		for(in2=0;in2<11;in2++)
		{
			if(str[in2]>='0'&&str[in2]<='9')
			{
				tol=tol+(str[in2]-'0')*cou;
				cou--; 
			}
		}
		for(in2=0;in2<11;in2++)
		{
			if((in2+tol)%11==0)
			break;
		}
		str[11]='-';
		if(in2==10)
		str[12]='X';
		else
		str[12]='0'+in2; 
		for(in2=0;in2<13;in2++)
		{
			cout << str[in2];
		}
		cout << endl;
	}
	return 0;
} 
