#ifndef QUEUE1_0_H
#define QUEUE1_0_H

#include<vector>
#include<iostream>
using namespace std;

template<class T>
class Queue
{
	public:
		Queue();
		bool pop();
		bool push(T ele);
		bool empty();
		T& front();
		T& back();
		int getSize();
	private:
		vector<T> element;
		int size;	
};

template<class T>
Queue<T>::Queue()
{
	size=0;
}

template<class T>
bool Queue<T>::push(T ele)
{
	element.push_back(ele);
	size++;
}

template<class T>
T& Queue<T>::front()
{
	if(size!=0)
	{
		return element[0];
	}
}

template<class T>
T& Queue<T>::back()
{
	if(size!=0)
	{
		return element[size-1];
	}
}

template<class T>
bool Queue<T>::empty()
{
	if(size==0)
		return true;
	else
		return false;	
}

template<class T>
bool Queue<T>::pop()
{
	if(!empty())
	{	
		typename vector<T>::iterator it;
		it=element.begin();
		element.erase(it);
		size--;
	}
}

template<class T>
int Queue<T>::getSize()
{
	return size;
}

#endif
