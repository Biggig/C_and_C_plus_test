 #include"array.hpp"
#include<iostream>
using namespace std;

array::array(size_t aaa)
{
	_size=aaa;
	_data=new int[_size];
}

array::~array()
{
	_size=0;
	if(_data!=NULL)
	{
		delete []_data;
		_data=NULL;
	}
}

array:: size_t array::max_size()
{
	return _size;
}

array::data_type& array::at(const data_type& i)
{
	return _data[i];
}

array::data_type& array::front()
{
	return _data[0];
}

array::data_type& array::back()
{
	return _data[_size-1];
}

array::pointer array::data()
{
	return _data;
}

void array::fill(const data_type& value)
{
	int in1=0;
	for(in1=0;in1<_size;in1++)
	_data[in1]=value;
}

void array::resize(int newSize)
{
	int in1;
	pointer aaa=new int[newSize];
	for(in1=0;in1<_size;in1++)
	aaa[in1]=_data[in1];
	delete []_data;
	_data=aaa;
	aaa=NULL;
	_size=newSize;
}

void array::sort(int from,int to)
{
	int in1;
	for(in1=from;in1<to;in1++)
	{
		int in2;
		for(in2=in1+1;in2<to;in2++)
		{
			int ex;
			if(_data[in1]>_data[in2])
			{
				ex=_data[in1];
				_data[in1]=_data[in2];
				_data[in2]=ex;
			}
		}
	}
}
