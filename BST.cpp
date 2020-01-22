#include<iostream>
using namespace std;


template <typename Comparable>
class BinarySearchTree
{
  public:
    BinarySearchTree( ) :root( NULL )
    {
    }

    BinarySearchTree( const BinarySearchTree & rhs ) : root( NULL )
    {
        *this = rhs;
    }

    /**
  * Destructor for the tree
  */
    ~BinarySearchTree( )
    {
        makeEmpty( );
    }

    /**
     * Find the smallest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMin( ) const
    {
        if( !isEmpty( ) )
        	return findMin( root )->element;
    }

    /**
     * Find the largest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMax( ) const
    {
        if( !isEmpty( ) )
            return findMax( root )->element;
    }

    /**
     * Returns true if x is found in the tree.
     */
    bool contains( const Comparable & x ) const
    {
        return contains( x, root );
    }
    
    void remove( const Comparable & x )
    {
        remove( x, root );
    }
    /**
     * Test if the tree is logically empty.
     * Return true if empty, false otherwise.
     */
    bool isEmpty( ) const
    {
        return root == NULL;
    }

    /**
     * Print the tree contents in sorted order.
     */
    void printTree( ostream & out = cout ) const
    {
        if( isEmpty( ) )
            out << "Empty tree" << endl;
        else
            printTree( root, out );
    }

    /**
     * Make the tree logically empty.
     */
    void makeEmpty( )
    {
        makeEmpty( root );
    }
    int height()const{
       return height(root);
    }
       
    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( const Comparable & x )
    {
        insert( x, root );
    }
     
       /**
     * Deep copy.
     */
    const BinarySearchTree & operator=( const BinarySearchTree & rhs )
    {
        if( this != &rhs )
        {
            makeEmpty( );
            root = clone( rhs.root );
        }
        return *this;
    }

  private:
    struct BinaryNode
    {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
            : element( theElement ), left( lt ), right( rt ) { }
    };

    BinaryNode *root;


    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( const Comparable & x, BinaryNode * & t )
    {
        if(t==NULL)
        	t=new BinaryNode(x,NULL,NULL);
        else
		{
			if(x>t->element)
				insert(x,t->right);
			else if(x<t->element)
				insert(x,t->left);
			else
				return ;			
		}	

    }

    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    BinaryNode* find(const Comparable & x,BinaryNode *t)//找到x对应指针 
	{
		if(t==NULL)
    		return NULL;
    	else
		{
			if(x==t->element)
				return t;
			else
			{
				if(x>t->element)
					return find(x,t->right);
				else
					return find(x,t->left);	
			}	
		}
	} 
     
    void remove( const Comparable & x,BinaryNode *t )
    {
    	if(t==NULL)
    		return;
    	BinaryNode* target=find(x,t);
		BinaryNode* to_delete=target;	
    	if(target==NULL)
			return ;
		else
		{
			if(target->right==NULL)
				target=target->left;
			else if(target->left==NULL)
				target=target->right;
			else
			{
				to_delete=target->left;
				BinaryNode* parent=target;
				while(to_delete->right!=NULL)
				{
					parent=to_delete;
					to_delete=to_delete->right;
				} 
				target->element=to_delete->element;
				if(parent==target)
					target->left=to_delete->left;
				else
					parent->right=to_delete->left;	
			}
			delete to_delete;		
		}		
    		
	}
        /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    BinaryNode * findMin( BinaryNode *t ) const
    {
  		if(t==NULL)
		  return NULL;
		else
		{
			if(t->left!=NULL)
				return findMin(t->left);
			else
				return t;	
		}       

    }

    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
    BinaryNode * findMax( BinaryNode *t ) const
    {
  		if(t==NULL)
		  return NULL;
		else
		{
			if(t->right!=NULL)
				return findMax(t->right);
			else
				return t;	
		}        

    }


    /**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the subtree.
     */
    bool contains( const Comparable & x, BinaryNode *t ) const
    {
    	if(t==NULL)
    		return false;
    	else
		{
			if(x==t->element)
				return true;
			else
			{
				if(x>t->element)
					return contains(x,t->right);
				else
					return contains(x,t->left);	
			}	
		}	

    }


    /**
     * Internal method to make subtree empty.
     */
    void makeEmpty( BinaryNode * & t )
    {
        if( t != NULL )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = NULL;
    }

    /**
     * Internal method to print a subtree rooted at t in sorted order.
     */
    void printTree( BinaryNode *t, ostream & out ) const
    {
        if( t != NULL )
        {
            printTree( t->left, out );
            out << t->element << endl;
            printTree( t->right, out );
        }
    }

    /**
     * Internal method to clone subtree.
     */
    BinaryNode * clone( BinaryNode *t ) const
    {
        if( t == NULL )
            return NULL;
        else
            return new BinaryNode( t->element, clone( t->left ), clone( t->right ) );
    }

   int height(BinaryNode *t) const {
     if (!t)
         return -1;
       int l = height(t->left);
       int r = height(t->right);
       return (l>=r)? l+1: r+1;
    }
};

