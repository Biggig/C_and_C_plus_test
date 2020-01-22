#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef int Comparable;

Comparable find_median(const vector<Comparable> &l1, const vector<Comparable> &l2)
{
	vector<Comparable> all;
	vector<Comparable>::const_iterator is;
	for(is=l1.begin();is!=l1.end();is++)
		all.push_back(*is);
	for(is=l2.begin();is!=l2.end();is++)
		all.push_back(*is);
	stable_sort(all.begin(),all.end());
	int num=l1.size()+l2.size();
	if(num%2==0)
		return all[num/2-1];
	else
		return all[num/2];			 
}

int main()
{
	int in1;
	vector<int> l1,l2;
	for(in1=0;in1<5;in1++)
	{
		l1.push_back(in1+2);
		l2.push_back(in1+3);
	}
	cout << find_median(l1,l2) << endl;
	return 0;
}
