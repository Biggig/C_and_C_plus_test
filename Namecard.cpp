#include "NameCard.h"

NameCard::NameCard()
{
	
}

NameCard::NameCard(string name_,string number_)//���캯�� 
{
	enterInform(name_,number_);
}

string NameCard::GetName()//�õ����� 
{
	return name;
}

string NameCard::GetNum()//�õ��绰���� 
{
	return number;
}

void NameCard::enterInform(string name_,string number_)//������Ϣ 
{
	name=name_;
	number=number_;
}

ControlNameCard::ControlNameCard()//���캯�� 
{
	totalNum=0;
}

void ControlNameCard::CreateNameCard(string name_,string number_)//����NameCard���󣬽������cards�� 
{
	NameCard example;
	example.enterInform(name_,number_);
	cards.push_back(example);
	totalNum++;
}

int ControlNameCard::DeleteNameCard(string name_)//�������֣�ɾ����Ƭ 
{
	vector<NameCard>::iterator it;
	int counter=0;
	for(it=cards.begin();it!=cards.end();)
	{
		if(it->GetName()==name_)
		{
			cards.erase(it);
			totalNum--;
			counter=1;
		} else {
			it++;
		}
	}
	return counter;
}

string ControlNameCard::SearchNameCard(string name_)//�������֣������绰���� 
{
	vector<NameCard>::iterator it;
	int counter=0;
	for(it=cards.begin();it!=cards.end();it++)
	{
		if(it->GetName()==name_)
		{
			counter=1;
			break;
		}
	}
	if(counter==0)
	{
		return "No this person.";
	}
	else
	{
		return it->GetNum();
	}
}
