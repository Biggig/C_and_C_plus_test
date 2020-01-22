#include"Myinteger.h"

#include<sstream>
#include<string>
using namespace std;

#include<stdlib.h>



MyInteger::MyInteger(int aaa)
{
	value=aaa;
}

int MyInteger::getValue() const
{
	return value;
}

bool MyInteger::isEven() const
{
	if(value%2==0)
	return true;
	else
	return false;
}

bool MyInteger::isOdd() const
{
	if(value%2!=0)
	return true;
	else
	return false;
}

bool MyInteger::isPrime() const
{
	int in1;
	for(in1=2;in1<value;in1++)
	{
		if(value%in1==0)
		break;
	}
	if(value==in1)
	return true;
	else
	return false;
}

bool MyInteger::isEven(int aaa)
{
	if(aaa%2==0)
	return true;
	else
	return false;
}

bool MyInteger::isOdd(int aaa)
{
	if(aaa%2!=0)
	return true;
	else
	return false;
}

bool MyInteger::isPrime(int aaa)
{
	int in1;
	for(in1=2;in1<aaa;in1++)
	{
		if(aaa%in1==0)
		break;
	}
	if(aaa==in1)
	return true;
	else
	return false;
}

bool MyInteger::isEven(const MyInteger& aaa)
{
	if(aaa.getValue()%2==0)
	return true;
	else
	return false;
}

bool MyInteger::isOdd(const MyInteger& aaa)
{
	if(aaa.getValue()%2!=0)
	return true;
	else
	return false;
}

bool MyInteger::isPrime(const MyInteger& aaa)
{
	int in1;
	for(in1=2;in1<aaa.getValue();in1++)
	{
		if(aaa.getValue()%in1==0)
		break;
	}
	if(aaa.getValue()==in1)
	return true;
	else
	return false;
}

bool MyInteger::equals(int aaa)
{
	if(aaa==value)
	return true;
	else
	return false;
}

bool MyInteger::equals(const MyInteger& aaa)
{
	if(aaa.getValue()==value)
	return true;
	else
	return false;
}

int MyInteger::parseInt(const string& aaa)
{
	int bbb;
	
	bbb=atoi(aaa.c_str());
	return bbb;
}

