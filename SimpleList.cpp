#include "SimpleList.hpp"
#include<string>
#include<sstream>
using namespace std;

list::list()
{
	head=NULL;
	_size=0;
}

list::list(const list& aaa)//aaa¿ÉÄÜÎªNULL 
{
	head=new node(aaa.head->data,NULL); 
	node* tail=head;
	node* pnew;
	node* bbb=aaa.head->next;
	int in1;
	for(in1=0;in1<aaa._size-1;in1++)
	{
		pnew=new node(bbb->data,NULL);
		tail->next=pnew;
		tail=pnew;
		bbb=bbb->next;
	}
	_size=aaa._size;
	
}

list& list::operator=(const list& aaa)
{
	if(head!=NULL)
	{
		clear();
		_size=0;
	}
	head=NULL;
	head=new node(aaa.head->data,NULL); 
	node* tail=head;
	node* pnew;
	node* bbb=aaa.head->next;
	int in1;
	for(in1=0;in1<aaa._size-1;in1++)
	{
		pnew=new node(bbb->data,NULL);
		tail->next=pnew;
		tail=pnew;
		bbb=bbb->next;
	}
	_size=aaa._size;
	return *this;
}

list::~list()
{
	if(head!=NULL)
	{
	    clear();
		head=NULL;
		_size=0;	
	}
}

bool list::empty() const
{
	if(_size==0)
	return true;
	else
	return false;
}

int list::size() const
{
	return _size;
}

string list::toString() const
{
	string aaa;
	node* bbb=head;
	while(bbb!=NULL)
	{
		string ddd;
		stringstream ccc;
		ccc << bbb->data;
		ccc >> ddd;
		aaa=aaa+ddd+"->";
		bbb=bbb->next;	
	}
	aaa=aaa+"NULL";
	return aaa;
}

void list::insert(int pos,const int& dat)
{
	if(pos==0)
	{
		node* aaa=new node(dat,head);
		head=aaa;
		_size++;
	} 
	else if(pos>0&&pos<=_size)
	{
		int in1;
		node* bbb=head;
		for(in1=0;in1<pos-1;in1++)
		{
			bbb=bbb->next;
		}
		node* res;
		res=new node(dat,bbb->next);
		bbb->next=res;
		_size++;
	}
	else
	return;
}

void list::erase(int pos)
{
	if(pos==0)
	{
		node* aaa=head;
		head=head->next;
		delete aaa;
		aaa=NULL;
		_size--;
	}
	else if(pos>0&&pos<=_size)
	{
		int in1;
		node* bbb=head;
		for(in1=0;in1<pos-1;in1++)
		{
			bbb=bbb->next;
		}
		node* res=bbb->next;
		bbb->next=res->next;
		delete res;
		res=NULL;
		_size--;
	}
	else
	return;	
}

list& list::sort()
{
	int in1;
	for(in1=0;in1<_size-1;in1++)
	{
		int in2;
		node* aaa=head;
		node* bbb=head->next;
		for(in2=0;in2<_size-1;in2++)
		{
			if(aaa->data>bbb->data)
			{
				int ex;
				ex=aaa->data;
				aaa->data=bbb->data;
				bbb->data=ex;	
			}
			aaa=aaa->next;
			bbb=bbb->next;
		}
	}
	return *this;
}
