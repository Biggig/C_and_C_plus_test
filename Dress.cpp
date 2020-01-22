#include"Dress.hpp"

Dress::Dress(const string& name_, const int price_)
{
	name=name_;
	price=price_;
}
        
Dress::Dress(const Dress& oth)
{
	name=oth.name;
	price=oth.price;
}

int Dress::getPrice() const
{
	return price;
}

string Dress::getName() const
{
	return name;
}
