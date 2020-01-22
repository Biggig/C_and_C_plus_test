#include<iostream>
#include<string>
using namespace std;

class Polynomial
{
	public:
		Polynomial()//Ĭ�Ϲ��캯�� 
		{
			numOfDigit=0;
		}
		Polynomial(string plo)//���캯�� ��plo--δ����Ķ���ʽ���ַ������ 
		{
			getNum(plo);//���ַ�������ȡ���� 
			combinePolynomial();//�ϲ�ͬ���� 
			sortTheDigit();//�����ݰ�����˳������ 
			polynomial=turnTheString();//������ת��Ϊ�ַ��� 
		}
		void combinePolynomial();//�ϲ�ͬ���� 
		void findPolynomial(Polynomial ele);//���Ҹ��ַ����Ƿ��Ѵ��ڣ�ele---Ҫ���ҵĶ��� 
		string turnTheString();//������ת��Ϊ�ַ��������ض���ʽ���ַ������Ѵ��� 
		Polynomial polynomialAddition(Polynomial plo);//����ʽ�ӷ���plo----��ӵĶ��� 
		Polynomial polynomialSubtraction(Polynomial plo);//����ʽ������plo----����Ķ���
		Polynomial polynomialMultiplitication(int ele);//����ʽ�볣���ĳ˷���ele----��˵ĳ��� 
		Polynomial derivativeOfPlo(Polynomial plo);//�����ʽ�ĵ�����plo----���󵼵Ķ���ʽ 
		double polynomialValue(double value);//�����ʽ��ֵ��value----����ʽ��δ֪����ֵ 
		string displayPolynomial();//��ʾ����ʽ���ַ������Ѵ��� 
		void getNum(string plo);//��ȡ����ʽ�е����֣�plo----����ʽ���ַ�����δ���� 
		void sortTheDigit();//������ʽ�е����ְ�����˳������ 
		Polynomial& operator=(Polynomial ele);//���� '='  
		bool comparePolynomial(Polynomial ele); //�Ƚ϶���ʽ�Ƿ���ͬ 
	private:
		string polynomial;//����ʽ���ַ������ 
		int numOfDigit;//����ʽ���̺������ֵ����� 
		int digit[100];	//����ʽ���̺�������
};



bool validPolynomial(string plo);//�ж�����Ķ���ʽ�Ƿ�Ϸ���plo----����ʽ���ַ������ 
void displayOrderList();//��ӡ�����б� 
void exitTheSystem();//�˳�ϵͳ 
void printOutSet();//��ӡ��ͷ 
void disolayAllPolynimal();//��ʾ���д���Ķ���ʽ 

