#ifndef ANIMAL_H
#define ANIMAL_H

#include<iostream>
using namespace std;

class animal
{
	public:
		animal();
		animal(string,int);
		void print_eyes() const;
	protected:
	    string _species;
		int _eyes;
};

animal::animal()
{
	_eyes=0;
}

animal::animal(string aaa,int bbb)
{
	_species=aaa;
	_eyes=bbb;
}

void animal::print_eyes() const
{
	cout << _species << " has " << _eyes << " eyes." << endl;
} 

#endif
