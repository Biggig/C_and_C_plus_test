#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* next;
} node ;

int size; // the size of linked list
node* head; // the head of linkedlist

//insert the value to the right position
//if the position is not valid, return false
//if insert successfully, return true
bool insert(int position, int value)
{
	if(position>size||position<0)
	   return false;
	else
	{
		if(position==0)
		{
			node* ph;
			ph=(node*)malloc(sizeof(node));//除了输入数据时，不申请空间 
			ph->value=value;
			ph->next=head;
			head=ph;
			size++;
			return true;
		}
		else
		{
			node* ph,*ps;
			ps=(node*)malloc(sizeof(node));
			ph=head;
			int in1;
			for(in1=1;in1<position;in1++)
			{
				ph=ph->next;
			}
			ps->value=value;
			ps->next=ph->next;
			ph->next=ps;
			size++;
			return true;
		}		
	}   
}

// return the value in the given position
int get(int position)
{
	int in1;
	node* ph,*ps;
	ps=ph=head;	
	for(in1=0;in1<position;in1++)
	{
		ps=ph->next;
		ph=ps;
	}
	return ps->value;
}

//clear the linkedlist, remember to free the memory you allocated
void clear()
{
	int in1;
	node* ph,*ps;
	ps=ph=head;	
	for(in1=0;in1<size;in1++)
	{
		ps=ph->next;
		free(ph);
		ph=ps;
	}

}


void print() 
{
	int i;
	for (i = 0; i < size; ++i) 
	{
		printf("%d ", get(i));
	}
	printf("\n");
}


int main() {
	head = NULL;
	size = 0;
	int n, i, position, value;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &position, &value);
		if (insert(position, value)) 
		{
			print();
		}
		else 
		{
			printf("position is not valid\n");
		}
	}
	clear();
	return 0;
}
