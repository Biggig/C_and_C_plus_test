#include<iostream>
#include<queue>
using namespace std;

struct Term
{
	int degree;
	int coefficient;
	Term(int exponent=0,int scalar=0)
	{
		degree=exponet;
		coeffient=scalar;
	}
};

class Plynomial
{
	public:
		Polynomial();
		void read(string input);
		void print();
}
