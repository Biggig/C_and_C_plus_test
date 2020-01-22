#include"polynomial.h"
#include<iostream>
#include<sstream>
using namespace std;

#include<string.h>
#include<math.h>

int numOfPlo=0;
Polynomial allPlo[1000];

void printOutSet()//��ӡ��ͷ 
{
	cout << "Welcome to use this polynomial-solving system!" << endl;	 
}

void exitTheSystem()//�˳�ϵͳ 
{
	exit(0);
}

void displayOrderList()//��ӡ�����б�
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

bool validPolynomial(string plo)//�ж�����Ķ���ʽ�Ƿ�Ϸ���plo----����ʽ���ַ������
{
	int counter=0;
	int zuokuohao=0;//���������� 
	int douhao=0;//�������� 
	int youkuohao=0; //���������� 
	const char* aaa=plo.c_str();//stringתchar���� 
	int num=strlen(aaa);
	if(aaa[num-1]!=')') //�ж��ַ������Ƿ���'��'��β 
	counter++;
	else
	youkuohao++;
	int in1;
	for(in1=0;in1<num-1;in1++)//�ж϶���ʽ�Ƿ�Ϸ� 
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

void Polynomial::getNum(string plo)//��ȡ����ʽ�е����֣�plo----����ʽ���ַ�����δ���� 
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
		if(aaa[in1]=='-')//������Ϊ���� 
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
		if(aaa[in1]>='0'&&aaa[in1]<='9')//����Ϊ���� 
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

void Polynomial::combinePolynomial()//�ϲ�ͬ���� 
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
			if(copy[in1+1]==copy[in2+1])//������ͬ���ϲ�ͬ���� 
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

string Polynomial::turnTheString()//ת��Ϊ�ַ��� 
{
	string total;
	int in1;
	for(in1=0;in1<numOfDigit-1;in1=in1+2)
	{
		string str,str1;
		stringstream st,sr;
		if(digit[in1]!=0)//ϵ����Ϊ�� 
		{
			if(digit[in1]==1)//ϵ��Ϊ1
			{
				if(digit[in1+1]==0)//����Ϊ0 
				str="1";
				else if(digit[in1+1]==1)//����Ϊ1
				str="x";
				else//����һ����� 
				{
					st << digit[in1+1];
					st >> str;
					str="x^"+str; 
				} 
			} 
			else if(digit[in1]==-1)//ϵ��Ϊ-1
			{
				if(digit[in1+1]==0)//����Ϊ0 
				str="-1";
				else if(digit[in1+1]==1)//����Ϊ1
				str="-x";
				else//һ����� 
				{
					st << digit[in1+1];
					st >> str;
					str="-x^"+str; 
				} 
			} 
			else//ϵ��Ϊһ����� 
			{
				if(digit[in1+1]==0)//����Ϊ0 
				{
					st << digit[in1];
					st >> str;
				}
				else if(digit[in1+1]==1)//����Ϊ1
				{
					st << digit[in1];
					st >> str;
					str=str+"x";
				}
				else//����һ����� 
				{
					st << digit[in1];
					st >> str;
					sr << digit[in1+1];
					sr >> str1;
					str=str+"x^"+str1; 
				} 	
			}
		}
		else//ϵ��Ϊ�� 
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

string Polynomial::displayPolynomial()//��ʾ����ʽ 
{
	if(polynomial=="")
	return "0";
	else
	return polynomial;
}

Polynomial Polynomial::polynomialAddition(Polynomial plo)//����ʽ�ӷ���������ʽ�Ѻϲ�ͬ���� 
{
	int copy1[100];
	int copy2[100];
	int in1;
	int numOfCopy=numOfDigit;
	for(in1=0;in1<100;in1++)//���ƶ����е�����ֵ 
	{
		copy1[in1]=digit[in1];
		copy2[in1]=plo.digit[in1];
	}
	for(in1=0;in1<numOfDigit-1;in1=in1+2)//�ϲ�ͬ������ܵ�copy1 
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

Polynomial Polynomial::polynomialSubtraction(Polynomial plo)//����ʽ���� 
{
	int copy1[100];
	int copy2[100];
	int in1;
	int numOfCopy=numOfDigit;
	for(in1=0;in1<100;in1++)//���ƶ����е�����ֵ 
	{
		copy1[in1]=digit[in1];
		copy2[in1]=plo.digit[in1];
	}
	for(in1=0;in1<numOfDigit-1;in1=in1+2)//�ϲ�ͬ������ܵ�copy1 
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

Polynomial Polynomial::polynomialMultiplitication(int ele)//����ʽ�볣���ĳ˷� 
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

double Polynomial::polynomialValue(double value)//�����ʽ��ֵ��value----����ʽ��δ֪����ֵ 
{
	double totalValue=0;
	int in1;
	for(in1=0;in1<numOfDigit;in1=in1+2)
	{
		totalValue=totalValue+pow(value,digit[in1+1])*digit[in1];
	}
	return totalValue;
}

void Polynomial::sortTheDigit()//���������гɽ�����ʽ 
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

void Polynomial::findPolynomial(Polynomial ele)//ȷ�϶���ʽ�Ƿ���ڣ��������ڣ���� 
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

Polynomial& Polynomial::operator=(Polynomial ele)//���� '=' 
{
	this->polynomial=ele.polynomial;
	this->numOfDigit=ele.numOfDigit;
	int in1;
	for(in1=0;in1<numOfDigit;in1++)
	this->digit[in1]=ele.digit[in1];
	return *this;
}

void disolayAllPolynimal()//��ʾ���д���Ķ���ʽ 
{
	int in1;
	cout << "All Polynomials: " << endl;
	for(in1=0;in1<numOfPlo;in1++)
	{
		cout << in1+1 << ". " << allPlo[in1].displayPolynomial() << endl;
	}
}

bool Polynomial::comparePolynomial(Polynomial ele)//�Ƚ϶���ʽ�Ƿ���ͬ 
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

Polynomial Polynomial::derivativeOfPlo(Polynomial plo)//�����ʽ�ĵ�����plo----���󵼵Ķ���ʽ
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
