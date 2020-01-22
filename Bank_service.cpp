#include"Bank_service.h"

int people::numberOfCus=1;

people::people()//��ʼ������ 
{
	privateNum=numberOfCus;
	numberOfCus++;
}

int people::getNum() const//�õ����˱�� 
{
	return privateNum;
}


window::window()//��ʼ�����ڣ�����״̬ 
{
	this->window_status=idle;
}


void window::changeCus(int newCus)//�ı䴰�ڽӴ��Ŀ��� 
{
	prnCus=newCus;
	this->window_status=working;
}

void window::endService()//���ڽ������� 
{
	this->window_status=idle;
}

void window::changeTime(int ST)//�ı䴰�ڽӴ���������ʱ�� 
{
	this->serviceTime=ST;
}

int window::presentCus()//�õ���ǰ���˱�� 
{
	return prnCus;
}

status window::getStatus()//�õ���ǰ״̬ 
{
	return window_status;
}

int window::getTime()
{
	return this->serviceTime;
}


bank::bank(int WT)//����״̬��ʼ�� 
{
	workTime=WT;
	tolNum=0;
}

void bank::addCus()//�������� 
{
	people cus;
	customers.push(cus); 
	cout << "Customer_" << cus.getNum() << " enters the queue." << endl; 
	tolNum++;
}

void bank::ServingCus(window &No)//�ò�ͬ���ڷ������ 
{
	No.changeCus(customers.front().getNum());
	int ST=1;
	No.changeTime(ST);
	tolNum--;	
}


void bank::check()
{
	int in1;
	cout << "The status of windows: " << endl;
	for(in1=0;in1<4;in1++)
	{
		if(windows[in1].getStatus()==idle)
			cout << "window_" << in1+1 << " is idle." << endl;
		else
			cout << "window_" << in1+1 << " is working for customer_" << windows[in1].presentCus() << " ." << endl; 
	}
	cout << endl;
}
 
bool bank::isEmpty()
{
	if(tolNum==0)
		return true;
	else
		return false;
}

void bank::arrangeCus()
{
	cout << "The arrangement of customers: " << endl;
	if(this->isEmpty())
	{
		cout << "There are no customers waiting. " << endl;
		return;
	}
	int in1;
	for(in1=0;in1<4;in1++)
	{
		if(this->isEmpty())
		{
			break;
		}	
		if(windows[in1].getStatus()==idle)
		{
			this->ServingCus(windows[in1]);
			cout << "customer_" << customers.front().getNum() << " goes to window_" << in1+1 << endl;
			customers.pop(); 
		}
		else
			cout << "window_" << in1+1 << " is working for customer_" << windows[in1].presentCus() << " ." << endl; 
	}
	cout << endl;	
}

void bank::cusLeave()
{
	int in1;
	cout << "The situation of customers' leaving: " << endl;
	int counter=0;
	for(in1=0;in1<4;in1++)
	{
		if(windows[in1].getStatus()==working)
		{
			if(windows[in1].getTime()==1)
			{
				cout << "customer_" << windows[in1].presentCus() << " leaves window_" << in1+1 << " ." << endl;
				windows[in1].endService();
			}
			else
			{
				int newST=windows[in1].getTime()-1;
				windows[in1].changeTime(newST);
				counter++;
			}
		}
		else
			counter++;
	}
	if(counter==4)
		cout << "No customers leave. " << endl;
	cout << endl;	
}

void bank::leftCus()
{
	cout << "Customers in queue: " << this->tolNum << endl;
	cout << endl;
} 


