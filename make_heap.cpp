#include<vector>
#include<algorithm>
#include<iterator>
#include<iostream>
using namespace std;

bool compare(int t1,int t2)
{
	return t1>t2;
}

int main()
{
	vector<int> all;
	int in1;
	for(in1=2;in1<13;in1++)
		all.push_back(in1%6);
		
	make_heap(all.begin(),all.end(),compare);
	cout << all.front() << endl;
	copy(all.begin(),all.end(),ostream_iterator<int>(cout," "));
	cout << endl;
	
	pop_heap(all.begin(),all.end(),compare);
	all.pop_back();
	cout << all.front() << endl;
	copy(all.begin(),all.end(),ostream_iterator<int>(cout," "));	
	cout << endl;
	
	pop_heap(all.begin(),all.end(),compare);
	all.pop_back();
	cout << all.front() << endl;
	copy(all.begin(),all.end(),ostream_iterator<int>(cout," "));	
	cout << endl;
	
	pop_heap(all.begin(),all.end(),compare);
	all.pop_back();
	cout << all.front() << endl;
	copy(all.begin(),all.end(),ostream_iterator<int>(cout," "));	
	cout << endl;
	//sort_heap(all.begin(),all.end());	
	//copy(all.begin(),all.end(),ostream_iterator<int>(cout," "));
	return 0;	
}
