#include<stdio.h>
int main()
{
	int x=1;
	int y=56;
	const int *p=&x;
	p=&y;
	printf("%x\n",*p);
	return 0;
} 
