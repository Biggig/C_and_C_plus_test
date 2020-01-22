#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

#include"huffmanTree.h"

void getCode(HuffmanNode* root,vector<string> &HT_code,string code)
{
	if(root!=NULL)
	{
		if(root->left==NULL&&root->right==NULL)
		{
			HT_code[root->key]=code;
		}	
		else
		{
			getCode(root->left,HT_code,code+"0");
			getCode(root->right,HT_code,code+"1");
		}	
	}	
} 

string translate(char c)
{
	string str;
	str.empty();
	int in1;
	for(in1=0;in1<8;in1++)
	{
		int g=c%2;
		if(g==0)
			str.push_back('0');
		else
			str.push_back('1');
		c=c/2;		
	}
	string strl;
	strl.empty();
	const char* add=str.c_str();
	for(in1=7;in1>=0;in1--)
		strl.push_back(add[in1]);
	return strl;	
}

int main(int argc,char **argv)
{
	ifstream inputF(argv[1]);//创建输入文件
	while(!inputF)
	{
		cerr << "open error for inputFile!" << endl;
		exit(1);
	}

	ofstream outputF(argv[2]);//创建输出文件 
	while(!outputF)
	{
		cerr << "open error for outputFile!" << endl;
		exit(1);
	}
	
	int dif;
	int counter;
	int all[256];
	HuffmanTree HT;//生成哈夫曼树
	vector<string> HT_code;//哈夫曼编码
	string code;
	code.empty(); 
	
	inputF >> dif >> counter;

	
	//初始化 
	for(int inr=0;inr<256;inr++)
		all[inr]=0;	
	for(int cou=0;cou<256;cou++)
		HT_code.push_back(code);
		
	for(int in1=0;in1<dif;in1++)
	{
		char fuhao;
		int weight;
		inputF >> fuhao >> weight;
		all[fuhao]=weight;
	}
	 
	
	for(int in1=0;in1<256;in1++)
	{
		if(all[in1]!=0)
		{
			dif++;
			HuffmanNode* in=new HuffmanNode(all[in1],in1);//哈夫曼节点包含字符及其出现次数 
			HT.getNode(in);
		}
	}	
	
	HT.buildTree();
	HuffmanNode* HT_root=HT.getRoot();//哈夫曼树根节点
	int cou;	
	for(cou=0;cou<256;cou++)
		HT_code.push_back(code);
	getCode(HT_root,HT_code,code);//获取哈夫曼编码
		
	char c;
	string str;
	while(inputF >> c)//转成01串 
	{
		string s=translate(c); 
		str=str+s;
	}	
	

	const char* cc=str.c_str();
	int c_num=str.size();
	int posi=0;
	string test;
	test.empty();
	for(posi=c_num;posi>=0;posi--)
	{
		test.push_back(cc[posi]);
		int in1;
		for(in1=0;in1<256;in1++)
		{
			if(test==HT_code[in1]&&counter!=0)
			{
				char oo;
				oo=in1;
				outputF << oo;
				test.empty();
				counter--;
				break;
			}				 
		}
	} 
	
	HT.clear(); 
	outputF.close();
	inputF.close();	 
	return 0;						
}
