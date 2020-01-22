#include<iostream>
using namespace std;


typedef int Comparable;
struct BinaryNode
{
    Comparable data;
    BinaryNode *left;
    BinaryNode *right;

    BinaryNode( const Comparable & theElement, BinaryNode *lt = NULL, BinaryNode *rt=NULL )
        : data( theElement ), left( lt ), right( rt ) { }
}; 


void rotateL(BinaryNode* &root)
{
	BinaryNode* T=root->right;
	root->right=T->left;
	T->left=root;
	root=T;
	T=NULL;
}

void visit(BinaryNode* root)
{
	if(root!=NULL)
	{
		cout << root->data << " ";
		visit(root->left);
		
		visit(root->right);
	}
}

int main()
{
	BinaryNode* root=new BinaryNode(1);
	root->left=new BinaryNode(2);
	root->right=new BinaryNode(3);
	root->right->left=new BinaryNode(4);
	root->right->right=new BinaryNode(5);
	visit(root);
	cout << endl;
	rotateL(root);
	visit(root);
	cout << endl;
	return 0;
}
