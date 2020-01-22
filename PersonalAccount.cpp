#include<string>
using namespace std;

#include"PersonalAccount"

int PersonalAccount::_total_per_account=0;

int PersonalAccount::_acc_id_ptr=12010000;

PersonalAccount::PersonalAccount()
{
	_id=_acc_id_ptr;
	_balance=10;
	_valid=true;
	_acc_id_ptr++;
	_total_per_account++;
}

PersonalAccount::~PersonalAccount()
{
	_total_per_account--;
}

string PersonalAccount::profile() const
{
	string aaa;
	aaa="ID:"+to_string(_id)+"\nBALANCE:"+to_string(_balance)+"\nVALID:Y\nTYPE:PERSONAL\n";
	return aaa;
}

void PersonalAccount::reset()
{
	_balance=10;
	_valid=true;
}

int PersonalAccount::get_total_per_account()
{
	return _total_per_account;
}
