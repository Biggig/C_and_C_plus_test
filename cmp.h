#include<string>
using namespace std;
#include<string.h>
 
template <class T>
bool cmp(T aaa,T bbb)
{
	if(aaa==bbb)
	return true;
	else
	return false;
}

template <>
bool cmp(int* aaa,int* bbb)
{
	if(*aaa==*bbb)
	return true;
	else
	return false;
}

template <>
bool cmp(float* aaa,float* bbb)
{
	if(*aaa==*bbb)
	return true;
	else
	return false;
}

template <>
bool cmp(double* aaa, double* bbb)
{
	if(*aaa==*bbb)
	return true;
	else
	return false;
}

template <>
bool cmp(const char* aaa,const char* bbb)
{
	int numa=strlen(aaa);
	int numb=strlen(bbb);
	if(numa=numb)
	{
		int in1;
		int counter=0;
		for(in1=0;in1<numa;in1++)
		{
			if(aaa[in1]==bbb[in1])
			counter++;
		}
		if(counter==numa)
		return true;
		else
		return false;
	}
	else
	return false;
}
