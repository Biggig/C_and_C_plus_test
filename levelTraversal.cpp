#include<iostream>
#include<queue>
using namespace std;

template <typename T> struct BinaryNode{
  T elem;
  BinaryNode *left;
  BinaryNode * right;
  BinaryNode(T d, BinaryNode *l=NULL, BinaryNode *r=NULL):elem(d),left(l),right(r){};
};

template <typename T>
void inorder_recursive(BinaryNode<T>* root, void (*visit)(T &x))
{
	if(root!=NULL)
	{
		inorder_recursive(root->left,visit);
		visit(root->elem);
		inorder_recursive(root->right,visit);
	}
}

template <typename T>
void inorder(BinaryNode<T>* root, void (*visit)(T &x))
{
	inorder_recursive(root,visit);
}

template <typename T>
void levelTraversal(BinaryNode<T>* root,void (*visit)(T &x))
{
		queue<BinaryNode<T>*> all;		
		if(root==NULL)
			return ;
		else
			all.push(root);
		while(!all.empty()) 
		{
			visit(all.front()->elem);			
			if(all.front()->left!=NULL)
				all.push(all.front()->left);
			if(all.front()->right!=NULL)
				all.push(all.front()->right);
			all.pop();	
		}	 
		return ; 
} 

template <typename T>
int height(BinaryNode<T>* root)
{
	if(root==NULL)
		return -1;
	else
	{
		int m=height(root->left);
		int n=height(root->right);
		return (m>n)?m+1:n+1;
	}	
}


template <typename T>
void print(T &x)
{
	cout << x << endl;
}

int main()
{
	BinaryNode<int> *root=new BinaryNode<int>(10);
	root->left=new BinaryNode<int>(21);
	root->right=new BinaryNode<int>(31);
	root->left->left=new BinaryNode<int>(54);
	root->right->right=new BinaryNode<int>(34);
	levelTraversal(root,print);
	int ht=height(root);
	cout << ht << endl;
	return 0;
}
