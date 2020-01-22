struct BinaryNode
{
    string name;
    int size;
    BinaryNode *left;
    BinaryNode *right;
    BinaryNode( const string & n = "", int s = 0, BinaryNode *lt =NULL, BinaryNode *rt =NULL )
            : name(n), size(s), left( lt ), right( rt ) { };
};



BinaryNode* myAnswer()
{
	BinaryNode* root=NULL;
	root=new BinaryNode("This");
	root->left=new BinaryNode("is");
	root->right=new BinaryNode("simple");
	return root;
}

int height(const BinaryNode* root)
{
	int counter=-1;
	BinaryNode* _left=root->left;
	BinaryNode* _right=root->right;
	while(_left!=NULL||_right!=NULL)
	
	return counter;
}
