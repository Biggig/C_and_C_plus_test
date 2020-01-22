#include<iostream>
#include<cstring>
using namespace std;

#include<stdio.h>

int main()
{
	char str[100];	
	scanf("%s",str);    
	int num=strlen(str);
	do
	{
	    int in1;
	    if(num==1&&str[0]=='x')
	    {
	    	break;
		}
	    for(in1=0;in1<num;in1++)
	    {
	    	if((str[in1]<'0'||str[in1]>'9')&&str[in1+1]!='0')
	    	cout << str[in1];
	    	else if(str[in1+1]=='0')
	    	in1++;
	    	else 
	    	{
	    		int num1=0;
	    		int last=in1-1;
	    		int now=in1;
	    		do
	    		{
	    			num1=num1*10+str[now]-'0';
	    			now++;
				}while(str[now]>='0'&&str[now]<='9');
				int in2=0;
				for(in2=0;in2<num1-1;in2++)
				cout << str[last];
				in1=now-1;
			}
		}
		cout << endl;	
	    scanf("%s",str);    
	    num=strlen(str);
	}while(num!=1||str[0]!='x'); 
	return 0;	
}
