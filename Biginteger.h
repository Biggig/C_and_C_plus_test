#ifndef _BIG_INTEGER_
#define _BIG_INTEGER_
 
#include <iostream>
#include <string>
using std::string;
using std::ostream;
 
// forward declaration
class BigInteger;
 
// operators overloading
BigInteger operator+(const BigInteger& left, const BigInteger& right);
BigInteger operator-(const BigInteger& left, const BigInteger& right);
ostream& operator<<(ostream& out, const BigInteger& Bint);
 
class BigInteger {
 public:
  BigInteger();//�����ռ� 
  explicit BigInteger(const string& number);//�����ַ��������ַ���תΪ�ַ����� 
  BigInteger(const BigInteger& other);//������� 
  friend BigInteger operator+(const BigInteger& left,
                              const BigInteger& right);//ʹ��ascll���ע���1 
 
  // promise left >= right
  friend BigInteger operator-(const BigInteger& left,
                              const BigInteger& right);
  friend ostream& operator<<(ostream& out, const BigInteger& Bint);//������ 
  ~BigInteger();//ɾ���ռ� 
 
 private:
  int *data_;//int���� 
  int size_;//size of big integer
};
 
#endif 
