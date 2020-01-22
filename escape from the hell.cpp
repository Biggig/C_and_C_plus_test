#include<stdio.h>
int main()
{
	int size;
	scanf("%d\n",&size);
	char map[20][20];
	int in1,in2;
	int x,y;
	for(in1=0;in1<size+2;in1++)
	{
		for(in2=0;in2<size+3;in2++)
		{
			map[in1][in2]=getchar();
			if(map[in1][in2]=='A')
			{
				x=in1;
				y=in2;
			}
		}    
	}
	char action[100];
	int in3=0;
	int xo;
	int yo;
	int counter=0,counter1=0;
	while(scanf("%c%*c",&action[in3])!=EOF)
	{

		char hold;
		if(counter==0)
		{
			 
		yo=y;
        xo=x;
		switch(action[in3])
		{
			case 'a': x=x; y=y-1; break;
			case 's': x=x+1; y=y; break;
			case 'w': x=x-1; y=y; break;
			case 'd': x=x; y=y+1; break;
			default :break;          
		}
		if(x==0)
		   x=size;
		if(x==size+1)
		   x=1;
		if(y==0)
		   y=size;
		if(y==size+1)
		   y=1;
		hold=map[x][y];}	
		if(hold=='$')
		{
			printf("Game Over!\n");
			break;
		}
		else if(hold==' ')
		{
			map[x][y]='A';
			if(map[xo][yo]!='@')
			   map[xo][yo]=' ';	
		}
		else if(hold=='#')
		{
			x=xo;
			y=yo;
			if(map[xo][yo]=='@')
			{
				map[xo][yo]='A';
				counter1++;
			}
		}
		else if(hold=='@')
		{
			map[x][y]='A';
			if(map[xo][yo]!='@')
			   map[xo][yo]=' ';
			counter++;
		}
		int ina,inb;
		for(ina=0;ina<size+2;ina++)
		{
			for(inb=0;inb<size+3;inb++)
			{
				printf("%c",map[ina][inb]);
			}
		}
		if(counter1==1)
		{
			counter1=0;
			map[x][y]='@';
		}
		if(counter==2)
		{
			counter=0;
			map[x][y]='@';
		}
		in3=in3+1;	            
	}
	return 0;	
} 
