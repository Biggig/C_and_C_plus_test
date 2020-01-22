#include"Mediator.hpp"

Mediator* Mediator::Ins=NULL;

void Mediator::RegisterHandler(User* u)
{
	users.push_back(u);
}

void Mediator::ChatHandler(const int& to, const string& msg)
{
	int counter=0;
	list<User*>::iterator it;
	for(it=users.begin();it!=users.end();it++)
	{
		if((*it)->getId()==to)
		{
			counter++;
			break;
		}
	}
	if(counter==0)
		cout << "Are you kidding ? There is no such a guy!" << endl;
	else	
		(*it)->GetMessage(msg);
}

void Mediator::DressInfoHandler(const int& to)
{
	int counter=0;
	list<User*>::iterator it;
	for(it=users.begin();it!=users.end();it++)
	{
		if((**it).getId()==to)
		{
			counter++;
			break;
		}
	}
	if(counter!=0)
	{
		(**it).ShowMyCuteDresses();
	}	
}

pair<int,string> Mediator::TradeHandler(const int& to, const int& pay,const string& dressName)
{
	int counter=0;
	list<User*>::iterator it;
	for(it=users.begin();it!=users.end();it++)
	{
		if((*it)->getId()==to)
		{
			counter++;
			break;
		}
	}
	if(counter==0)
	{
		cout << "There is no Such a guy!" << endl; 
		pair<int,string> p1(-4,"0");
		return p1;
	}	
	else
	{
		return (*it)->SellBeautifulDress(pay,dressName);
	}		
}

void User::BuyBeautifulDress(const int & id, const int & pay, const string & name)
{   
	     
    if(pay>this->money)
    	cout << this->name << " : " << "Forget to Check Wallet!" << endl;
	else
    {
    	pair<int,string> copy=  Mediator::getInstance()->TradeHandler(id,pay,name);
    	if(copy.first>0)
    	{
    		Dress test(copy.second,copy.first);
    		dresses.push_back(test);
    		money=money-pay;
    		cout << this->name << " : " << "So happy to get new Dress!" << endl;
		}
		else if(copy.first==0)
		{
			cout << this->name << " : " << "I'm so sorry maybe just because I love it so much." << endl;
		}
		else if(copy.first==-1)
		{
			cout << this->name << " : " <<  "OMG! Why it is so Expensive!" << endl;
		}
	}        
}

void User::SendMessage(const int& to, const string & msg)
{
	Mediator::getInstance()->ChatHandler(to,msg); 
}

void User::GetDressInfo(const int& id_)
{
	cout << this->name << " : " << "I wanna see your beautiful suits!" << endl;
	Mediator::getInstance()->DressInfoHandler(id_);	
}
