#include<stdio.h>
int main()
{
	int mmm,sss,ttt;
	while(scanf("%d%d%d",&mmm,&sss,&ttt)!=EOF)
	{
		int tidais=sss;
		int tidait=ttt;
		while(mmm>=10&&ttt>=1&&sss>0)
		{
			mmm-=10;
			ttt-=1;
			sss-=60;
		}   
		while(1)
		{
			if(mmm>=0&&mmm<=1&&ttt>=7&&sss>102)
			{
				mmm=(mmm+20)%10;
				ttt=ttt-7;
				sss=sss-120;
			}
			else if(mmm>=2&&mmm<=5&&ttt>=3&&sss>34)
			{
				mmm=(mmm+8)%10;
				ttt=ttt-3;
				sss=sss-60;
			}
			else if(mmm>=6&&mmm<=9&&ttt>=2&&sss>17)
			{
				mmm=(mmm+4)%10;
				ttt=ttt-2;
				sss=sss-60;
			}
			else
			break;
		}
		while(ttt>0&&sss>0)
		{
			ttt--;
			sss=sss-17;
		}
		if(ttt==0&&sss>0)
		   printf("No\n%d\n",tidais-sss);
		if(ttt>=0&&sss<=0)
		   printf("Yes\n%d\n",tidait-ttt);      
	}
} 
