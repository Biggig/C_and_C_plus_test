#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<iomanip> 
using namespace std; 

void check(string &str)//检查字符串的最后一位是否为标点符号，若是，删除该位 
{
	if(*(str.rbegin())>'z'||*(str.rbegin())<'a')
		str=str.substr(0,str.length()-1);
}

bool compare(pair<string,int> no, pair<string,int> na)//比较函数 
{
	if(no.first!=na.first)
		return no.first<na.first;
	else
		return no.second<na.second;	
} 

bool compare1(string str1,string str2)
{
	return str1<str2;
}

int main()
{
	string order;//输入命令 
	cin >> order;
	if(order!="index")
	{
		cout << "Wrong order!" << endl;
		return 0;
	}
	
	string in_name;//打开输入文件 
	cin >> in_name;
	ifstream inputF(in_name);
	while(!inputF)
	{
		cerr << "open error for inputFile!" << endl;
		exit(1);		
	}
	
	string key_name;//打开key文件 
	cin >> key_name;
	ifstream key(key_name);
	while(!key)
	{
		cerr << "open error for keyFile!" << endl;
		exit(1);		
	}	
		
	string out_name;//打开或创建输出文件 
	cin >> out_name;
	ofstream outputF(out_name);
	while(!outputF)
	{
		cerr << "open error for outputFile!" << endl;
		exit(1);
	}
	
	vector<pair<string,int> > all;//储存字符串及其出现的行数
	vector<string> key_string;//储存key中的字符串
	
	int counter=0; 
	while(inputF)//输入字符串及其行号 
	{
		counter++;
		string line;
		getline(inputF,line);
		istringstream iss(line);
		while(iss)
		{
			string str;
			iss >> str;
			check(str);
			all.push_back(make_pair(str,counter));
		}
	} 
	
	stable_sort(all.begin(),all.end(),compare);//排序 
	
	string word;//输入key文件 
	while(key >> word)
	{
		key_string.push_back(word);
	}
	
	stable_sort(key_string.begin(),key_string.end(),compare1);//将key中的字符串排序
	
	vector<string>::iterator it;//输出到输出文件 
	for(it=key_string.begin();it!=key_string.end();it++)
	{
		outputF << left << setw(15) << *it;
		int counter=0;
		int last=0;
		vector<pair<string,int>>::iterator is;
		for(is=all.begin();is!=all.end();is++)
		{
			if(counter==0&&is->first==*it)
			{
				outputF << is->second;
				last=is->second;
				counter++;
			}	
			else if(counter!=0&&is->first==*it&&is->second!=last)
			{
				outputF << "," << is->second;
				last=is->second;
				counter++;
			}	
		}
		if(counter==0)
			outputF << "This word doesn't appear" << endl;
		else
			outputF << endl;	
	}
	
	key.close(); 
	outputF.close();
	inputF.close();
	return 0;	
} 
