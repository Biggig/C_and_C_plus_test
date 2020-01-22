#include<iostream>
#include<string>
#include<cstring>
using namespace std;

#include"user.hpp"
using namespace alipay;
using namespace Gender;

inline bool User::verifyPhoneFormat(const string &aaa)
{
	int num=strlen(aaa.c_str());
	if(num!=13)
	{
		return false; 
	}
	else
	{
		int in1=0;
		int counter=0;
		for(in1=0;in1<num;in1++)
		{
			if(aaa[in1]<'0'||aaa[in1]>'9')
			counter++;
		}
		if(counter!=0)
		return false;
		else
		return true;
	}	
}

inline bool User::verifyUsernameFormat(const string &aaa)
{
	int num=strlen(aaa.c_str());//48 57 65 90 97 122
	if(num<6||num>20)
	{
		return false;
	}
	else
	{
		int in1=0;
		int counter=0;
		for(in1=0;in1<num;in1++)
		{
			if(aaa[in1]<'0'||(aaa[in1]>'9'&&aaa[in1]<'A')||(aaa[in1]>'Z'&&aaa[in1]<'a')||aaa[in1]>'z')
			counter++;
		}
		if(counter!=0)
		return false;
		else
		return true;
	}	
  	
}

inline bool User::verifyPasswordFormat(const string &aaa)
{
	int num=strlen(aaa.c_str());//48 57 65 90 97 122
	if(num<8||num>20)
	{
		return false;
	}
	else
	{
		int in1=0;
		int counter=0;
		for(in1=0;in1<num;in1++)
		{
		    if(aaa[in1]<'0'||(aaa[in1]>'9'&&aaa[in1]<'A')||(aaa[in1]>'Z'&&aaa[in1]<'a')||aaa[in1]>'z')
			counter++;
		}
		if(counter!=0)
		return false;
		else
		return true;
	}    	
}

bool User::setUsername(const char *aaa)
{
    if(this->verifyUsernameFormat(aaa))
	{
		username=aaa;
	  	//strcpy(this->username.c_str(),aaa);
	  	return true;
	}
	else
	return false; 
}

bool User::setPassword(const char *aaa, const char *bbb)
{
	if(this->verifyPasswordFormat(aaa))
	{
		string ccc;
		ccc=bbb;
		if(this->password!=ccc||ccc!="""")
		{
			return false;
		}
		//strcpy(aaa,bbb);
	    else
	    {	
	    	this->password=aaa;
			return true;
		}
	    
	}
	else
	return false;
}

bool User::setPhone(const char *aaa)
{
	if(this->verifyPhoneFormat(aaa))
	{
		this->phone=aaa;
		return true;
	}
	else
	return false;
}

bool User::setGender(Gender::Gender aaa)
{
	if(aaa==2)
	return false;
	else
	{
		this->gender=aaa;
		return true;
	}	
}

alipay::Gender::Gender User::getGender(void)
{
	return this->gender;
}

string User::getUsername()
{
	return username;
}

string User::getPhone()
{
	return phone;
}


long long int User::getMoneyAmount(const char *aaa)
{
	return this->balance;
}

bool User::deposit(long long int aaa)
{
	if(aaa>0)
	{
		balance=balance+aaa;
		return true;
	}
	else
	return false;
}

bool User::withdraw(long long int aaa,const char *bbb)
{
	if(this->password==bbb)
	{
		if(aaa<=balance&&aaa>=0)
		{
			balance=balance-aaa;
			return true;
		}
		else
		return false;
	}
	return false;
}
