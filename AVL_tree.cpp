#include<iostream>
using namespace std;

enum Balance_factor{ left_higher,equal_higher,right_higher };

template<class T>
struct Binary_node
{
	T ele;
	Binary_node *left;
	Binary_node *right;
	Binary_node(T elem, Binary_node *lef=NULL, Binary_node *rig=NULL)
				:ele(elem),left(lef),rig(right)
				{};
};

template< class T >
struct AVL_node:public Binary_node<class T>
{
	Balance_factor balance;//Æ½ºâÇé¿ö 
	AVL_node(const T &x)
			:Binary_node(x)
	{}
	void set_balance(Balance_factor b)
	{
		balance=b;
	}
	Balance_factor get_balance() const
	{
		return balance;
	}		
};


