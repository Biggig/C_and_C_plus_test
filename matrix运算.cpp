#include <iostream>
using namespace std;

class Matrix    
{
public:
    Matrix();                                           //Ĭ�Ϲ��캯��
    ~Matrix();                                          //��������
    Matrix(const Matrix &);                             //�������캯��
    Matrix(int row, int col);                           //���������캯��  
    Matrix operator+(const Matrix &)const;              //�����������+��
    Matrix& operator=(const Matrix &);                  //�����������=��
    Matrix transpose()const;
	int getRow()const;
	int getCol()const;                           //�����ת��
    void display()const;                                //������ݺ���   
private:
    int row;                                            //�������
    int col;                                            //�������
    int** mat;                                          //���ڴ������
};

int Matrix::getCol()const
{
	return col;
}

int Matrix::getRow()const
{
	return row;
}

Matrix::Matrix()
{
	mat=NULL;
	col=0;
	row=0;
}

Matrix::Matrix(int aaa,int bbb)
{
	mat= new int *[aaa];
	int in3;
	for(in3=0;in3<aaa;in3++)
	{
		mat[in3]=new int [bbb];
	}
	int in1;
	for(in1=0;in1<aaa;in1++)
	{
		int in2;
		for(in2=0;in2<bbb;in2++)
		{
			cin >> mat[in1][in2];
		}
	}
	row=aaa;
	col=bbb; 
}

Matrix::Matrix(const Matrix& aaa)
{
	row=aaa.row;
	col=aaa.col;
	mat= new int *[row];
	int in3;
	for(in3=0;in3<row;in3++)
	{
		mat[in3]=new int [col];
	}
	int in1;
	for(in1=0;in1<row;in1++)
	{
		int in2;
		for(in2=0;in2<col;in2++)
		{
			mat[in1][in2]=aaa.mat[in1][in2];
		}
	 } 	
}

Matrix::~Matrix()
{
	int in1;
	for(in1=0;in1<row;in1++)
	{
		if(mat[in1]!=NULL)
		{
			delete  []mat[in1];
			mat[in1]=NULL;
		}
	}
	if(mat!=NULL)
	{
		delete []mat;
		mat=NULL;
	}
	
}

void Matrix::display()const
{
	int in4=1,in5=0;
	for(in4=0;in4<row;in4++)
	{
		for(in5=0;in5<col;in5++)
		{
			cout << mat[in4][in5] << " ";
	    }
		cout << endl;
	}
}


Matrix Matrix::operator+(const Matrix &aaa)const
{
	Matrix bbb;
	bbb.mat=new int *[aaa.row];
	int in3;
	for(in3=0;in3<aaa.row;in3++)
	{
		bbb.mat[in3]=new int [aaa.col];
	}	
	int in1;
	for(in1=0;in1<aaa.row;in1++)
	{
		int in2;
		for(in2=0;in2<aaa.col;in2++)
		{
			bbb.mat[in1][in2]=mat[in1][in2]+aaa.mat[in1][in2];	
		}
	}
	bbb.row=aaa.row;
	bbb.col=aaa.col;
	return bbb;
}

Matrix& Matrix::operator=(const Matrix&aaa)
{
	int in1;
	col=aaa.col;
	row=aaa.row;
	if(mat==NULL)
	{
	    mat= new int *[row];
	    int in3;
	    for(in3=0;in3<row;in3++)
	   {
		    mat[in3]=new int [col];
	   }	
	} 
	for(in1=0;in1<row;in1++)
	{
		int in2;
		for(in2=0;in2<col;in2++)
		{
			mat[in1][in2]=aaa.mat[in1][in2];	
		}
	}
	return *this;
}

Matrix Matrix::transpose()const
{
	Matrix aaa;
	aaa.mat=new int *[col];
	int in3;
	for(in3=0;in3<col;in3++)
	{
		aaa.mat[in3]=new int [row];
	}
	int in1;
	for(in1=0;in1<col;in1++)
	{
		int in2;
		for(in2=0;in2<row;in2++)
		{
			aaa.mat[in1][in2]=mat[in2][in1];
		}
	}
	 aaa.col=row;
	 aaa.row=col;
	return aaa;  
}

int main() {
	int row, col;
	cout << "input the row and the col for Matrix a, b" << endl;
	cin >> row >> col;
	Matrix a(row, col), b(row, col), c(a), d;
	cout << endl << "Matrix a:" << endl;//�����޷����� 
	a.display();//�����ڴ�й©�� 
	cout << endl << "Matrix b:" << endl;
	b.display();
	c = a + b;//�������������+��ʵ������������� 
	cout << endl << "Matrix c = Matrix a + Matrix b :" << endl;
	c.display();
	cout << endl << "Matrix a transpose to Matrix d:" << endl;
	d = a.transpose();
	d.display();
	return 0;
}
