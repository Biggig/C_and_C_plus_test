#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

void shell_once(vector<int> &v,int increment)
{
	int num=v.size();
	vector<int> index;
	int in1=0;
	for(in1=0;in1<increment;in1++)
	{
		for(int in2=in1;in2<num;in2=in2+increment)
		{
			index.push_back(in2);//索引 
		}
		vector<int>::iterator it;
		vector<int> partial;
		for(it=index.begin();it!=index.end();it++)
		{
			partial.push_back(v[*it]);
		}
		stable_sort(partial.begin(),partial.end());//部分排序 
		int counter=0;
		for(it=index.begin();it!=index.end();it++)
		{
			v[*it]=partial[counter];//重新赋值 
			counter++;
		}
		index.clear();
		partial.clear(); 
	}
} 

int main()
{
	vector<int> v;
	int in1;
	for(in1=10;in1>=0;in1--)
		v.push_back(in1);
	shell_once(v,4);
	copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
	return 0;	
}
