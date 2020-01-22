#ifndef _FACTORY_H_
#define _FACTORY_H_

#include<iostream>
using namespace std;

#include"Product.hpp" 

class Factory
{
	public:
		Factory(){}
		virtual ~Factory(){}
		virtual Laptop* produceLaptop()=0;
		virtual MobilePhone* produceMobilePhone()=0;	
};

class AppleFactory:public Factory
{
	public:
		AppleFactory(){}
		~AppleFactory(){
		}
		Laptop* produceLaptop()
		{
			return new AppleLaptop;
		}
		MobilePhone* produceMobilePhone()
		{
			return new AppleMobilePhone;
		}
};

class XiaomiFactory:public Factory
{
	public:
		XiaomiFactory(){}
		~XiaomiFactory(){}
		Laptop* produceLaptop()
		{
			return new XiaomiLaptop;
		}
		MobilePhone* produceMobilePhone()
		{
			return new XiaomiMobilePhone;
		}
};

#endif
