#include<iostream>
#include<queue>
using namespace std; 

typedef int T;

struct treeNode 
{
  T data;
  struct treeNode *left, *right;
 
  treeNode(T d, treeNode *l=NULL, treeNode *r=NULL):data(d),left(l),right(r){};
};

int width(const treeNode * root)
{
	if(root==NULL)
		return 0;
	queue<const treeNode*> all;
	all.push(root);
	int maxWidth=1;
	while(true)
	{
		int length=all.size();
		if(length==0)
			break;
		while(length>0)
		{
			const treeNode* exam=all.front();
			all.pop();
			length--;
			if(exam->left)
				all.push(exam->left);
			if(exam->right)
				all.push(exam->right);	
		}
		maxWidth=(all.size()>maxWidth)?all.size():maxWidth;
	}
	return maxWidth;	
}

int main()
{
	treeNode* root=new treeNode(2);
	root->left=new treeNode(1);
	root->right=new treeNode(18);
	root->right->right=new treeNode(18);
	cout << width(root) << endl;
	return 0;
}

