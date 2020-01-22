#include<string.h>
#include"Set.hpp"

int* Set::getMembers()
{
	return members;
}

int Set::getSize()
{
	return size;
}

Set::Set()
{
	int in1;
	for(in1=0;in1<100;in1++)
	members[in1]=0;
	size=0;
}

Set::Set(int* mmm,int sss)
{
	int in1;
	for(in1=0;in1<100;in1++)
	{
		members[in1]=mmm[in1];
	}
	size=sss;
}

Set::Set(Set const &aaa)
{
	size=aaa.size;
	int in1;
	for(in1=0;in1<size;in1++)
	members[in1]=aaa.members[in1];
}

bool Set::append(int eee)
{
	int in1;
	int counter=0;
	for(in1=0;in1<size;in1++)
	{
		if(members[in1]==eee)
		counter++;
	}
	if(counter!=0)
	return false;
	else
	{
		members[size]=eee;
		size++;
		return true;
	}
}


bool Set::remove(int eee)
{
	int in1;
	int counter=0;
	for(in1=0;in1<size;in1++)
	{
		if(members[in1]==eee)
		{
			counter++;
			break;
		}
	}
	if(counter==0)
	return false;
	else
	{
		members[in1]=members[size-1];
		members[size-1]=0;
		size--;
		return true;
	}
}

bool Set::isEmptySet()
{
	int in1;
	int counter=0;
	for(in1=0;in1<size;in1++)
	{
		if(members[in1]==0)
		counter++;
	}
	if(counter==size)
	return true;
	else
	return false;
}

bool Set::isInSet(int eee)
{
	int in1;
	int counter=0;
	for(in1=0;in1<size;in1++)
	{
		if(members[in1]==eee)
		counter++;
	}
	if(counter!=0)
	return true;
	else
	return false;
}

Set Set::operator&(const Set &s)
{
	int in1;
	Set res;
	int in3=0;
	for(in1=0;in1<size;in1++)
	{
		int in2;
		for(in2=0;in2<s.size;in2++)
		{
			if(members[in1]==s.members[in2])
			{
				res.members[in3]=members[in1];
				in3++;
			}
		}
	}
	res.size=in3;
	return res;
}

Set Set::operator|(const Set &s)
{
	int in1;
	Set res;
	for(in1=0;in1<size;in1++)
	{
		res.members[in1]=members[in1];
	}
	res.size=size;
	for(in1=0;in1<s.size;in1++)
	{
		int in2;
		int counter=0;
		for(in2=0;in2<res.size;in2++)
		{
			if(res.members[in2]!=s.members[in1])
			{
				counter++;
			}
		}
		if(counter==res.size)
		{
			res.members[res.size]=s.members[in1];
			res.size++;
		}
	}
	return res;
}

Set Set::operator-(const Set &s)//²¹¼¯ 
{
	Set res;
	int in1;
	int in3=0;
	for(in1=0;in1<size;in1++)
	{
		int in2;
		int counter=0;
		for(in2=0;in2<s.size;in2++)
		{
			if(members[in1]!=s.members[in2])
			counter++;
		}
		if(counter==s.size)
		{
			res.members[in3]=members[in1];
			in3++;
		}
	}
	res.size=in3;
	return res;
}

Set Set::operator+(const Set &s)
{
	Set aaa=*this|s;
	Set bbb=*this&s;
	Set ccc=aaa-bbb;
	return ccc;
}
