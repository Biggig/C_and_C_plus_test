#include<iostream>
#include<string>
using namespace std;

class Polynomial
{
	public:
		Polynomial()//默认构造函数 
		{
			numOfDigit=0;
		}
		Polynomial(string plo)//构造函数 ，plo--未处理的多项式的字符串表达 
		{
			getNum(plo);//从字符串中提取数字 
			combinePolynomial();//合并同类项 
			sortTheDigit();//将数据按降幂顺序排列 
			polynomial=turnTheString();//将数字转化为字符串 
		}
		void combinePolynomial();//合并同类项 
		void findPolynomial(Polynomial ele);//查找该字符串是否已存在，ele---要查找的对象 
		string turnTheString();//将数字转化为字符串，返回多项式的字符串表达（已处理） 
		Polynomial polynomialAddition(Polynomial plo);//多项式加法，plo----相加的对象 
		Polynomial polynomialSubtraction(Polynomial plo);//多项式减法，plo----相减的对象
		Polynomial polynomialMultiplitication(int ele);//多项式与常数的乘法，ele----相乘的常数 
		Polynomial derivativeOfPlo(Polynomial plo);//求多项式的导数，plo----需求导的多项式 
		double polynomialValue(double value);//求多项式的值，value----多项式中未知数的值 
		string displayPolynomial();//显示多项式的字符串表达（已处理） 
		void getNum(string plo);//提取多项式中的数字，plo----多项式的字符串表达（未处理） 
		void sortTheDigit();//将多项式中的数字按降幂顺序排列 
		Polynomial& operator=(Polynomial ele);//重载 '='  
		bool comparePolynomial(Polynomial ele); //比较多项式是否相同 
	private:
		string polynomial;//多项式的字符串表达 
		int numOfDigit;//多项式中蕴含的数字的数量 
		int digit[100];	//多项式中蕴含的数字
};



bool validPolynomial(string plo);//判断输入的多项式是否合法，plo----多项式的字符串表达 
void displayOrderList();//打印命令列表 
void exitTheSystem();//退出系统 
void printOutSet();//打印开头 
void disolayAllPolynimal();//显示所有储存的多项式 

