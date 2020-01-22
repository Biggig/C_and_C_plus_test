#include "NameCard.h"

NameCard::NameCard()
{
	
}

NameCard::NameCard(string name_,string number_)//构造函数 
{
	enterInform(name_,number_);
}

string NameCard::GetName()//得到名字 
{
	return name;
}

string NameCard::GetNum()//得到电话号码 
{
	return number;
}

void NameCard::enterInform(string name_,string number_)//输入信息 
{
	name=name_;
	number=number_;
}

ControlNameCard::ControlNameCard()//构造函数 
{
	totalNum=0;
}

void ControlNameCard::CreateNameCard(string name_,string number_)//创建NameCard对象，将其加入cards中 
{
	NameCard example;
	example.enterInform(name_,number_);
	cards.push_back(example);
	totalNum++;
}

int ControlNameCard::DeleteNameCard(string name_)//根据名字，删除名片 
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

string ControlNameCard::SearchNameCard(string name_)//根据名字，搜索电话号码 
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
