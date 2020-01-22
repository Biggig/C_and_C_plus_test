#include<iostream>
using namespace std;

template<class T>
class Stack
{
	public:
		Stack()
		{
			top_node=NULL;
			node_num=0;
		}
		Stack(const Stack& aaa)
		{
			if(aaa.top_node==NULL)
			{
				top_node=NULL;
				node_num=0;
			}
			else
			{
				top_node=new Node(aaa.top_node->element,NULL);
				node_num=0;
				node_num++;
				Node* tail=top_node;
				Node* pnew;
				Node* bbb=aaa.top_node->next;
				int in1;
				for(in1=0;in1<aaa.node_num-1;in1++)
				{
					pnew=new Node(bbb->element,NULL);
					tail->next=pnew;
					tail=pnew;
					bbb=bbb->next;
					node_num++;
				}
			}
		}
		~Stack()
		{
			Node* aaa=top_node;
			while(aaa!=NULL)
			{
				top_node=top_node->next;
				delete aaa;
				aaa=top_node;
			}
			node_num=0;
		}
		bool empty()
		{
			if(top_node==NULL)
			return true;
			else
			return false;
		}
		size_t size() const
		{
			return node_num;
		}
		T top() const
		{
			if(top_node!=NULL)
			return top_node->element;
		}
		void push(T ele)
		{
			Node* aaa=new Node(ele);
			aaa->next=top_node;
			top_node=aaa;
			node_num++;
		}
		void pop()
		{
			if(top_node!=NULL)
			{
				Node* aaa=top_node;
				top_node=top_node->next;
				delete aaa;
				node_num--;
				aaa=NULL;
			}
		}
		void swap(Stack& aaa)
		{
			Node* exc;
			exc=top_node;
			top_node=aaa.top_node;
			aaa.top_node=exc;
		}
		void reverse()
		{
			if(top_node!=NULL)
			{
			Node* aaa=new Node(top_node->element,NULL);
			Node* tail=aaa;
			Node* head=aaa;
			Node* bbb=top_node->next;
			int in1;
			for(in1=0;in1<node_num-1;in1++)
			{
				head=new Node(bbb->element,tail);
				tail=head;
				bbb=bbb->next;
			}
			Node* ccc=top_node;
			while(ccc!=NULL)
			{
				top_node=top_node->next;
				delete ccc;
				ccc=top_node;
			}
			top_node=head;}
		}
		void clear()
		{
			Node* aaa=top_node;
			while(aaa!=NULL)
			{
				top_node=top_node->next;
				delete aaa;
				aaa=top_node;
			}
			node_num=0;
		}
	private:
		struct Node
{
	T element;
	Node* next;
	Node(T ele,Node* n=NULL)
	{
		element=ele;
		next=n;
	}
};
		Node* top_node;
		size_t node_num;	
};


