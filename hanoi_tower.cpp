#include<iostream>
using namespace std;

void move(int count,int start,int finish,int temp,int &counter)
{
	if(count>0)
	{
		move(count-1,start,temp,finish,counter);
		cout << "Move disk_" << count << " from" << " stick_" << start << " to " << "stick_" << finish << "." << endl;
		counter++;
		move(count-1,temp,finish,start,counter);
	}
}

int main()
{
	int counter=0;
	move(10,1,3,2,counter);
	cout << counter << endl;
	return 0;
}
