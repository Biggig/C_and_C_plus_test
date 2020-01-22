#include<stdio.h>
#include<string.h>
int main()
{
	char aaa[60];
	char bbb[60];
	scanf("%s %s",aaa,bbb);
	int anum=strlen(aaa);
	int bnum=strlen(bbb);
	if(anum!=bnum)
	   printf("NO\n");
	else
	{
		int in1;
		int sign[60]={0};
		for(in1=0;in1<anum;in1++)
		{
			int in2;
			for(in2=0;in2<anum;in2++)
			{
				if(sign[in2]==0)
				{
					if(aaa[in1]==bbb[in2])
					{
						sign[in2]=1;
						break;
					}
				}
			}
		}
		int counter=0;
		for(in1=0;in1<anum;in1++)
		{
			if(sign[in1]==1)
			{
				counter++;
			}
		}
		if(counter==anum)
		   printf("YES\n");
		else
		   printf("NO\n");   
	}
	return 0;      
}
