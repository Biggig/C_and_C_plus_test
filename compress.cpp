#include<fstream>
#include<string>
#include<bitset>
#include<iomanip>
#include<cmath>
using namespace std;

#include"huffman.h"

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

int translate(string str )
{
	int num=0;
	const char* c=str.c_str();
	int in1;
	for(in1=0;in1<8;in1++)
	{
		num=num+(c[in1]-'0')*pow(2,7-in1);
	}
	return num;
}


//>huffmanCoding inputfile outputfile
int main(int argc,char **argv)//�ѿɶ����ı���ȫ���ַ� 
{ 
	ifstream inputF(argv[1]);//���������ļ�
	while(!inputF)
	{
		cerr << "open error for inputFile!" << endl;
		exit(1);
	}
	
	string outN=argv[2];
	outN=outN+".huf";
	ofstream outputF(outN);//��������ļ� 
	while(!outputF)
	{
		cerr << "open error for outputFile!" << endl;
		exit(1);
	}
	
	unsigned char in;//�Ȳ����Ǻ��� 
	int all[256];//�����ַ�������ֵĴ���,�±��Ӧ�ַ�
	int inr;
	for(inr=0;inr<256;inr++)
		all[inr]=0;
	int counter=0;//�ַ�ͳ�ƣ�
	while(inputF >> in)//�������ı��е��ַ�����
	{
		int in2;
		for(in2=0;in2<256;in2++)
		{
			if(in2==in)
			{
				all[in2]=all[in2]+1;
				break;
			}
		}
		counter++; 
	}	
	
	
	int in1;
	HuffmanTree HT;//���ɹ�������
	int dif=0;
	for(in1=0;in1<256;in1++)
	{
		if(all[in1]!=0)
		{
			dif++;
			HuffmanNode* in=new HuffmanNode(all[in1],in1);//�������ڵ�����ַ�������ִ��� 
			HT.getNode(in);
		}
	}	

	HT.buildTree();
	HuffmanNode* HT_root=HT.getRoot();//�����������ڵ�

	vector<string> HT_code;//���������� 
	int cou;	
	string code;
	code.empty();
	for(cou=0;cou<256;cou++)
		HT_code.push_back(code);
	getCode(HT_root,HT_code,code);//��ȡ����������
	
	inputF.close();//�ر������ļ�
		
	outputF << dif << " ";//������Ϣ����ͬ�ַ������ַ�������char��weight 
	outputF << counter << " ";
	for(in1=0;in1<256;in1++)
	{
		if(all[in1]!=0)
		{
			outputF << in1 << " " << all[in1] << " ";
		}
	}	 
	outputF.close();
		
	ifstream input(argv[1]);//�ٴδ��������ļ�
	while(!input)
	{
		cerr << "open error for inputFile!" << endl;
		exit(1);
	}
	
	
	ofstream output(outN,ios::binary|ios::app);//��������ļ� 
	while(!output)
	{
		cerr << "open error for outputFile!" << endl;
		exit(1);
	}

	
	int i=0;
	string str;
	str.empty();	
	while(input >> in)//�������ı��е��ַ�ת��Ϊ���������룬����bitset,�����뵽ѹ���ļ� 
	{
		string exm=HT_code[in];
		str=str+exm;	
	}

	int s=str.size();
	output.write((char*)&s,sizeof(int));
	
	while(str.size()%8!=0)
	{
		str.push_back('0');
	}
	
	string res_text;
	while(i<str.size())
	{
		string sub_str=str.substr(i,8);
		char c=translate(sub_str);
		res_text.push_back(c);
		i=i+8;
	}

	output.write(res_text.c_str(),res_text.size()*sizeof(char));

	HT.clear(); 
	output.close();
	input.close(); 
	return 0;
} 
