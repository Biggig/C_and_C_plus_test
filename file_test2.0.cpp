#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

void retrieve(vector<pair<string,int>> &all,string ele)//遍历已储存的string，若已存在，数量加一，否则，创建新的pair并加入到vector中 
{
	vector<pair<string,int>>::iterator it;
	for(it=all.begin();it!=all.end();it++)
	{
		if(it->first==ele)
		{
			it->second++;
			return;
		}
	}
	all.push_back(make_pair(ele,1));
	return;
} 

void check(string &str)//检查字符串的最后一位是否为标点符号，若是，删除该位 
{
	if(*(str.rbegin())>'z'||*(str.rbegin())<'a')
		str=str.substr(0,str.length()-1);
}

bool compare(pair<string,int> no, pair<string,int> na)//比较函数 
{
	return no.first<na.first;
} 


int main()
{
	string count;//输入命令 
	cin >> count;
	if(count!="count")
	{
		cout << "Wrong order!" << endl;
		return 0;
	}
	
	string in_name;
	cin >> in_name;//输入文件名 
	ifstream inputF(in_name);//创建输入文件
	while(!inputF)
	{
		cerr << "open error for inputFile!" << endl;
		exit(1);
	}
	
	
	string out_name;
	cin >> out_name;//输出文件名 
	ofstream outputF(out_name);//创建输出文件 
	while(!outputF)
	{
		cerr << "open error for outputFile!" << endl;
		exit(1);
	}
		
	string str;
	vector<pair<string,int> > all;//储存字符串及其出现的次数 
	
	while(inputF >> str)//将输入文本中的字符串输入
	{
		check(str);
		retrieve(all,str);
	}	
	
	sort(all.begin(),all.end(),compare);//排序 
	
	vector<pair<string,int>>::iterator it;
	for(it=all.begin();it!=all.end();it++)
	{
		outputF << left << setw(15) << it->first << " " << it->second << "\n";//输出到输出文件 
	}
	
	outputF.close();
	inputF.close();
	return 0;
}
