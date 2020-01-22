#include <iostream>
using namespace std;

class Matrix    
{
public:
    Matrix();                                           //默认构造函数
    ~Matrix();                                          //析构函数
    Matrix(const Matrix &);                             //拷贝构造函数
    Matrix(int row, int col);                           //含参数构造函数  
    Matrix operator+(const Matrix &)const;              //重载运算符“+”
    Matrix& operator=(const Matrix &);                  //重载运算符“=”
    Matrix transpose()const;
	int getRow()const;
	int getCol()const;                           //矩阵的转置
    void display()const;                                //输出数据函数   
private:
    int row;                                            //矩阵的行
    int col;                                            //矩阵的列
    int** mat;                                          //用于储存矩阵
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
	cout << endl << "Matrix a:" << endl;//下面无法运行 
	a.display();//？，内存泄漏？ 
	cout << endl << "Matrix b:" << endl;
	b.display();
	c = a + b;//用重载运算符“+”实现两个矩阵相加 
	cout << endl << "Matrix c = Matrix a + Matrix b :" << endl;
	c.display();
	cout << endl << "Matrix a transpose to Matrix d:" << endl;
	d = a.transpose();
	d.display();
	return 0;
}
