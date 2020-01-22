#include"Stack3.0.h"

template<class T>
Stack<T>::Stack()
{
	size=0;
	head=NULL;
}

template<class T>
bool Stack<T>::push(T element)
{
	Node<T>* insert=new Node<T>(element,head);
	head=insert;
	size++;
	return true;
}

template<class T>
bool Stack<T>::pop()
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

template<class T>
bool Stack<T>::empty()
{
	return size;
}

template<class T>
T Stack<T>::top() const
{
	if(!empty())
		return head->element;
}

template<class T>
int Stack<T>::getSize() const
{
	return size;
}

template<class T>
Stack<T>::~Stack()
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

