#include"Biginteger.h"
#include<cstring>
using namespace std;

BigInteger::BigInteger()
{
	data_=NULL;
	size_=0;
}

BigInteger::BigInteger(const string& number)
{
	char* aaa=new char[number.length()+1];
	strcpy(aaa,number.c_str());
	int num=strlen(aaa);
	int in1;
	data_=new int[num];
	size_=num;
	for(in1=0;in1<num;in1++)
	{
		data_[in1]=aaa[in1]-48;
	}
	delete []aaa;
}

BigInteger::BigInteger(const BigInteger& aaa)
{
	size_=aaa.size_;
	data_=new int[size_];
	int in1;
	for(in1=0;in1<size_;in1++)
	{
		data_[in1]=aaa.data_[in1];
	}
}

BigInteger::~BigInteger()
{
	if(data_!=NULL)
	{
		delete []data_;
		data_=NULL;
	}
	size_=0;
}

BigInteger operator+(const BigInteger& left,const BigInteger& right)
{
	int max,min;
	int* lon;
	int* sho;
	if(left.size_>right.size_)
	{
		max=left.size_;
		lon=left.data_;
		min=right.size_;
		sho=right.data_;
	}
	else
	{
		max=right.size_;
		lon=right.data_;
		min=left.size_;
		sho=left.data_;
	}
	BigInteger res;
	res.data_=new int[max];
	res.size_=max;
	int in1;
	for(in1=0;in1<max;in1++)
	res.data_[in1]=0;
	for(in1=0;in1<min;in1++)
	{
		if(res.data_[max-1-in1]+lon[max-1-in1]+sho[min-1-in1]>9)
		res.data_[max-2-in1]=res.data_[max-2-in1]+(res.data_[max-1-in1]+lon[max-1-in1]+sho[min-1-in1])/10;
		res.data_[max-1-in1]=(res.data_[max-1-in1]+lon[max-1-in1]+sho[min-1-in1])%10;

	}
	for(in1=max-min-1;in1>=0;in1--)
	{
		if(res.data_[in1]+lon[in1]>9)
		res.data_[in1-1]++;
		res.data_[in1]=(res.data_[in1]+lon[in1])%10;
	}
	return res;
}

BigInteger operator-(const BigInteger& left,const BigInteger& right)
{
	int max=left.size_;
	int min=right.size_;
	BigInteger res;
	int* lon=new int[max];
	int* sho=new int[min];
	res.data_=new int[max];
	res.size_=max;
	int in1;
	for(in1=0;in1<max;in1++)
	res.data_[in1]=0;
	for(in1=0;in1<max;in1++)
	lon[in1]=left.data_[in1];
	for(in1=0;in1<min;in1++)
	sho[in1]=right.data_[in1];
	for(in1=0;in1<min;in1++)
	{
		if(lon[max-1-in1]-sho[min-1-in1]<0)
		{
			lon[max-2-in1]--;
			lon[max-1-in1]+=10;
		}
		res.data_[max-1-in1]=lon[max-1-in1]-sho[min-1-in1];
	}
	for(in1=max-min-1;in1>=0;in1--)
	{
		if(lon[in1]-res.data_[in1]<0)
		{
			lon[in1-1]--;
			lon[in1]+=10;
		}
		res.data_[in1]=lon[in1]-res.data_[in1];
	}
	delete []lon;
	delete []sho;
	return res;
}

ostream& operator<<(ostream& out,const BigInteger& Bint)
{
	int in1;
	for(in1=0;in1<Bint.size_;in1++)
	{
		if(Bint.data_[in1]==0)
		{
			int in2;
			int counter=0;
			for(in2=0;in2<=in1;in2++)
			{
				if(Bint.data_[in2]==0)
				counter++;
			}
			if(counter==in1+1)
			continue;
			else
			cout << Bint.data_[in1];
		}
		else
		out << Bint.data_[in1];
	}	
	return out;
}
