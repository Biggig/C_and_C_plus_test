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

//随机产生客人，窗口服务客人所需时间随机；哪个窗口处于空闲，客人就前往哪个窗口；当工作时间清零，系统停止运行
 
enum status{working=1,idle};//窗口所处状态 

class people
{
	public:
		people();//初始化客人 
		int getNum() const;//得到客人编号 
	private:
		int privateNum;
		static int numberOfCus;
}; 



class window//窗口类 
{
	public:
		window();//初始化窗口 
		void changeCus(int newCus);//客人变更
		void changeTime(int serviceTime);//服务时间变更 
		int presentCus();//返回当前客人编号 
		status getStatus();//返回当前状态 
		void endService(); //结束服务 
		int getTime();//返回服务当前客人所需时间 
	private:
		int prnCus;//当前客人 
		status window_status;//窗口状态	
		int serviceTime;//每个客人的服务时间
};


class bank//银行类 
{
	public:
		bank(int WT=0);//为银行初始化 
		bool isEmpty();
		void ServingCus(window &No);//将客人引导至某一窗口 
		void addCus();//新客人到来 
		void leftCus();//打印排队中客人人数 
		void check();//检查各窗口工作情况 
		void arrangeCus();//安排客人 
		void cusLeave();//确认是否有客人已经完成业务 
	private:
		queue<people> customers; //排队中的客人 
		window windows[4];//窗口
		int tolNum;//客人总人数 
		int workTime;//银行工作总时间 
};




#endif
