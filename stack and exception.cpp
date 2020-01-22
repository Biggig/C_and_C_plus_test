#include<iostream>
using namespace std;


const int MAX_LEN=5;

template<class T>
class Stack
{
	public:
		explicit Stack()
		{
			stack_size=0;
		}
		bool empty() const
		{
			if(stack_size==0)
			return true;
			else
			return false;
		}
		int size() const
		{
			return stack_size;
		}
		T& top()
		{
			if(empty())
				throw int();
			else
				return data[stack_size-1];	
		}
		const T& top() const
		{
			if(empty())
				throw(int());
			else
				return data[stack_size-1];	
		}
		void push(const T& x)
		{
			if(stack_size!=5)
			{
				data[stack_size]=x;
				stack_size++;
			}
			else
			{
				if(x>data[stack_size-1])
				{
					data[stack_size-1]=x;
				}
			}
		}
		void pop()
		{
			if(empty())
			{
				throw double();
			}
			else
			{
				data[stack_size-1]=0;
				stack_size--;
			}
		}
	private:
		T data[MAX_LEN];
		int stack_size;	
};
