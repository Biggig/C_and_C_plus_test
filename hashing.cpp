#include<iostream>
#include<vector>
#include<list>
#include<string>
using namespace std;

class people
{
	public:
		string name;
		int key;
		people(string name_)
		{
			name=name_;
			key=total++;
		}
	private:
		static int total;	
};//�������ݵĵ�Ԫ 

int people::total=1;

int hashing_fun(string name)
{
	const char* c=name.c_str();
	char value=c[0];
	if(value>='a'&&value<='z')
		return value-'a';
	else if(value>='A'&&value<='Z')
		return value-'A'+26;
	else 
		return 52;		
}//��ϣ���� 

void search_insert(string name_,list<people> &ele)
{
	list<people>::iterator it;
	int counter=0;
	for(it=ele.begin();it!=ele.end();it++)
	{
		if((*it).name==name_)
		{
			counter++;
			cout << name_ << ":" << (*it).key << endl;
			break;
		}
	}
	if(counter!=0)
		return ;
	else
	{
		people aaa(name_);
		ele.push_front(aaa);
		cout << aaa.name << ":" << aaa.key << endl;
		return ;	
	}	
}//����Ƿ��ڸ����У����ڣ�ֱ�������������� 


int main()
{
	vector<list<people>> all(53);
	int in1;
	for(in1=0;in1<53;in1++)
		all[in1].clear();//��ʼ����ϣ��
	int num;//��������
	cin >> num;
	for(in1=0;in1<num;in1++)
	{
		string name;
		cin >> name;
		int add=hashing_fun(name);
		search_insert(name,all[add]);
	}
	return 0;	 
} 
