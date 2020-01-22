#include<iostream>
#include<queue>
using namespace std;

template <class T>
class Stack
{
	public:
		Stack()
		{
			count=0;
		}
		void push(const T& data)
		{
			q1.push(data);
			count++;
		}
		T pop()
		{
			if(count!=0)
			{
				T result;
				int in1;
				for(in1=0;in1<count-1;in1++)
				{
					q2.push(q1.front());
					q1.pop();
				}
				result=q1.front();
				q1.pop();
				count--;
				for(in1=0;in1<count;in1++)
				{
					q1.push(q2.front());
					q2.pop();
				}
				return result;
			}
			else
			{
				return 0;
			}	
		}
		T top()
		{
			return q1.back();
		}
		int size() const
		{
			return count;
		}
		bool empty()
		{
			if(count==0)
			return true;
			else
			return false;
		}
		void printSta()
		{
			int num=count;
			T copy[num];
			int in1;
			for(in1=0;in1<num;in1++)
			{
				copy[in1]=this->top();
				cout << this->top() << " ";
				this->pop();
			}
			cout << endl;
			for(in1=num-1;in1>=0;in1--)
			{
				this->push(copy[in1]);
			}
		}
	private:
		queue<T> q1;
		queue<T> q2;
		int count;	
};

template <class T>
void print(Stack<T> aaa)
{
	aaa.printSta();
	return ;
}
