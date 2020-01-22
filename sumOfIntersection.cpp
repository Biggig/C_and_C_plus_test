#include<set>
using namespace std;

int sumOfIntersection(const set<int>& set1,const set<int>& set2)
{
	set<int>::iterator in1;
	set<int>::iterator in2;
	int counter=0;
	for(in1=set1.begin();in1!=set1.end();in1++)
	{
		for(in2=set2.begin();in2!=set2.end();in2++)
		{
			if(*in1==*in2)
			counter=*in1+counter;
		}
	}
	return counter;
}
