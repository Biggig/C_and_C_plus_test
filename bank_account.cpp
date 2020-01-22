// Problem#: 21097
// Submission#: 5199095
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>
using namespace std;

int search(string str)
{
    const char* s=str.c_str();
    int in1;
    int counter=0;
    for(in1=0;in1<str.size();in1++)
    {
        if(s[in1]==',')
            counter++;
        if(counter==3)
            break;  
    }
    return in1+1;
}

int main()
{
    string in;
    vector<string> str;
    getline(cin,in);
    while(getline(cin,in))
    {   
        str.push_back(in);
    }
    stable_sort(str.begin(),str.end());//对操作已经排序 
    vector<string>::iterator it;
    string id=(*(str.begin())).substr(0,10);
    int money=0;
    for(it=str.begin();it!=str.end();it++)
    {
        string copy=(*it);
        string is=copy.substr(0,10);
        if(id==is)//仍是对同一账户进行操作 
        {
            string action=copy.substr(22,1);
            int loca=search(copy);
            string numb=copy.erase(0,loca);
            const char* c=numb.c_str();
            int mon=atoi(c);
            if(action=="w")
                money=money-mon;
            else if(action=="d")
                money=money+mon;
            cout << (*it) << endl;      
        }
        else//对不同账户进行操作 
        {
            cout << "Total:" << money << endl;
            money=0;
            id=is;
            string action=copy.substr(22,1);
            int loca=search(copy);
            string numb=copy.erase(0,loca);
            const char* c=numb.c_str();
            int mon=atoi(c);
            if(action=="w")
                money=money-mon;
            else if(action=="d")
                money=money+mon;
            cout << (*it) << endl; 
        }
        if(it==str.end()-1)
            cout << "Total:" << money << endl;
    } 
    return 0;
}                                 
