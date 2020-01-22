#ifndef NAMECARD_H
#define NAMECARD_H

#include<iostream>
#include<string>
#include<vector> 
using namespace std;

class NameCard//��Ƭ�� 
{
	public:
		NameCard();
		NameCard(string name,string number);
		void enterInform(string name,string number);//������Ƭ��Ϣ 
		string GetName();//������Ƭ�ϵ����� 
		string GetNum(); //������Ƭ�ϵĵ绰���� 
	private:
		string name;//���� 
		string number;//�绰����	
};

class ControlNameCard//������Ƭ���� 
{
	public:
		ControlNameCard();
		int DeleteNameCard(string name);//ɾ�����и����ֵ���Ƭ 
		void CreateNameCard(string name,string number);//������Ƭ 
		string SearchNameCard(string name);//�������֣������绰���� 
	private:
		int totalNum;//��Ƭ���� 
		vector<NameCard> cards;
};


#endif
