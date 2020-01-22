#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int in;
	cin >> in;
	while(!cin.eof())
	{
		vector<int> key;
		int co;
		int in1;
		for(in1=0;in1<in;in1++)
		{
			cin >> co;
			key.push_back(co);
		}
		int codnum;
		cin >> codnum;
		vector<int> code;
		for(in1=0;in1<codnum;in1++)
		{
			cin >> co;
			code.push_back(co);
		}
		int start=-1;
		if(in!=0)
		{
			for(in1=0;in1<codnum;in1++)
			{
				if(code[in1]==key[0])
				{
					
					int in2;
					int start_=in1;
					in1++;
					int counter=1;
					for(in2=1;in2<in;in2++)
					{
						if(key[in2]==code[in1])
						{
							counter++;
							in1++;
						}
						else
							break;	
					}
					if(counter==in)
					{
						start=start_;
						break;
					}
				}
			}			
		}
		if(in==0||codnum==0)
			cin >> in;
		else
		{
			if(start==-1)
				cout << "no solution" << endl;
			else
				cout << start << endl;
			cin >> in;
		}
		
	}
	return 0;
}
