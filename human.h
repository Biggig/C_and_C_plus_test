#ifndef HUMAN_H
#define HUMAN_H

#include"animal.h"

class human:public animal
{
	public:
		human();
		human(string name);
		void greeting() const;
	private:
	    string _name;	
};

human::human()
{
	_eyes=2;
	_species="Human";
}

human::human(string name)
{
	_name=name;
	_eyes=2;
	_species="Human";
}

void human::greeting() const
{
	cout << "Hello, I'm " << _name << "." << endl;
}

#endif
