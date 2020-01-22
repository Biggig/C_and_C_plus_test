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
  BigInteger();//不开空间 
  explicit BigInteger(const string& number);//传入字符串，把字符串转为字符数组 
  BigInteger(const BigInteger& other);//传入对象 
  friend BigInteger operator+(const BigInteger& left,
                              const BigInteger& right);//使用ascll码表，注意进1 
 
  // promise left >= right
  friend BigInteger operator-(const BigInteger& left,
                              const BigInteger& right);
  friend ostream& operator<<(ostream& out, const BigInteger& Bint);//逐个输出 
  ~BigInteger();//删除空间 
 
 private:
  int *data_;//int数组 
  int size_;//size of big integer
};
 
#endif 
