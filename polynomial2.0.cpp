#include<iostream>
#include<list>
using namespace std;

struct polynomial
{
	int num;
	list<int> xi;
	list<int> ci;
	polynomial(int num_)
	{
		num=num_;
	}
};

polynomial operator +(polynomial p, polynomial q)
{
	polynomial result(0);
	while(!p.xi.empty()&&!q.xi.empty())
	{
		int maxp=p.ci.front();
		int maxq=q.ci.front();
		if(maxp>maxq)
		{
			if(p.xi.front()!=0)
			{
				result.ci.push_back(maxp);
				result.xi.push_back(p.xi.front());
			}			
			p.ci.pop_front();			
			p.xi.pop_front();
		}
		else if(maxq>maxp)
		{
			if(q.xi.front()!=0)
			{
				result.ci.push_back(maxq);
				result.xi.push_back(q.xi.front());
			}			
			q.ci.pop_front();			
			q.xi.pop_front();			
		}
		else
		{
			if(q.xi.front()+p.xi.front()!=0)
			{
				result.ci.push_back(maxq);
				result.xi.push_back(q.xi.front()+p.xi.front());
			}			
			q.xi.pop_front();
			p.xi.pop_front();			
			q.ci.pop_front();
			p.ci.pop_front();						
		}
	}
	while(!p.xi.empty())
	{
		result.ci.push_back(p.ci.front());
		p.ci.pop_front();
		result.xi.push_back(p.xi.front());
		p.xi.pop_front();		
	}
	while(!q.xi.empty())
	{
		result.ci.push_back(q.ci.front());
		q.ci.pop_front();
		result.xi.push_back(q.xi.front());
		q.xi.pop_front();		
	}
	result.num=result.ci.size();
	return result;	
}

int main()
{
	int num;
	cin >> num;
	while(num--)
	{
		int num_p;
		cin >> num_p;
		polynomial p(num_p);
		int in1;
		int xi,ci;
		for(in1=0;in1<num_p;in1++)
		{
			cin >> xi;
			p.xi.push_back(xi);
			cin >> ci;
			p.ci.push_back(ci);		
		}
		int num_q;
		cin >> num_q;
		polynomial q(num_q);
		for(in1=0;in1<num_q;in1++)
		{
			cin >> xi;
			q.xi.push_back(xi);
			cin >> ci;
			q.ci.push_back(ci);			
		}
		polynomial result=p+q;
		cout << result.num << endl;
		for(in1=0;in1<result.num;in1++)
		{
			cout << result.xi.front() << " ";
			result.xi.pop_front();
			cout << result.ci.front() << endl;
			result.ci.pop_front(); 
		}
	}
	return 0;
}
