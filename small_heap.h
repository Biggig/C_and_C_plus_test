#include<vector>
#include<iostream>
using namespace std;

template <class T>
class heap//最小化堆,需改为可比较哈夫曼树节点的堆 
{
	public:
		heap()
		{}
		heap(const T* a,int size)
		{
			int i;
			for(i=0;i<size;i++)
				all.push_back(a[i]);
			for(i=(size-2)/2;i>=0;i--)
				AdjustDown(i);//从最后一个父节点调整	
		}
		void swap(T& a, T& b)
		{
			T exchange=a;
			a=b;
			b=exchange;
		}
		void Push(const T& x)
		{
			all.push_back(x);
			swap(all[0],all[all.size()-1]);
			AdjustDown(0);
		}
		void Pop()
		{
			if(!all.empty())
			{
				swap(all[0],all[all.size()-1]);
				all.pop_back();
				AdjustDown(0);
			}
		}
		T& Top()
		{
			if(!all.empty())
				return all[0];
		}
		bool Empty()
		{
			return all.empty();
		}
		int Size()
		{
			return all.size();
		}
		void AdjustDown(int root)
		{
			int child=root*2+1;
			while(child<all.size())
			{
				if(child+1<all.size()&&(all[child+1]<all[child]))
					child++;
				if(all[child]<all[root])
				{
					swap(all[child],all[root]);
					root=child;
					child=root*2+1;
				}
				else
					break;	
			}
		}
	private:
		vector<T> all;	
};

/*int main()
{
	int a[6]={3,2,5,6,7,8};
	heap<int> test(a,6);
	test.Push(11);
	int in1;
	for(in1=0;in1<7;in1++)
	{
		cout << test.Top() << endl;
		test.Pop();
	}
	return 0;
}*/ 
