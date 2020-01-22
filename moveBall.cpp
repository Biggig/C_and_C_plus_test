#include<iostream>
#include<list>
using namespace std;

int main()
{
	int samples;
	cin >> samples; 
	int i=0;
	while( i<samples)
	{
		i++;
		list<int> balls;
		int num,order;
		cin >> num >> order;
		int in1=0;
		while(in1<num)
		{
			in1++;
			balls.push_back(in1);
		}
		int in2;
		for(in2=0;in2<order;in2++)
		{
			int ord,x,y;
			cin >> ord >> x >> y;
			list<int>::iterator it;
			it=balls.begin();
			while(*it!=x)
			{
				it++;
			}	
			balls.erase(it);
			it=balls.begin();
			while(*it!=y)
			{
				it++;
			}
			if(ord==1)
			{	
				balls.insert(it,x);	
			}
			else
			{
				balls.insert(++it,x);
			}	
		}
		int in3=0;
		while(in3<num)
		{
			cout << balls.front() << " ";
			balls.pop_front();
			in3++;
		}		
		cout << endl;	 
	}
	return 0;	
}
