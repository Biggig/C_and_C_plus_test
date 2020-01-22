#include<iostream>
using namespace std;

typedef int T;

struct BinaryNode{

  T data; //store data

  BinaryNode *left, *right;

  BinaryNode(T d, BinaryNode *l=NULL, BinaryNode* r=NULL):data(d), left(l), right(r) {};

};
 
bool isRegularBT_cur(BinaryNode* root)
{
	if(root==NULL)
		return true;//非根节点为空 
	else
	{
		if(root->left==NULL&&root->right==NULL)
			return true;
		else if(root->left!=NULL&&root->right!=NULL)
		{
			bool left_=isRegularBT_cur(root->left);
			bool right_=isRegularBT_cur(root->right);
			if(left_==true&&right_==true)
				return true;
			else
				return false;	
		}	
		else
			return false;		
	}	
} 
 
bool isRegularBT(BinaryNode* root)
{
	if(root==NULL)
		return false;//根节点 
	else
	{
		if(root->left==NULL&&root->right==NULL)
			return true;
		else if(root->left!=NULL&&root->right!=NULL)
		{
			bool left_=isRegularBT_cur(root->left);
			bool right_=isRegularBT_cur(root->right);
			if(left_==true&&right_==true)
				return true;
			else
				return false;	
		}
		else
			return false;
		
	}	
}

int main()
{
	BinaryNode *root=new BinaryNode(1);
	root->left=new BinaryNode(2);
	root->right=new BinaryNode(3);
	root->left->right= new BinaryNode(5);
	root->left->left = new BinaryNode(5);
	root->left->right->left=new BinaryNode(7);
	root->left->right->right=new BinaryNode(7);
	cout << isRegularBT(root) << endl;
	return 0;
} 
