#define STACK_MAX_SIZE 6

int stack_push(int *stack, int num);

int stack_pop(int *stack);

int stack_top(int *stack, int *ret);

int *stack_constructor(void);

void stack_destructor(int *stack);

int *stack_constructor()
{
	int stack[STACK_MAX_SIZE+1];
	return stack;
} 

void stack_destructor(int *stack)
{
	free(stack);
}

int stack_push(int *stack,int num)
{
	stack[0]++;
	if(stack[0]>STACK_MAX_SIZE)
	    stack[0]--;
	    return 0;
	else
	{
		stack[stack[0]]=num;
		return 1;
	}    
}

int stack_pop(int *stack)
{
	stack[0]--;
	if(stack[0]<=0)
	{
		if(stack[0]<0)
		   stack[0]=0;
		return 0;
	}
	else
	   return 1   
}

int stack_top(int *stack,int *ret)
{
	if(stack[0]==0)
	   return 0;
	else
	   *ret=stack[stack[0]];
	   return *ret;   
}
