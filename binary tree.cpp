#include"binary tree.hpp"

void BinaryTree::MemoryDelete(node* p)
{
     if (p!=NULL) 
	 {
     MemoryDelete(p->left);
     MemoryDelete(p->right);
     delete p;
     p = NULL;
     return ;
     }
     else 
	 {
      return ;
     }
}

void BinaryTree::BuildTree(const node* Sroot,node* &Troot)
{
	if(Sroot!=NULL)
	{
		Troot=new node(Sroot->ele);
	if(Sroot->left!=NULL)
	{
		BuildTree(Sroot->left,Troot->left);
	}
	if(Sroot->right!=NULL)
	{
		BuildTree(Sroot->right,Troot->right);
	}
	}
	else
	Troot=NULL;	 
}

void BinaryTree::BuildTree(const int* arr,int len,node* &rot)
{
	BinaryTree aaa; 
	int in1;
	aaa.root=new node(arr[0]);
	for(in1=1;in1<len;in1++)
	{
		aaa.insert(arr[in1]);
	}
	rot=aaa.root;
	aaa.root=NULL;
}

BinaryTree::BinaryTree()
{
	root=NULL;
}

BinaryTree::BinaryTree(const BinaryTree& aaa)
{
	BuildTree(aaa.root,root);
}

BinaryTree::BinaryTree(const int* arr,int len)
{
	BuildTree(arr,len,root);
}

void BinaryTree::ResetTree(const int* arr,int len)
{
	clear();
	BuildTree(arr,len,root);
}

BinaryTree::~BinaryTree()
{
	if(root!=NULL)
	clear(); 
}

void BinaryTree::clear()
{
	if(root!=0) 
	{
		MemoryDelete(root);
		root=NULL;
	}
}

    void Tree_insert(int ele,node* &root) {
      if (root!=NULL) {
        if (ele > root->ele) {
          Tree_insert(ele,root->right);
        }
        else if (ele < root->ele) {
          Tree_insert(ele,root->left);
        }
      }
      else {
        root = new node (ele);
      }
    }

    void BinaryTree::insert(int ele) {
     Tree_insert(ele,root);
    }

    void Tree_Delete(int ele,node *&root) {//不要执着于删除，转移变量值即可 
      if (root!=NULL) {
        if (ele>root->ele) {
          Tree_Delete(ele,root->right);
        }
        else if (ele<root->ele) {
          Tree_Delete(ele,root->left);
        }
        else {
          if (root->right==NULL&&root->left==NULL) {
              delete root;
              root=NULL;
          }
          else if (root->right!=NULL&&root->left==NULL){
            node *ptr = root->right;
            root->ele = root->right->ele;
            root->left = root->right->left;
            root->right = root->right->right;
            delete ptr;
            ptr = NULL;
          }
          else {
               if (root->left->right==NULL) {
                node *temp = root->left;
                root->ele = root->left->ele;
                root->left = root->left->left;
                delete temp;
                temp = NULL;
               }
               else {
                   node *Node = root->left;
                   node *Pnode = root->left;
                   while (Node->right) {
                    Pnode = Node;
                    Node = Node->right;
                   }
                   root->ele = Node->ele;
                   Pnode->right = Node->left;
                   delete Node;
                   Node = NULL;
               } 
          }
        }
      }
    }
    void BinaryTree::Delete(int ele) {
      Tree_Delete(ele,root);
    }

void BinaryTree::print()
{
	if(root!=NULL)
	{
	    preorder(root);
	    cout << endl;
	}
	else
	cout << endl;
}

void BinaryTree::preorder(const node* p)
{
	if(p!=NULL)
	{
		cout << p->ele << " ";
		preorder(p->left);
		preorder(p->right);	
	}
}




