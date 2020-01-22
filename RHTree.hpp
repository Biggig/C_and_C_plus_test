#include<iostream>
using namespace std;

struct node
{
	node* left;
	node* right;
	int ele;
	node(int num,node* _left=NULL,node* _right=NULL)
	{
		ele=num;
		left=_left;
		right=_right;
	}
};

class RHTree
{
	public:
		RHTree();
		~RHTree();
		void insert(int ele);
		node* getRoot();
		void inOrder(node* _root);
		void preOrder(node* _root);
		void postOrder(node* _root);
	private:
		node* root;
		int tolNum;	
};

void treeInsert(node* root,int num);
void clear(node* root);
