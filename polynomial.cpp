#include"polynomial.h"
#include<iostream>
#include<sstream>
using namespace std;

#include<string.h>
#include<math.h>

int numOfPlo=0;
Polynomial allPlo[1000];

void printOutSet()//打印开头 
{
	cout << "Welcome to use this polynomial-solving system!" << endl;	 
}

void exitTheSystem()//退出系统 
{
	exit(0);
}

void displayOrderList()//打印命令列表
{
	cout << "**********************************************" << endl;
	cout << "*This is the list of order:                  *" << endl;
	cout << "*1.Enter the polynomial                      *" << endl;
	cout << "*2.Polynomial addition                       *" << endl;
	cout << "*3.Polynomial subtrction                     *" << endl;
	cout << "*4.Polynomial multiplication                 *" << endl;
	cout << "*5.Calculate the value of polynomial         *" << endl;
	cout << "*6.Display all the polynomials               *" << endl;
	cout << "*7.Compare two polynomials                   *" << endl;
	cout << "*8.Figure out the derivative                 *" << endl;
	cout << "*9.Help(Display the list of order)           *" << endl;
	cout << "*0.Exit the system                           *" << endl;
	cout << "*Ps:If you want to back to the main menu,    *" << endl;
	cout << "*enter 'Back'.                               *" << endl;
	cout << "**********************************************" << endl;
}

bool validPolynomial(string plo)//判断输入的多项式是否合法，plo----多项式的字符串表达
{
	int counter=0;
	int zuokuohao=0;//左括号数量 
	int douhao=0;//逗号数量 
	int youkuohao=0; //右括号数量 
	const char* aaa=plo.c_str();//string转char数组 
	int num=strlen(aaa);
	if(aaa[num-1]!=')') //判断字符串的是否以'）'结尾 
	counter++;
	else
	youkuohao++;
	int in1;
	for(in1=0;in1<num-1;in1++)//判断多项式是否合法 
	{
		
		if(aaa[in1]=='(')
		{
			zuokuohao++;
			if(aaa[in1+1]=='-')
			counter=counter;
			else if(aaa[in1+1]>='0'&&aaa[in1+1]<='9')
			counter=counter;
			else
			counter++;
		}
		else if(aaa[in1]>='0'&&aaa[in1]<='9')
		{
			if(aaa[in1+1]>='0'&&aaa[in1+1]<='9')
			counter=counter;
			else if(aaa[in1+1]==',')
			counter=counter;
			else if(aaa[in1+1]==')')
			counter=counter;
			else
			counter++;
		}
		else if(aaa[in1]==')')
		{
			youkuohao++;
			if(aaa[in1+1]=='(')
			counter=counter;
			else
			counter++;
		}
		else if(aaa[in1]==',')
		{
			douhao++;
			if(aaa[in1+1]>='0'&&aaa[in1+1]<='9')
			counter=counter;
			else
			counter++;
		}
		else if(aaa[in1]=='-')
		{
			if(aaa[in1+1]>='0'&&aaa[in1+1]<='9')
			counter=counter;
			else
			counter++;
		}
		else
		counter++;
	}
	if(zuokuohao!=youkuohao)
	counter++;
	if(zuokuohao!=douhao)
	counter++;
	if(counter==0)
	return true;
	else
	return false;
}

void Polynomial::getNum(string plo)//提取多项式中的数字，plo----多项式的字符串表达（未处理） 
{
	const char* aaa=plo.c_str();
	int num=strlen(aaa);
	int in1;
	int counter=0;
	int numb[100];
	for(in1=0;in1<100;in1++)
	numb[in1]=0;
	for(in1=0;in1<num;in1++)
	{
		if(aaa[in1]=='-')//该数字为负数 
		{
			int in2;
			int digit=0;
			for(in2=in1+1;in2<num;in2++)
			{
				if(aaa[in2]>='0'&&aaa[in2]<='9')
				digit=digit*10+aaa[in2]-'0';
				else
				break;
			}
			numb[counter]=-digit;
			counter++;
			in1=in2;
		}
		if(aaa[in1]>='0'&&aaa[in1]<='9')//数字为正数 
		{
			int in2;
			int digit2=0;
			for(in2=in1;in2<num;in2++)
			{
				if(aaa[in2]>='0'&&aaa[in2]<='9')
				digit2=digit2*10+aaa[in2]-'0';
				else
				break;
			}
			numb[counter]=digit2;
			counter++;
			in1=in2;
		}
	}
	for(in1=0;in1<100;in1++)
	{
		digit[in1]=numb[in1];
	}
	numOfDigit=counter; 
}

void Polynomial::combinePolynomial()//合并同类项 
{
	int copy[100];
	int in1;
	for(in1=0;in1<100;in1++)
	{
		copy[in1]=this->digit[in1];
	}
	for(in1=0;in1<98;in1=in1+2)
	{
		int in2;
		for(in2=in1+2;in2<100;in2=in2+2)
		{
			if(copy[in1+1]==copy[in2+1])//次数相同，合并同类项 
			{
				copy[in1]=copy[in1]+copy[in2];
				copy[in2]=0;
				copy[in2+1]=0;
			}
		} 
	}
	for(in1=0;in1<100;in1=in1+2)
	{
		digit[in1]=copy[in1];
		digit[in1+1]=copy[in1+1];
	}
}

string Polynomial::turnTheString()//转化为字符串 
{
	string total;
	int in1;
	for(in1=0;in1<numOfDigit-1;in1=in1+2)
	{
		string str,str1;
		stringstream st,sr;
		if(digit[in1]!=0)//系数不为零 
		{
			if(digit[in1]==1)//系数为1
			{
				if(digit[in1+1]==0)//次数为0 
				str="1";
				else if(digit[in1+1]==1)//次数为1
				str="x";
				else//次数一般情况 
				{
					st << digit[in1+1];
					st >> str;
					str="x^"+str; 
				} 
			} 
			else if(digit[in1]==-1)//系数为-1
			{
				if(digit[in1+1]==0)//次数为0 
				str="-1";
				else if(digit[in1+1]==1)//次数为1
				str="-x";
				else//一般情况 
				{
					st << digit[in1+1];
					st >> str;
					str="-x^"+str; 
				} 
			} 
			else//系数为一般情况 
			{
				if(digit[in1+1]==0)//次数为0 
				{
					st << digit[in1];
					st >> str;
				}
				else if(digit[in1+1]==1)//次数为1
				{
					st << digit[in1];
					st >> str;
					str=str+"x";
				}
				else//次数一般情况 
				{
					st << digit[in1];
					st >> str;
					sr << digit[in1+1];
					sr >> str1;
					str=str+"x^"+str1; 
				} 	
			}
		}
		else//系数为零 
		{}
		if(in1==0)
		total=str;
		else
		{
			if(digit[in1]>0)
			total=total+"+"+str;
			if(digit[in1]<0)
			total=total+str;
		}			
    }
	return total;
}

string Polynomial::displayPolynomial()//显示多项式 
{
	if(polynomial=="")
	return "0";
	else
	return polynomial;
}

Polynomial Polynomial::polynomialAddition(Polynomial plo)//多项式加法，两多项式已合并同类项 
{
	int copy1[100];
	int copy2[100];
	int in1;
	int numOfCopy=numOfDigit;
	for(in1=0;in1<100;in1++)//复制对象中的整数值 
	{
		copy1[in1]=digit[in1];
		copy2[in1]=plo.digit[in1];
	}
	for(in1=0;in1<numOfDigit-1;in1=in1+2)//合并同类项，汇总到copy1 
	{
		int in2;
		for(in2=0;in2<plo.numOfDigit-1;in2=in2+2)
		{
			if(copy1[in1+1]==copy2[in2+1])
			{
				copy1[in1]=copy1[in1]+copy2[in2];
				copy2[in2]=0;
				copy2[in2+1]=0;
			}
		}
	}
	for(in1=0;in1<plo.numOfDigit;in1=in1+2)
	{
		if(copy2[in1]!=0||copy2[in1+1]!=0)
		{
			copy1[numOfCopy]=copy2[in1];
			copy1[numOfCopy+1]=copy2[in1+1];
			numOfCopy=numOfCopy+2;
		}
	}
	Polynomial result;
	for(in1=0;in1<100;in1++)
	result.digit[in1]=copy1[in1];
	result.numOfDigit=numOfCopy;
	result.sortTheDigit(); 
	result.polynomial=result.turnTheString();
	return result; 
}

Polynomial Polynomial::polynomialSubtraction(Polynomial plo)//多项式减法 
{
	int copy1[100];
	int copy2[100];
	int in1;
	int numOfCopy=numOfDigit;
	for(in1=0;in1<100;in1++)//复制对象中的整数值 
	{
		copy1[in1]=digit[in1];
		copy2[in1]=plo.digit[in1];
	}
	for(in1=0;in1<numOfDigit-1;in1=in1+2)//合并同类项，汇总到copy1 
	{
		int in2;
		for(in2=0;in2<plo.numOfDigit-1;in2=in2+2)
		{
			if(copy1[in1+1]==copy2[in2+1])
			{
				copy1[in1]=copy1[in1]-copy2[in2];
				copy2[in2]=0;
				copy2[in2+1]=0;
			}
		}
	}
	for(in1=0;in1<plo.numOfDigit;in1=in1+2)
	{
		if(copy2[in1]!=0||copy2[in1+1]!=0)
		{
			copy1[numOfCopy]=-copy2[in1];
			copy1[numOfCopy+1]=copy2[in1+1];
			numOfCopy=numOfCopy+2;
		}
	}
	Polynomial result;
	for(in1=0;in1<100;in1++)
	result.digit[in1]=copy1[in1];
	result.numOfDigit=numOfCopy;
	result.sortTheDigit(); 
	result.polynomial=result.turnTheString();
	return result;
}

Polynomial Polynomial::polynomialMultiplitication(int ele)//多项式与常数的乘法 
{
	int copy[100];
	int in1;
	int numOfCopy=numOfDigit;
	for(in1=0;in1<100;in1++)
	copy[in1]=digit[in1];
	for(in1=0;in1<100;in1=in1+2)
	copy[in1]=copy[in1]*ele;
	Polynomial result;
	for(in1=0;in1<100;in1++)
	result.digit[in1]=copy[in1];
	result.numOfDigit=numOfCopy;
	result.sortTheDigit(); 
	result.polynomial=result.turnTheString();
	return result;	
}

double Polynomial::polynomialValue(double value)//求多项式的值，value----多项式中未知数的值 
{
	double totalValue=0;
	int in1;
	for(in1=0;in1<numOfDigit;in1=in1+2)
	{
		totalValue=totalValue+pow(value,digit[in1+1])*digit[in1];
	}
	return totalValue;
}

void Polynomial::sortTheDigit()//将数据排列成降幂形式 
{
	int in1;
	for(in1=0;in1<numOfDigit-2;in1=in1+2)
	{
		int in2;
		for(in2=in1+2;in2<numOfDigit;in2=in2+2)
		{
			if(digit[in1+1]<digit[in2+1])
			{
				int exchange;
				exchange=digit[in1];
				digit[in1]=digit[in2];
				digit[in2]=exchange;
				exchange=digit[in1+1];
				digit[in1+1]=digit[in2+1];
				digit[in2+1]=exchange;
			}
		} 
	}
}

void Polynomial::findPolynomial(Polynomial ele)//确认多项式是否存在，若不存在，添加 
{
	Polynomial* result;
	result=NULL;
	if(numOfPlo==0)
	{
		result=NULL;
	}
	else
	{
		int in1;
		for(in1=0;in1<numOfPlo;in1++)
		{
			if(!allPlo[in1].polynomial.compare(ele.polynomial))
			result=&allPlo[in1];	
		}
	}
	if(result==NULL)
	{
		allPlo[numOfPlo]=ele;
		numOfPlo++;
		cout << "(New polynomial,save it.)" << endl;
	}
	else
	cout << "(This polynomial has existed.)" << endl;
}

Polynomial& Polynomial::operator=(Polynomial ele)//重载 '=' 
{
	this->polynomial=ele.polynomial;
	this->numOfDigit=ele.numOfDigit;
	int in1;
	for(in1=0;in1<numOfDigit;in1++)
	this->digit[in1]=ele.digit[in1];
	return *this;
}

void disolayAllPolynimal()//显示所有储存的多项式 
{
	int in1;
	cout << "All Polynomials: " << endl;
	for(in1=0;in1<numOfPlo;in1++)
	{
		cout << in1+1 << ". " << allPlo[in1].displayPolynomial() << endl;
	}
}

bool Polynomial::comparePolynomial(Polynomial ele)//比较多项式是否相同 
{
	if(numOfDigit!=ele.numOfDigit)
	{
		return false;
	}
	else
	{
		if(!this->polynomial.compare(ele.polynomial))
		return true;
		else
		return false;
	}
}

Polynomial Polynomial::derivativeOfPlo(Polynomial plo)//求多项式的导数，plo----需求导的多项式
{
	Polynomial result;
	int copy[100];
	int in1;
	for(in1=0;in1<100;in1=in1+2)
	{
		copy[in1]=plo.digit[in1]*plo.digit[in1+1];
		if(plo.digit[in1+1]==0)
		copy[in1+1]=0;
		else
		copy[in1+1]=plo.digit[in1+1]-1;
	}
	int counter=0; 
	for(in1=0;in1<100;in1=in1+2)
	{
		if(copy[in1]!=0)
		{
			result.digit[in1]=copy[in1];
			result.digit[in1+1]=copy[in1+1];
			counter=counter+2;
		}
	}
	result.numOfDigit=counter;
	result.polynomial=result.turnTheString();
	return result;
}
