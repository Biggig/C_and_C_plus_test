#include<iostream>
using namespace std;

enum balance{left_higher,equal_height,right_higher
};

struct node
{
	node* left;
	node* right;
	int data;
	balance bal;
	node(int data_,node* left_=NULL,node* right_=NULL,balance bal_=equal_height)
		:data(data_),left(left_),right(right_),bal(bal_)
	{}
	void setBalance(balance b)
	{
		bal=b;
	}
	balance getBalance() const
	{
		return bal;
	}
}; 

class avl_tree
{
	public:
		void avl_insert(node* &sub_root,int &new_data,bool &taller)
		{
			if(sub_root==NULL)
			{
				sub_root=new node(new_data);
				taller=true;
			}
			else if(new_data<sub_root->data)
			{
				avl_insert(sub_root->left,new_data,taller);
				if(taller==true)
					switch(sub_root->getBalance())
					{
						case left_higher:
							left_balance(sub_root);
							taller=false;
							break;
						case equal_height:
							sub_root->setBalance(left_higher);
							break;
						case right_higher:
							sub_root->setBalance(equal_height);
							taller=false;
							break;	
					}
	
			}
			else
			{
				avl_insert(sub_root->right,new_data,taller);
				if(taller==true)
					switch(sub_root->getBalance())
					{
						case left_higher:
							sub_root->setBalance(equal_height);
							taller=false;
							break;
						case equal_height:
							sub_root->setBalance(right_higher);
							break;
						case right_higher:
							right_balance(sub_root);
							taller=false;
							break;
					}
		
			}
		}
		void Rrotate_left(node* &sub_root)
		{
			node* right_tree=sub_root->right;
			sub_root->right=right_tree->left;
			right_tree->left=sub_root;
			sub_root=right_tree;
		}
		void Rrotate_right(node* &sub_root)
		{
			node* right_tree=sub_root->right;
			node* sub_tree=right_tree->left;
			right_tree->left=sub_tree->right;
			sub_tree->right=right_tree;
			sub_root->right=sub_tree->left;
			sub_tree->left=sub_root;
			sub_root=sub_tree; 
		}
		void right_balance(node* &sub_root)
		{
			node* &right_tree=sub_root->right;
			switch(right_tree->getBalance())
			{
				case right_higher:
					sub_root->setBalance(equal_height);
					right_tree->setBalance(equal_height);
					Rrotate_left(sub_root);
					break;
				case left_higher:
					node* sub_tree=right_tree->left;
					switch(sub_tree->getBalance())
					{
						case equal_height:
							sub_root->setBalance(equal_height);
							right_tree->setBalance(equal_height);
							break;
						case left_higher:
							sub_root->setBalance(equal_height);
							right_tree->setBalance(right_higher);
							break;
						case right_higher:
							sub_tree->setBalance(left_higher);
							right_tree->setBalance(equal_height);
							break;		
					}
					sub_tree->setBalance(equal_height);
					Rrotate_right(right_tree);
					Rrotate_left(sub_root);
					break;
			}	
		}
		void Lrotate_right(node* &sub_root)
		{
			node* left_tree=sub_root->left;
			sub_root->left=left_tree->right;
			left_tree->right=sub_root;
			sub_root=left_tree;
		}
		void Lrotate_left(node* &sub_root)
		{
			node* left_tree=sub_root->left;
			node* sub_tree=left_tree->right;
			left_tree->right=sub_tree->left;
			sub_tree->left=left_tree;
			sub_root->left=sub_tree->right;
			sub_tree->right=sub_root;
			sub_root=sub_tree; 
		}
		void left_balance(node* &sub_root)
		{
			node* &left_tree=sub_root->left;
			switch(left_tree->getBalance())
			{
				case left_higher:
					sub_root->setBalance(equal_height);
					left_tree->setBalance(equal_height);
					Lrotate_right(sub_root);
					break;
				case right_higher:
					node* sub_tree=left_tree->right;
					switch(sub_tree->getBalance())
					{
						case equal_height:
							sub_root->setBalance(equal_height);
							left_tree->setBalance(equal_height);
							break;
						case right_higher:
							sub_root->setBalance(equal_height);
							left_tree->setBalance(left_higher);
							break;
						case left_higher:
							sub_tree->setBalance(right_higher);
							left_tree->setBalance(equal_height);
							break;		
					}
					sub_tree->setBalance(equal_height);
					Lrotate_left(left_tree);
					Lrotate_right(sub_root);
					break;
			}	
		}		
};

void print(node* &root)
{
	if(root!=NULL)
	{
		cout << root->data << " ";
		print(root->left);
		print(root->right); 
	}
}

int main()
{
	int num;
	cin >> num;
	while(num!=0)
	{
		num--;
		int counter;
		cin >> counter;
		int in1;
		int insert;
		int a[counter];
		avl_tree Tree;
		node* root=NULL;
		for(in1=0;in1<counter;in1++)
		{
			bool taller;
			cin >> a[in1];
			Tree.avl_insert(root,a[in1],taller);
		}
		bool ta;
		cin >> insert;
		Tree.avl_insert(root,insert,ta);	
		print(root);
		cout << endl;
	}
	return 0;
}
