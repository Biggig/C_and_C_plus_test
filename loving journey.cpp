#include<stdio.h>
int main()
{
	int city,maxoil;
	scanf("%d%d",&city,&maxoil);
	int in1,distance[120],addoil[120];
	for(in1=0;in1<city;in1++)
	    scanf("%d%d",&distance[in1],&addoil[in1]);
	if(maxoil<distance[0])
	printf("No\n");
	else
	{
		int in2;
		int leftoil=maxoil;
		for(in2=0;in2<city;in2++)
		{
			leftoil=leftoil-distance[in2];
			if(leftoil<0)
			{
				in2=in2-1;
				break;
			}
			leftoil=leftoil+addoil[in2];
			if(leftoil>maxoil)
			leftoil=maxoil;
		}
		if(in2!=city)
		printf("No\n");
		else
		printf("Yes\n");
	}
	return 0;    
} 
