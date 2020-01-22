#ifndef BANK_SERVICE_H
#define BANK_SERVICE_H

#include<queue>
#include<iostream>
#include<random>
#include<iomanip>
using namespace std;

/*#include<stdlib.h>
#include<math.h>
#include<time.h>*/

//����������ˣ����ڷ����������ʱ��������ĸ����ڴ��ڿ��У����˾�ǰ���ĸ����ڣ�������ʱ�����㣬ϵͳֹͣ����
 
enum status{working=1,idle};//��������״̬ 

class people
{
	public:
		people();//��ʼ������ 
		int getNum() const;//�õ����˱�� 
	private:
		int privateNum;
		static int numberOfCus;
}; 



class window//������ 
{
	public:
		window();//��ʼ������ 
		void changeCus(int newCus);//���˱��
		void changeTime(int serviceTime);//����ʱ���� 
		int presentCus();//���ص�ǰ���˱�� 
		status getStatus();//���ص�ǰ״̬ 
		void endService(); //�������� 
		int getTime();//���ط���ǰ��������ʱ�� 
	private:
		int prnCus;//��ǰ���� 
		status window_status;//����״̬	
		int serviceTime;//ÿ�����˵ķ���ʱ��
};


class bank//������ 
{
	public:
		bank(int WT=0);//Ϊ���г�ʼ�� 
		bool isEmpty();
		void ServingCus(window &No);//������������ĳһ���� 
		void addCus();//�¿��˵��� 
		void leftCus();//��ӡ�Ŷ��п������� 
		void check();//�������ڹ������ 
		void arrangeCus();//���ſ��� 
		void cusLeave();//ȷ���Ƿ��п����Ѿ����ҵ�� 
	private:
		queue<people> customers; //�Ŷ��еĿ��� 
		window windows[4];//����
		int tolNum;//���������� 
		int workTime;//���й�����ʱ�� 
};




#endif
