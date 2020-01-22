#include<iostream>
#include<algorithm>
#include<vector>
using namespace std; 

struct HuffmanNode
{
	HuffmanNode *left;
	HuffmanNode *right;
	int parent;
	unsigned char key; 
	int weight;//字符出现次数
	HuffmanNode(int _weight,unsigned char key_,HuffmanNode* _left=NULL,HuffmanNode* _right=NULL,int _parent=0)
				:weight(_weight),key(key_),left(_left),right(_right),parent(_parent)
				{} 
};


bool compare(HuffmanNode* T1,HuffmanNode* T2)
{
	return T1->weight>T2->weight;	
}

class HuffmanTree
{
	public:
		HuffmanTree()
		{
			root=NULL;
		}
		void getNode(HuffmanNode* &in)
		{
			all.push_back(in);
		}
		void buildTree()//根据最小化堆生成哈夫曼树(尚未测试)
		{
			int num=all.size()*2-2;
			int counter=0;
			while(counter!=num)//当堆中元素超过一时 
			{
				vector<HuffmanNode*>::iterator it;
				vector<HuffmanNode*>::iterator is;
				vector<HuffmanNode*>::iterator io;
				long long int min=99999999999999;
				for(it=all.begin();it!=all.end();it++)
				{
					if((*it)->weight<min&&(*it)->parent==0)
					{
						min=(*it)->weight;
						is=it;
					}					
				}
				
				min=99999999999999;
				(*is)->parent=1;
				//cout << (*is)->weight << endl; 
				counter++;
				for(it=all.begin();it!=all.end();it++)
				{
					if((*it)->weight<min&&(*it)->parent==0)
					{
						min=(*it)->weight;
						io=it;
					}					
				}
				(*io)->parent=1;
				//cout << (*io)->weight << endl;
				counter++;
				
				HuffmanNode *in=new HuffmanNode((*is)->weight+(*io)->weight,-1,(*is),(*io));//新插入节点key皆为-1
				//cout << in->weight << endl;
				root=in;
				all.push_back(in);				
			}
		} 
		HuffmanNode* getRoot() const//返回根节点 
		{
			return root;
		}
		void clear()//清空哈夫曼树 
		{
			delete root;
		}
		void deleteNode(HuffmanNode* &need)
		{
	        if( need != NULL )
	        {
	            deleteNode( need->left );
	            deleteNode( need->right );
	            delete need;
	        }
	        need = NULL;
		}
	private:
		HuffmanNode* root;
		vector<HuffmanNode*> all;	
};

