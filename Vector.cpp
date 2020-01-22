#include"Vector.h"
#include<iostream>
using namespace std;

Vector::Vector(string name_,int dim,int* par)
{
	name=name_;
	dimension=dim;
	param=new int[dimension];
	int in1;
	for(in1=0;in1<dimension;in1++)
	{
		param[in1]=par[in1];
	}
	cout << "construct a vector called " << name << "." << endl;
}

Vector::Vector(const Vector& other)
{
	name=other.name;
	dimension=other.dimension;
	param=new int[dimension];
	int in1;
	for(in1=0;in1<dimension;in1++)
	{
		param[in1]=other.param[in1];
	}
	cout << "copy a vector called " << name << "." << endl;	
}

Vector::~Vector()
{
	cout << "release memory from a vector called " << name << "." << endl;
	name.clear();
	dimension=0;
	if(param!=NULL)
	{
		delete []param;
		param=NULL;
	}
}

void Vector::isEqual(const Vector& other)
{
	if(name==other.name)
	{
		cout << "same name, ";
	}
	else
	{
		cout << "different name, ";
	}
	if(dimension==other.dimension)
	{
		int in1;
		int counter=0;
		for(in1=0;in1<dimension;in1++)
		{
			if(param[in1]==other.param[in1])
			counter++;
		}
		if(counter==dimension)
		cout << "same value." << endl;
		else
		cout << "different value." << endl; 
	}
	else
	{
		cout << "different value." << endl;
	}
}

void Vector::setName(string name_)
{
	name=name_;
}

void Vector::print()
{
	cout << name << "(";
	int in1;
	for(in1=0;in1<dimension;in1++)
	{
		if(in1!=dimension-1)
		cout << param[in1] << "," << " ";
		else
		cout << param[in1] << ")" << endl;
	}
}
