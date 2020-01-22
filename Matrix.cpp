#include"Matrix.h"



Matrix::Matrix(string aaa,int hei,int wid,int** pa)
{
	name=aaa;
	height=hei;
	width=wid;
	param=pa;
	param=new int*[height];
	int in1;
	for(in1=0;in1<height;in1++)
	param[in1]=new int[width];
	for(in1=0;in1<height;in1++)
	{
		int in2;
		for(in2=0;in2<width;in2++)
		param[in1][in2]=pa[in1][in2];
	}
}

Matrix::Matrix(const Matrix &aaa)
{
	name=aaa.name;
	height=aaa.height;
	width=aaa.width;
	param=new int*[height];
	int in1;
	for(in1=0;in1<height;in1++)
	param[in1]=new int[width];
	for(in1=0;in1<height;in1++)
	{
		int in2;
		for(in2=0;in2<width;in2++)
		param[in1][in2]=aaa.param[in1][in2];
	}
}

Matrix::~Matrix()
{
	int in1;
	for(in1=0;in1<height;in1++)
	delete []param[in1];
	delete []param;
}

bool Matrix::operator ==(const Matrix& aaa)
{
	int in1;
	if(height!=aaa.height||width!=aaa.width)
	return false;
	else
	{
		int counter=0;
	    for(in1=0;in1<height;in1++)
	    {
		    int in2;
		    for(in2=0;in2<width;in2++)
		    {
		    	if(param[in1][in2]==aaa.param[in1][in2])
		    	counter++;
		    }
	    }
	    if(counter==width*height)
	    return true;
	    else
	    return false;
	}
}

bool Matrix::operator !=(const Matrix& aaa)
{
	int in1;
	if(height!=aaa.height||width!=aaa.width)
	return true;
	else
	{
		int counter=0;
	    for(in1=0;in1<height;in1++)
	    {
		    int in2;
		    for(in2=0;in2<width;in2++)
		    {
		    	if(param[in1][in2]==aaa.param[in1][in2])
		    	counter++;
		    }
	    }
	    if(counter!=width*height)
	    return true;
	    else
	    return false;
	}
}

void Matrix::operator +=(const Matrix& aaa)
{
	if(width!=aaa.width||height!=aaa.height)
	{
		cout << "invalid addition." << endl;	
	}
	else
	{
	int in1;
	for(in1=0;in1<height;in1++)
	{
		int in2;
		for(in2=0;in2<width;in2++)
		param[in1][in2]=param[in1][in2]+aaa.param[in1][in2];
	}
	}

}

void Matrix::operator -=(const Matrix&aaa)
{
	if(width!=aaa.width||height!=aaa.height)
	{
		cout << "invalid substraction." << endl;	
	}
	else
	{
			int in1;
	for(in1=0;in1<height;in1++)
	{
		int in2;
		for(in2=0;in2<width;in2++)
		param[in1][in2]=param[in1][in2]-aaa.param[in1][in2];
	}
	}
}

Matrix Matrix::operator *(const Matrix& aaa)
{
	if(width!=aaa.height)
	{
		cout << "invalid multiplication." << endl;
		Matrix bbb;
		return bbb;
	}
	else
	{
	int h3=height;
	int w3=aaa.width;
	int** pa3=new int*[h3];
	int in1;
	for(in1=0;in1<h3;in1++)
	pa3[in1]=new int [w3];
	for(in1=0;in1<height;in1++)
	{
		int in2;
		for(in2=0;in2<aaa.width;in2++)
		{
			int num=0;
			int in3;
			for(in3=0;in3<width;in3++)
			{
				num=num+param[in1][in3]*aaa.param[in3][in2];
				pa3[in1][in2]=num;
			}
		}
	}
	Matrix bbb("newMat",h3,w3,pa3);
	int in6;
	for(in6=0;in6<h3;in6++)
	delete []pa3[in6];
	delete []pa3;	
	return bbb;
	}
}
