#include<vector>
#include<iostream>
using namespace std;

int main()
{
	vector<int> numbers;
	int element;
	cin >> element;
	while(element!=-1)
	{
		numbers.push_back(element);
		cin >> element;
	}
	int tol=numbers.size();
	int key;
	for(key=1;key<tol;key++)
	{
		int counter=0;
		while(numbers[key]>numbers[counter])
		{
			counter++;//��λ��key��ʼ�ң���ǰ����û�б���С���� 
		}
		int value=numbers[key];
		int integer;
		for(integer=key;integer>counter;integer--)
		{
			numbers[integer]=numbers[integer-1];//���� 
		}
		numbers[counter]=value;
	}
	for(key=0;key<tol;key++)
	{
		cout << numbers[key] << " ";
	}
	cout << endl;
	return 0;
} 
