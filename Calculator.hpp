#include"Exception.hpp"

#include<string.h>



class calculator
{
	public:
		calculator(){}
		bool validExpression(std::string str1)
		{
			const char* str=str1.c_str();
			if(str1=="")
			{
				EmptyExpressionException e;
				throw e;
				return false;
			}
			int num=strlen(str);
			int in1;
			for(in1=0;in1<num;in1++)
			{
				if((str[in1]<'0'||str[in1]>'9')&&(str[in1]!='+'&&str[in1]!='-'))
				{
					IllegalSymbolException e(in1);
					throw e;
					return false;
				}
				if((str[in1]=='+'||str[in1]=='-')&&in1==num-1)
				{
					throw MissingOperandException(in1+1);
					return false;					
				}
				if((str[in1]=='+'||str[in1]=='-')&&in1==0)
				{
					throw MissingOperandException(in1);
					return false;					
				}
				if((str[in1]=='+'||str[in1]=='-')&&(str[in1+1]=='+'||str[in1+1]=='-')&&in1<num-1&&in1!=0)
				{
					throw MissingOperandException(in1+1);
					return false;					
				}				
				if((str[in1]>='0'&&str[in1]<='9')&&(str[in1+1]>='0'&&str[in1+1]<='9')&&in1<num-1)
				{
					throw MissingOperatorException(in1+1);
					return false;					
				}
			}
			return true;
		}
		int calculate(std::string str1)
		{
			if(validExpression(str1))
			{
				const char* str=str1.c_str();
				int num=strlen(str);
				int total=str[0]-'0';
				int in1;
				for(in1=1;in1<num;in1=in1+2)
				{
					if(str[in1]=='+')
						total=total+str[in1+1]-'0';
					else
						total=total-(str[in1+1]-'0');	
				}
				return total;
			}
		}
		
};

