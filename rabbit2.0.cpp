#include<iostream>
using namespace std;

int main()
{
    int mmm,ddd;
	cin >> mmm >> ddd; 	
	int num[100];
	while(mmm!=0||ddd!=0)
	{
		int in1;
		for(in1=0;in1<100;in1++)
		{
			num[in1]=0;
		}
		if(mmm==1)
		{
			num[0]=1;
			int in2;
			for(in2=0;in2<ddd;in2++)
			{
				int in3;
				for(in3=0;in3<100;in3++)
				{
					num[in3]=num[in3]*2;
				}
				for(in3=0;in3<99;in3++)
				{
					if(num[in3]>=10)
					{
						num[in3+1]=num[in3+1]+num[in3]/10;
						num[in3]=num[in3]%10;
					}
				}
			}
			for(in2=99;in2>=0;in2--)
			{
				if(num[in2]!=0)
				break;
			}
			int in4;
			for(in4=in2;in4>=0;in4--)
			{
				cout << num[in4];
			}
			cout << endl;
	        cin >> mmm >> ddd; 			
		}
		else
		{
			if(ddd<=mmm)
			{
				cout << ddd+1 << endl;
				cin >> mmm >> ddd; 
			}
			else
			{
				int numb[100][100];
				int in2,in3;
				for(in2=0;in2<100;in2++)
				{
					for(in3=0;in3<100;in3++)
					{
						numb[in2][in3]=0;
					}
				}
				for(in2=0;in2<mmm;in2++)
				{
					numb[in2][0]=in2+2;
					for(in3=0;in3<99;in3++)
				   {
						if(numb[in2][in3]>=10)
						{
							numb[in2][in3+1]=numb[in2][in3+1]+numb[in2][in3]/10;
							numb[in2][in3]=numb[in2][in3]%10;
						}
					}
				}
				for(in2=mmm;in2<ddd;in2++)
				{
					for(in3=0;in3<99;in3++)
					{
						numb[in2][in3]=numb[in2-1][in3]+numb[in2-mmm][in3];
					}
					for(in3=0;in3<99;in3++)
				   {
						if(numb[in2][in3]>=10)
						{
							numb[in2][in3+1]=numb[in2][in3+1]+numb[in2][in3]/10;
							numb[in2][in3]=numb[in2][in3]%10;
						}
					}
				}
			for(in2=99;in2>=0;in2--)
			{
				if(numb[ddd-1][in2]!=0)
				break;
			}
			int in4;
			for(in4=in2;in4>=0;in4--)
			{
				cout << numb[ddd-1][in4];
			}				
			cout << endl;
			cin >> mmm >> ddd; 
			}
		}
	}
	return 0;
}
