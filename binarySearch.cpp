#include<iostream>
using namespace std;

template<typename T>
int BinarySearch(T array[],int start, int end, T k)
{
	while(start<=end)
	{
		int middle=(start+end)/2;
	    int middleData=array[middle];
	    if(middleData==k)
	    {
	    	start=middle;
	    	break;
		}
		else if(middleData<k)
			start=middle+1;
		else
			end=middle-1;	
	}
	return start;	
}


int main()
{
	int a[8]={1,2,3,4,5,6,7,8,};
	int result=BinarySearch(a,0,7,6);
	if(a[result]==6)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;	 	 
} 
