#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<iomanip> 
using namespace std; 

void check(string &str)//����ַ��������һλ�Ƿ�Ϊ�����ţ����ǣ�ɾ����λ 
{
	if(*(str.rbegin())>'z'||*(str.rbegin())<'a')
		str=str.substr(0,str.length()-1);
}

bool compare(pair<string,int> no, pair<string,int> na)//�ȽϺ��� 
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
	string order;//�������� 
	cin >> order;
	if(order!="index")
	{
		cout << "Wrong order!" << endl;
		return 0;
	}
	
	string in_name;//�������ļ� 
	cin >> in_name;
	ifstream inputF(in_name);
	while(!inputF)
	{
		cerr << "open error for inputFile!" << endl;
		exit(1);		
	}
	
	string key_name;//��key�ļ� 
	cin >> key_name;
	ifstream key(key_name);
	while(!key)
	{
		cerr << "open error for keyFile!" << endl;
		exit(1);		
	}	
		
	string out_name;//�򿪻򴴽�����ļ� 
	cin >> out_name;
	ofstream outputF(out_name);
	while(!outputF)
	{
		cerr << "open error for outputFile!" << endl;
		exit(1);
	}
	
	vector<pair<string,int> > all;//�����ַ���������ֵ�����
	vector<string> key_string;//����key�е��ַ���
	
	int counter=0; 
	while(inputF)//�����ַ��������к� 
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
	
	stable_sort(all.begin(),all.end(),compare);//���� 
	
	string word;//����key�ļ� 
	while(key >> word)
	{
		key_string.push_back(word);
	}
	
	stable_sort(key_string.begin(),key_string.end(),compare1);//��key�е��ַ�������
	
	vector<string>::iterator it;//���������ļ� 
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
