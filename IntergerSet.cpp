#include"IntegerSet.h"

void IntegerSet::emptySet()
{
	int in1;
	for(in1=0;in1<101;in1++)
	set[in1]=0;	
}

IntegerSet::IntegerSet(int s[],int l)
{
	emptySet();
	int in1;
	for(in1=0;in1<l;in1++)
	{
		if(s[in1]>=0&&s[in1]<=100)
		set[s[in1]]=1;
		else
		cout << "Invalid insert attempted!" << endl;
	}
}

IntegerSet IntegerSet::unionOfSets(const IntegerSet& aaa)
{
	IntegerSet bbb;
	int in1;
	for(in1=0;in1<101;in1++)
	{
		if(aaa.set[in1]==1||set[in1]==1)
		bbb.set[in1]=1;	
	}
	return bbb;
}

IntegerSet IntegerSet::intersectionOfSets(const IntegerSet& aaa)
{
	IntegerSet bbb;
	int in1;
	for(in1=0;in1<101;in1++)
	{
		if(aaa.set[in1]==1&&set[in1]==1)
		bbb.set[in1]=1;
	}
	return bbb;
}

void IntegerSet::insertElement(int ele)
{
	if(ele<0||ele>100)
	{
		cout << "Invalid insert attempted!" << endl;
	}
	else
	set[ele]=1;
}

void IntegerSet::deleteElement(int ele)
{
	if(ele<0||ele>100)
	{
		cout << "Invalid delete attempted!" << endl;
	}
	else
	set[ele]=0;
}

bool IntegerSet::isEqualTo(const IntegerSet& aaa)const
{
	int in1;
	int counter=0;
	for(in1=0;in1<101;in1++)
	{
		if(set[in1]!=aaa.set[in1])
		counter++;
	}
	if(counter==0)
	return true;
	else
	return false;
}
