 #include<stdio.h>
int main()
{
	int num;
	scanf("%d",&num);
	int in1;
	for(in1=0;in1<num;in1++)
	{
		int test;
		scanf("%d",&test);
		int in2;
		int chang[50]={0};
		int kuang[50]={0};
		for(in2=0;in2<test;in2++)
		{
			scanf("%d%d",&chang[in2],&kuang[in2]);
		}
		int in3,counter=0;
		for(in3=0;in3<test-1;in3++)
		{
			int in4,check[50]={0},check2[50]={0};
			int hold[50]={0},tol[50]={0};
			int in5=0;
			for(in4=in3+1;in4<test;in4++)
			{
				if(chang[in3]==kuang[in4])
				    {
				    	tol[in5]=chang[in4]+kuang[in3];
				    	hold[in5]=chang[in3];
				    	check[in5]=in4;
				    	check2[in5]=in3;
				    	in5++;
					}
				if(chang[in3]==chang[in4])
				    {
				    	tol[in5]=kuang[in3]+kuang[in4];
				    	hold[in5]=chang[in3];
				    	check[in5]=in4;
				    	check2[in5]=in3;
				    	in5++;
					}
				if(kuang[in3]==chang[in4])
				    {
				    	tol[in5]=chang[in3]+kuang[in4];
				    	hold[in5]=kuang[in3];
				    	check[in5]=in4;
				    	check2[in5]=in3;
				    	in5++;
					}
				if(kuang[in3]==kuang[in4])
				    {
				    	tol[in5]=chang[in3]+chang[in4];
				    	hold[in5]=kuang[in3];
				    	check[in5]=in4;
				    	check2[in5]=in3;
				    	in5++;
					}	
				int in6;
				for(in6=0;in6<test;in6++)
				{
					int in7;
					for(in7=0;in7<in5;in7++)
					{
					if(chang[in6]==tol[in7]&&in6!=check[in7]&&in6!=check2[in7])
					   counter++;
					if(kuang[in6]==tol[in7]&&in6!=check[in7]&&in6!=check2[in7])
					   counter++;
					if(chang[in6]==hold[in7]&&in6!=check[in7]&&in6!=check2[in7])
					   counter++;
					if(kuang[in6]==hold[in7]&&in6!=check[in7]&&in6!=check2[in7])
					   counter++;
			        }
				}
		    }
		}
		if(counter!=0)
		    printf("Yes\n");
		else
		    printf("No\n");
	}
	return 0;
}
