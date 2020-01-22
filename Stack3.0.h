#ifndef STACK3_0_H
#define STACK3_0_H

#include<iostream>
using namespace std;


template<class T>
struct Node
{
	T element;
	Node* next;
	Node(T ele,Node* ne)
	{
		element=ele;
		next=ne;
	}
};

template<class T>
class Stack
{
	public:
		Stack()
		{
			size=0;
	  		head=NULL;
		}
		~Stack()
		{
			while(head!=NULL)
			{
				Node<T>* pointer=head;
				head=head->next;
				delete pointer;
				size--;
				pointer=NULL;	
			}			
		}
		bool pop()
		{
			if(empty())
				return false;
			else
			{
				Node<T>* pointer=head;
				head=head->next;
				delete pointer;
				pointer=NULL;
				size--;
				return true; 
			}				
		}
		bool push(T element)
		{
			Node<T>* insert;
			insert=new Node<T>(element,head);
			head=insert;
			size++;
			return true;			
		}
		bool empty()
		{
			if(size==0)
				return true;
			else 
				return false;			
		}
		T top() 
		{
			if(!empty())
				return head->element;
		}
		int getSize() const
		{
			return size;
		}
	private:
		Node<T>* head;	
		int size;		
};


Stack<T>::Stack


#endif
