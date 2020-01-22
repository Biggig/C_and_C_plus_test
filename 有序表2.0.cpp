#include<iostream>
using namespace std;

struct Num
{
	int value;
	Num *next;
};//构造链表元素 

int main()
{
	Num *head,*pnew,*tail;//head为链表开头，pnew为新增链表成员，tail为链表结尾 
	head=new Num;
	head->next=NULL;
	tail=head;
	int m,n;
	cin >> m >> n;
	cin >> head->value; //输入第一个值 
	int integer;
	for(integer=0;integer<m+n-1;integer++)//构造链表，并赋值 
	{
		pnew=new Num;
		cin >> pnew->value;
		pnew->next=NULL;
		tail->next=pnew;
		tail=pnew;
	}
	Num *n1,*n2;
	int integer2;
	for(integer=0;integer<m+n-1;integer++)//冒泡排序 
	{
		n1=head;
		n2=head->next;
		for(integer2=0;integer2<m+n-1;integer2++)
		{
			int exchange=0;
			if(n1->value>n2->value)
			{
				exchange=n1->value;
				n1->value=n2->value;
				n2->value=exchange;
			}
			n1=n1->next;
			n2=n2->next;
		}
	}
	Num *p=head;
	for(integer=0;integer<m+n;integer++)//打印结果 
	{
		cout << p->value << " ";
		p=p->next;
	}
	cout << endl;
	Num *f=head;
	for(integer=0;integer<m+n;integer++)//收回内存空间 
	{
		Num *g=f->next;
		delete f;
		f=g;
	}
	return 0;
}
