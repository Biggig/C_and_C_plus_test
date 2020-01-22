#include"myStack.h"

myStack::myStack()
{
	mtop=NULL;
	_size=0;
}

bool myStack::empty() const
{
	if(mtop==NULL)
	return true;
	else
	return false;
}

int myStack::size() const
{
	return _size;
}

int myStack::top() const
{
	if(mtop==NULL)
	return 0;
	else
	return mtop->number;
}

bool myStack::pop()
{
	if(mtop==NULL)
	return false;
	else
	{
		Node* aaa=mtop;
		mtop=mtop->next;
		delete aaa;
		_size--;
		aaa=NULL;
		return true;
	}
}

bool myStack::push(int _number)
{
	Node* aaa=new Node;
	if(aaa==NULL)
	return false;
	else
	{
		aaa->number=_number;
	    aaa->next=mtop;
	    mtop=aaa;
	    _size++;
	    return true;
	}	
}

myStack::~myStack()
{
	Node* aaa=mtop;
	while(aaa!=NULL)
	{
		mtop=mtop->next;
		delete aaa;
		aaa=mtop;
	}
	_size=0;
}

myStack::myStack(const myStack& aaa)
{
	if(aaa.mtop==NULL)
	{
		mtop=NULL;
		_size=0;
	}
	else
	{
		mtop=new Node;
	mtop->number=aaa.mtop->number;
	mtop->next=NULL;
	_size++;
	Node* tail=mtop;
	Node* pnew;
	Node* bbb=aaa.mtop->next;
	int in1;
	for(in1=0;in1<aaa._size-1;in1++)
	{
		pnew=new Node;
		pnew->number=bbb->number;
		pnew->next=NULL;
		tail->next=pnew;
		tail=pnew;
		bbb=bbb->next;
		_size++;
	}
	}
}

myStack::myStack(const int* arr,const int num)
{
	if(arr==NULL||num==0)
	{
		mtop=NULL;
		_size=0;
	}
	else
	{
		mtop=new Node;
	    mtop->number=arr[0];
	    mtop->next=NULL;
	    _size=1;
	    int in1;
	    for(in1=1;in1<num;in1++)
	    {
		    push(arr[in1]);
	    }
	}
}

myStack& myStack::operator=(const myStack& aaa)
{
	this->~myStack();
	if(aaa.mtop==NULL)
	{
		mtop=NULL;
		_size=0;
	}
	else
	{
		mtop=new Node;
	    mtop->number=aaa.mtop->number;
	    mtop->next=NULL;
	    _size++;
	    Node* tail=mtop;
	    Node* pnew;
	    Node* bbb=aaa.mtop->next;
	    int in1;
	    for(in1=0;in1<aaa._size-1;in1++)
	   {
		    pnew=new Node;
		    pnew->number=bbb->number;
		    pnew->next=NULL;
		    tail->next=pnew;
		    tail=pnew;
		    bbb=bbb->next;
		    _size++;
	    }
	}
	return *this;	
}
