#include<iostream>
using namespace std;

#include<stdio.h>
 
char *convertDecimalToHex(int value)
{
 int num;
  int value1=value;
  for(num=0;num<100;num++)
   {
    value1=value1/16;
     if(value1==0)
      break;
   }
	char* aaa=new char[num+2];
	int in1;
	for(in1=num;in1>=0;in1--)
	{
		aaa[in1]=value%16+'0';
		if(aaa[in1]>('0'+9))
		aaa[in1]=aaa[in1]-58+'A';
		value=value/16;
		if(value==0)
			break;
	}
 aaa[num+1]='\0';
	return aaa;
}

void convertDecimalToHex(int value,char *s)
{
   int num;
  int value1=value;
  for(num=0;num<100;num++)
   {
    value1=value1/16;
     if(value1==0)
      break;
   }
   	int in1;
	for(in1=num;in1>=0;in1--)
	{
		s[in1]=value%16+'0';
		value=value/16;
		if(s[in1]>'0'+9)
		s[in1]=s[in1]-58+'A';
		if(value==0)
			break;
	}
    s[num+1]='\0';
}

int main()
{
	char *aaa=convertDecimalToHex(161);
	char bbb[100];
	convertDecimalToHex(161,bbb);
	printf("%d\n",'0');
	cout << aaa << endl;
	cout << bbb << endl;
	delete []aaa;
	return 0;
}
