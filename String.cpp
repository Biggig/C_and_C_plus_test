#include<cstring>
using namespace std;

#include"String.h"
#include<string.h>
#include<stdlib.h>

int String::length() const
{
	return _length;
}

String::String()
{
	_buff=NULL;
	_length=0;
	_size=0;
}

String::String(const char* aaa)
{
	_length=strlen(aaa);
	_size=sizeof(char)*_length;
	_buff=new char [strlen(aaa)+1];
	strcpy(_buff,aaa);
	_buff[_length]='\0'; 
}

String::String(const String &aaa)
{
	_buff=new char [strlen(aaa._buff)+1];
	_length=aaa._length;
	_size=aaa._size;
	strcpy(_buff,aaa._buff);
	_buff[_length]='\0';
}

String::~String()
{
	if(_buff!=NULL)
	{
		delete []_buff;
		_buff=NULL;
	}	
}

void String::assign(const char* aaa)
{
	_length=strlen(aaa);
	_size=sizeof(char)*_length;
    delete []_buff;
    _buff=NULL; 
  	_buff=new char[strlen(aaa)+1];
  	strcpy(_buff,aaa);
	_buff[_length]='\0';  
}

void String::append(const char &aaa)
{
	if(_buff!=NULL)
	{
	_length++;
	_size=sizeof(char)*_length;	
	char* bbb;
	bbb=new char [_length+1];
	strcpy(bbb,_buff);
	bbb[_length-1]=aaa;
	bbb[_length]='\0';
	delete []_buff;
	_buff=new char [_length+1];
	strcpy(_buff,bbb);
	delete []bbb;
	bbb=NULL;	
	}
	else
	{
		_length++;
		_size=sizeof(char)*_length;
		_buff = new char [_length+1];
		_buff[0] = aaa;
		_buff[1] = '\0';
	}
	
}

void String::clear()
{
	int in1;
	delete []_buff;
	_buff = NULL;
	_length=0;
	_size=0;
}

int String::compare(const String &aaa) const
{
	if(strcmp(_buff,aaa._buff)>0)
		return 1;
	else if(strcmp(_buff,aaa._buff)<0)
		return -1;
	else
		return 0;
}

const char* String::c_str() const
{
	return _buff;
}

bool String::empty() const
{
	if(_length==0)
	return true;
	else
	return false;
}

int String::find(const String &aaa,int pos) const
{
	int cnum=aaa._length;
	int in1;
	for(in1=pos;in1<_length;in1++)
	{
		if(_buff[in1]==aaa._buff[0]&&in1+cnum-1<_length)
		{
		    int counter=0;
	        int in2=0;
			for(in2=0;in2<cnum;in2++)
			{
				if(_buff[in1+in2]==aaa._buff[in2])
					counter++;
			}
			if(counter==cnum)
			break;	
		}		
	}
	return in1;
}

String String::substr(const int &aaa,const int &bbb) const
{
	char *str1=new char[bbb+1];
	int in1=0;
	for(in1=0;in1<bbb;in1++)
	{
		str1[in1]=_buff[in1+aaa];
	}
	str1[bbb]='\0';
    String ccc;
    ccc._buff=new char[bbb+1];
    strcpy(ccc._buff,str1);
    ccc._buff[bbb]='\0';
	ccc._length=bbb;
	ccc._size=sizeof(char)*ccc._length;
	delete []str1;
	str1=NULL;
	return ccc;
}

char& String::operator[](const int &aaa)
{
	return _buff[aaa];
}

void String::operator=(const String &aaa)
{
	_length=aaa._length;
	_size=aaa._size;
	*this=aaa._buff;
}

void String::operator=(const char* aaa)
{
	_length=strlen(aaa);
	_size=sizeof(char)*_length;
	if(_buff!=NULL)
	{
		delete []_buff;
		_buff=NULL;
	}
	_buff=new char [_length+1];
	strcpy(_buff,aaa);
	_buff[_length]='\0';
}

String String::operator+(const String &aaa) const
{
	String bbb;
	bbb._length=_length+aaa._length;
	bbb._buff=new char[bbb._length+1];
	strcpy(bbb._buff,_buff);
	int in1;
	for(in1=0;in1<aaa._length;in1++)
		bbb._buff[in1+_length]=aaa._buff[in1];
	bbb._buff[bbb._length]='\0';
	bbb._size=sizeof(char)*_length;
	return bbb;
}

bool String::operator<(const String &aaa) const
{
	if(strcmp(_buff,aaa._buff)<0)
	return true;
	else
	return false;
}

bool String::operator<=(const String &aaa) const
{
	if(strcmp(_buff,aaa._buff)<=0)
	return true;
	else
	return false;	
}

bool String::operator>(const String &aaa) const
{
	if(strcmp(_buff,aaa._buff)>0)
	return true;
	else
	return false;	
}

bool String::operator>=(const String &aaa) const
{
	if(strcmp(_buff,aaa._buff)>=0)
	return true;
	else
	return false;	
}

bool String::operator==(const String &aaa) const
{
	if(strcmp(_buff,aaa._buff)==0)
	return true;
	else
	return false;	
}

bool String::operator!=(const String &aaa) const
{
	if(strcmp(_buff,aaa._buff)!=0)
	return true;
	else
	return false;	
}

std::ostream& operator<<(std::ostream &aaa,const String &bbb)
{
	if (bbb._buff != NULL)
		aaa << bbb._buff;
	return aaa;
}

char String::_error_sign='y';
