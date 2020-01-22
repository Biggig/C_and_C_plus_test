#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

void retrieve(vector<pair<string,int>> &all,string ele)//�����Ѵ����string�����Ѵ��ڣ�������һ�����򣬴����µ�pair�����뵽vector�� 
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

void check(string &str)//����ַ��������һλ�Ƿ�Ϊ�����ţ����ǣ�ɾ����λ 
{
	if(*(str.rbegin())>'z'||*(str.rbegin())<'a')
		str=str.substr(0,str.length()-1);
}

bool compare(pair<string,int> no, pair<string,int> na)//�ȽϺ��� 
{
	return no.first<na.first;
} 


int main()
{
	string count;//�������� 
	cin >> count;
	if(count!="count")
	{
		cout << "Wrong order!" << endl;
		return 0;
	}
	
	string in_name;
	cin >> in_name;//�����ļ��� 
	ifstream inputF(in_name);//���������ļ�
	while(!inputF)
	{
		cerr << "open error for inputFile!" << endl;
		exit(1);
	}
	
	
	string out_name;
	cin >> out_name;//����ļ��� 
	ofstream outputF(out_name);//��������ļ� 
	while(!outputF)
	{
		cerr << "open error for outputFile!" << endl;
		exit(1);
	}
		
	string str;
	vector<pair<string,int> > all;//�����ַ���������ֵĴ��� 
	
	while(inputF >> str)//�������ı��е��ַ�������
	{
		check(str);
		retrieve(all,str);
	}	
	
	sort(all.begin(),all.end(),compare);//���� 
	
	vector<pair<string,int>>::iterator it;
	for(it=all.begin();it!=all.end();it++)
	{
		outputF << left << setw(15) << it->first << " " << it->second << "\n";//���������ļ� 
	}
	
	outputF.close();
	inputF.close();
	return 0;
}
