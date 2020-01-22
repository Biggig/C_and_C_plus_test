#include"Bitset.h"
#include<math.h>

bitset::bitset()
{
	int in1;
	for(in1=0;in1<N;in1++)
	{
		a[in1]=0;
	}
}

void bitset::set(int pos)
{
	int aaa=pos/32;
	int bbb=pos%32;
	a[aaa]=a[aaa]|(1<<bbb);	
}

void bitset::reset(int pos)
{
	int aaa=pos/32;
	int bbb=pos%32;
	int ccc=pow(2,bbb);
	a[aaa]=a[aaa]&(~ccc);	
}

int bitset::count() const
{
	int num=0;
	int in1;
	for(in1=0;in1<max_length;in1++)
	{
		if(this->test(in1))
		num++;
	}
	return num;
}

bool bitset::test(int pos) const
{
	int in1;
	int aaa=pos/32;
	int bbb=pos%32;
	int ccc=pow(2,bbb);
	if(a[aaa]&ccc)
	return true;
	else
	return false;
}

bool bitset::any() const//ÊÇ·ñÓĞ1 
{
	int in1;
	int counter=0;
	for(in1=0;in1<5;in1++)
	{
		if(a[in1]!=0)
		counter++;
	}
	if(counter!=0)
	return true;
	else
	return false;
}

bool bitset::none() const
{
	int in1;
	int counter=0;
	for(in1=0;in1<5;in1++)
	{
		if(a[in1]!=0)
		counter++;
	}
	if(counter!=0)
	return false;
	else
	return true;	
}

bool bitset::all() const
{
	int in1;
	int check=~0;
	int counter=0;
	for(in1=0;in1<N;in1++)
	{
		if(a[in1]==check)
		counter++;
	}
	if(counter==N)
	return true;
	else
	return false;
}

bitset& bitset::operator&=(const bitset& b)
{
	int in1;
	for(in1=0;in1<5;in1++)
	{
		a[in1]=a[in1]&b.a[in1];
	}
	return *this;
}

bitset& bitset::operator|=(const bitset& b)
{
	int in1;
	for(in1=0;in1<5;in1++)
	{
		a[in1]=a[in1]|b.a[in1];
	}
	return *this;
}

bitset& bitset::operator^=(const bitset& b)
{
	int in1;
	for(in1=0;in1<5;in1++)
	{
		a[in1]=a[in1]^b.a[in1];
	}
	return *this;
}

bitset& bitset::operator=(const bitset& b)
{
	int in1;
	for(in1=0;in1<5;in1++)
	{
		this->a[in1]=b.a[in1];
	}
	return *this;
}

bitset bitset::operator~() const
{
	bitset bbb;
	int in1;
	for(in1=0;in1<5;in1++)
	{
		bbb.a[in1]=~a[in1]; 
	}
	return bbb;
}

bitset bitset::operator&(const bitset& b) const
{
	int in1;
	bitset c;
	for(in1=0;in1<5;in1++)
	{
		c.a[in1]=a[in1]&b.a[in1];
	}
	return c;
}

bitset bitset::operator|(const bitset& b) const
{
	int in1;
	bitset c;
	for(in1=0;in1<5;in1++)
	{
		c.a[in1]=a[in1]|b.a[in1];
	}
	return c;
}

bitset bitset::operator^(const bitset& b) const
{
	int in1;
	bitset c;
	for(in1=0;in1<5;in1++)
	{
		c.a[in1]=a[in1]^b.a[in1];
	}
	return c;
}

bool bitset::operator==(const bitset& b) const
{
	int in1;
	int counter=0;
	for(in1=0;in1<5;in1++)
	{
		if(a[in1]!=b.a[in1])
		counter++;
	}
	if(counter!=0)
	return false;
	else
	return true;
}

bool bitset::operator!=(const bitset& b) const
{
	int in1;
	int counter=0;
	for(in1=0;in1<5;in1++)
	{
		if(a[in1]!=b.a[in1])
		counter++;
	}
	if(counter==0)
	return false;
	else
	return true;
}

bool bitset::operator[] (int pos) const
{
	return test(pos);
}

bitset& bitset::operator <<= (int pos)
{
	int in1;
	for(in1=max_length-1;in1>=pos;in1--)
	{
		if(this->test(in1-pos))
		this->set(in1);
		else
		this->reset(in1);
	}
	for(in1=0;in1<pos;in1++)
	this->reset(in1);
	return *this;
}

bitset bitset::operator<<(int pos) const
{
	bitset aaa;
	int in1;
	for(in1=0;in1<N;in1++)
	aaa.a[in1]=a[in1];
	aaa <<=pos;
	return aaa;
}

bitset& bitset::operator >>=(int pos)
{
	int in1;
	bitset aaa;
	for(in1=0;in1<N;in1++)
	aaa.a[in1]=a[in1];
	for(in1=max_length-1;in1>=pos;in1--)
	{
		if(this->test(in1))
		aaa.set(in1-pos);
		else
		aaa.reset(in1-pos);
	}
	for(in1=max_length-1;in1>max_length-pos;in1--)
	aaa.set(in1);
	for(in1=0;in1<N;in1++)
	a[in1]=aaa.a[in1];
	return *this;
}

bitset bitset::operator>>(int pos) const
{
	bitset aaa;
	int in1;
	for(in1=0;in1<N;in1++)
	aaa.a[in1]=a[in1];
	aaa >>=pos;
	return aaa;	
}
