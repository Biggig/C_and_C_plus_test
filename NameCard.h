#ifndef NAMECARD_H
#define NAMECARD_H

#include<iostream>
#include<string>
#include<vector> 
using namespace std;

class NameCard//名片类 
{
	public:
		NameCard();
		NameCard(string name,string number);
		void enterInform(string name,string number);//输入名片信息 
		string GetName();//返回名片上的姓名 
		string GetNum(); //返回名片上的电话号码 
	private:
		string name;//姓名 
		string number;//电话号码	
};

class ControlNameCard//控制名片的类 
{
	public:
		ControlNameCard();
		int DeleteNameCard(string name);//删除带有该名字的名片 
		void CreateNameCard(string name,string number);//创建名片 
		string SearchNameCard(string name);//根据名字，搜索电话号码 
	private:
		int totalNum;//名片总数 
		vector<NameCard> cards;
};


#endif
