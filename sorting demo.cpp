#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;

int main()
{
	int a[]={1,3,5,6,7,4,3,4,3,2,1,3,5,2,2,1,2,1,2,3,2};
	const int N=sizeof(a)/sizeof(int);
	vector<int> v;
	int i;
	for(i=0;i<N;i++)
		v.push_back(a[i]);
	sort(v.begin(),v.end());
	copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
	cout << endl;
	sort(v.begin(),v.end(),greater<int>());
	copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
	return 0;	
} 
