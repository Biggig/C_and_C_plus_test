#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
	int num;
	float score;
	struct student *next;
}STUDENT;

int main()
{
	STUDENT a,b,c,d,*head,*p;
	a.num=101;
	b.num=102;
	c.num=103;
	a.score=99.9;
	b.score=98.3;
	c.score=97.8;
	head=&a;
	a.next=&b;
	b.next=&c;
	c.next=&d;
	d.next=NULL;
	p=head;
	do
	{
		printf("The score of student %d is %.1f\n",p->num,p->score);
		p=p->next;
	 } while(p->next!=NULL);
	 return 0;
}
