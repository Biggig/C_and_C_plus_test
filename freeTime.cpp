#include"freeTime.h"

#include<sstream>

stdTime::stdTime()
{
	year=2000;
	month=1;
	day=1;
	hour=0;
	minute=0;
	second=0;
}

stdTime::stdTime(int ye,int mon,int da,int ho,int min,int sec)
				:year(ye),month(mon),day(da),hour(ho),minute(min),second(sec)
{
	
}

string stdTime::getDay() 
{
	stringstream bbb;
	bbb << year;
	bbb >> Trueday;
	string aaa;
	bbb << month;
	bbb >> aaa;
	Trueday=Trueday+" "+aaa;
	string ccc;
	bbb << day;
	bbb >> ccc;
	Trueday=Trueday+" "+ccc;
	return Trueday; 
}

string stdTime::getTime() 
{
	stringstream bbb;
	bbb << hour;
	bbb >> ComTime;
	string aaa;
	bbb << minute;
	bbb >> aaa;
	ComTime=ComTime+":"+aaa;
	string ccc;
	bbb << second;
	bbb >> ccc;
	ComTime=ComTime+":"+ccc;
	return ComTime; 	
}

string stdTime::getCompleteTime()
{
	return Trueday+"\n"+ComTime;
} 
