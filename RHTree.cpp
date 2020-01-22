#include"RHTree.hpp"

RHTree::RHTree()
{
	root=NULL;
	tolNum=0;
}

node* RHTree::getRoot()
{
	return root;
}

void treeInsert(node* root,int num)
{
	if(root->ele>=num)
	{
		if(root->left==NULL)
		{
			root->left=new node(num);
		}
		else
		{
			treeInsert(root->left,num);
		}
	}
	else
	{
		if(root->right==NULL)
		{
			root->right=new node(num);
		}
		else
		{
			treeInsert(root->right,num);
		}
	}
}

void RHTree::insert(int ele)
{
	if(root==NULL)
	{
		root=new node(ele);
		tolNum++;
	}
	else
	{
		treeInsert(root,ele);
		tolNum++;
	}
}

void RHTree::preOrder(node* _root)
{
	if(_root!=NULL)
	{
		cout << " " << _root->ele ;
		preOrder(_root->left);
		preOrder(_root->right);		
	}	
}

void RHTree::inOrder(node* _root)
{
	if(_root!=NULL)
	{
		inOrder(_root->left);
		cout << " " << _root->ele ;
		inOrder(_root->right);		
	}	
}

void RHTree::postOrder(node* _root)
{
	if(_root!=NULL)
	{
		postOrder(_root->left);
		postOrder(_root->right);
		cout << " " << _root->ele ;		
	}	
}

void clear(node* root)
{
	if(root!=NULL)
	{
		if(root->left!=NULL||root->right!=NULL)
		{
			clear(root->left);
			clear(root->right);
			delete root;
			root=NULL;
		}
		else
		{
			delete root;
			root=NULL;
		}
	}
}

RHTree::~RHTree()
{
	clear(this->root);
}
