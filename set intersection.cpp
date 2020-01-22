#include<iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;
	while(num!=0)
	{
		num--;
		int count1,count2;
		int value1[count1];
		int value2[count2];
		int in1;
		cin >> count1;
		for(in1=0;in1<count1;in1++)
			cin >> value1[in1];//输入第一个集合 
		cin >> count2;
		for(in1=0;in1<count2;in1++)
			cin >> value2[in1];	//输入第二个集合
		for(in1=0;in1<count1;in1++)
		{
			int in2;
			for(in2=0;in2<count2;in2++)
			{
				if(value1[in1]==value2[in2])
				{
					cout << value1[in1] << " ";
					break;
				}	
			}
		}
		cout << endl;	 
	}
	return 0;
}
