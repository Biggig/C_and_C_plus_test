#include"fraction.h"
//溢出，中间化简 
fraction::fraction(const fraction &aaa)
{
	if(aaa._denominator==0||aaa._numerator==0)
	{
		_numerator=0;
		_denominator=0;
	}
	else
	{
		_numerator=aaa._numerator;
	    _denominator=aaa._denominator;
	    this->simp();
	}
}

fraction::fraction(const int &aaa,const int &bbb)
{
	if(aaa==0||bbb==0)
	{
		_numerator=0;
		_denominator=0;
	}
	else
	{
		_numerator=aaa;
	    _denominator=bbb;
	    this->simp();
	}
}

int fraction::gcd(const int& aaa,const int& bbb) const
{
	if(aaa==0||bbb==0)
	return 0;
	else
	{
		int fenzi=aaa;
	    int yushu=bbb%aaa;
	    int mid;
	    while(yushu!=0)
	   {
		    mid=yushu;
		    yushu=fenzi%yushu;
		    fenzi=mid;
	   }
	    return fenzi;
	}
}

void fraction::simp()
{
	int aaa=gcd(_numerator,_denominator);
	if(aaa==0)
	{
		_numerator=0;
		_denominator=0;
	}
	else
	{
		_numerator=_numerator/aaa;
	    _denominator=_denominator/aaa;
	}
	
}

void fraction::operator=(const fraction& aaa)
{
	if(aaa._numerator==0||aaa._denominator==0)
	{
		_numerator=0;
		_denominator=0;
	}
	else
	{
		_numerator=aaa._numerator;
	    _denominator=aaa._denominator;
	    this->simp();
	}
}

fraction fraction::operator+(const fraction& aaa) const
{
	fraction bbb;
	if(_denominator==0||aaa._denominator==0)
	{
		bbb._numerator=0;
		bbb._denominator=0;
	}
	else
	{
		int in1=_denominator/gcd(_denominator,aaa._denominator);
		int in2=aaa._denominator/gcd(_denominator,aaa._denominator);
	    int fenmu=in1*in2*gcd(_denominator,aaa._denominator);
	    int fenzi=_numerator*in2+aaa._numerator*in1;
	    bbb._numerator=fenzi;
	    bbb._denominator=fenmu;
		bbb.simp();		
	}
	return bbb;
}

fraction fraction::operator-(const fraction& aaa) const
{
	fraction bbb;
	if(_denominator==0||aaa._denominator==0)
	{
		bbb._numerator=0;
		bbb._denominator=0;
	}
	else
	{
		int in1=_denominator/gcd(_denominator,aaa._denominator);
		int in2=aaa._denominator/gcd(_denominator,aaa._denominator);
	    int fenmu=in1*in2*gcd(_denominator,aaa._denominator);
	    int fenzi=_numerator*in2-aaa._numerator*in1;
	    bbb._numerator=fenzi;
	    bbb._denominator=fenmu;		
	}
	return bbb;	
}
fraction fraction::operator*(const fraction& aaa) const
{
	fraction bbb;
	if(_denominator==0||aaa._denominator==0)
	{
		bbb._numerator=0;
		bbb._denominator=0;
	}
	else
	{
		bbb=*this;
	    bbb*=aaa;		
	}
	return bbb;
}

fraction fraction::operator/(const fraction& aaa) const
{
	fraction bbb;
	if(_denominator==0||aaa._numerator==0||aaa._denominator==0)
	{
		bbb._numerator=0;
		bbb._denominator=0;
	}
	else
	{
		bbb=*this;
		bbb/=aaa;
	}
	return bbb;
}

void fraction::operator+=(const fraction& aaa)
{
	if(_denominator==0||aaa._denominator==0)
	{
		_numerator=0;
		_denominator=0;
	}
	else
	{
		int in1=_denominator/gcd(_denominator,aaa._denominator);
		int in2=aaa._denominator/gcd(_denominator,aaa._denominator);
	    int fenmu=in1*in2*gcd(_denominator,aaa._denominator);
	    int fenzi=_numerator*in2+aaa._numerator*in1;
		_numerator=fenzi;
		_denominator=fenmu;
	}
}

void fraction::operator-=(const fraction& aaa)
{
	if(_denominator==0||aaa._denominator==0)
	{
		_denominator=0;
		_numerator=0;
	}
	else
	{
		int in1=_denominator/gcd(_denominator,aaa._denominator);
		int in2=aaa._denominator/gcd(_denominator,aaa._denominator);
	    int fenmu=in1*in2*gcd(_denominator,aaa._denominator);
	    int fenzi=_numerator*in2-aaa._numerator*in1;
		_numerator=fenzi;
		_denominator=fenmu;
		this->simp();
	}	
}

void fraction::operator*=(const fraction& aaa) 
{
	if(_denominator==0||aaa._denominator==0)
	{
		_denominator=0;
		_numerator=0;
	}
	else
	{
	    fraction bbb=aaa;
	    int in1=gcd(_denominator,bbb._numerator);
	    _denominator=_denominator/in1;
	    bbb._numerator=bbb._numerator/in1;
	    int in2=gcd(_numerator,bbb._denominator);
	    _numerator=_numerator/in2;
	    bbb._denominator=bbb._denominator/in2;
	    int fenmu=_denominator*bbb._denominator;
	    int fenzi=_numerator*bbb._numerator;
	    _numerator=fenzi;
	    _denominator=fenmu;		
	}
}

void fraction::operator/=(const fraction& aaa)
{
	if(_denominator==0||aaa._numerator==0||aaa._denominator==0)
	{
		_numerator=0;
		_denominator=0;
	}
	else
	{
		fraction ccc=aaa;
	    int in1=gcd(_denominator,ccc._denominator);
	    _denominator=_denominator/in1;
	    ccc._denominator=ccc._denominator/in1;
	    int in2=gcd(_numerator,ccc._numerator);
	    _numerator=_numerator/in2;
	    ccc._numerator=ccc._numerator/in2;
		int fenmu=_denominator*ccc._numerator;
	    int fenzi=_numerator*ccc._denominator;
	    _numerator=fenzi;
	    _denominator=fenmu;		
	}	
}

bool fraction::operator==(const fraction& aaa) const
{
	fraction bbb=*this;
	fraction ddd=aaa;
	bbb.simp();
	ddd.simp();
	if(bbb._numerator==ddd._numerator&&bbb._denominator==ddd._denominator)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool fraction::operator!=(const fraction& aaa) const
{
	fraction bbb=*this;
	fraction ddd=aaa;
	bbb.simp();
	ddd.simp();
	if(bbb._numerator==ddd._numerator&&bbb._denominator==ddd._denominator)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool fraction::operator<(const fraction& aaa) const
{
	fraction bbb=*this;
	fraction ddd=aaa;
	bbb.simp();
	ddd.simp();
	if(bbb._denominator<0&&bbb._numerator<0)
	{
	    bbb._denominator=-bbb._denominator;
		bbb._numerator=-bbb._numerator;	
	}
	if(bbb._denominator<0&&bbb._numerator>0)
	{
	    bbb._denominator=-bbb._denominator;
		bbb._numerator=-bbb._numerator;		
	}
	if(ddd._denominator<0&&ddd._numerator<0)
	{
	    ddd._denominator=-ddd._denominator;
		ddd._numerator=-ddd._numerator;	
	}
	if(ddd._denominator<0&&ddd._numerator>0)
	{
	    ddd._denominator=-ddd._denominator;
		ddd._numerator=-ddd._numerator;		
	}
	int in1=bbb._denominator/gcd(bbb._denominator,ddd._denominator);
	int in2=ddd._denominator/gcd(bbb._denominator,ddd._denominator);
	bbb._denominator=in1*in2*gcd(bbb._denominator,ddd._denominator);
	ddd._numerator=ddd._numerator*in1;
	bbb._numerator=bbb._numerator*in2;
	ddd._denominator=in1*in2*gcd(bbb._denominator,ddd._denominator);
	if(bbb._numerator<ddd._numerator)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool fraction::operator>(const fraction &aaa) const
{
	fraction bbb=*this;
	fraction ddd=aaa;
	bbb.simp();
	ddd.simp();
	if(bbb._denominator<0&&bbb._numerator<0)
	{
	    bbb._denominator=-bbb._denominator;
		bbb._numerator=-bbb._numerator;	
	}
	if(bbb._denominator<0&&bbb._numerator>0)
	{
	    bbb._denominator=-bbb._denominator;
		bbb._numerator=-bbb._numerator;		
	}
	if(ddd._denominator<0&&ddd._numerator<0)
	{
	    ddd._denominator=-ddd._denominator;
		ddd._numerator=-ddd._numerator;	
	}
	if(ddd._denominator<0&&ddd._numerator>0)
	{
	    ddd._denominator=-ddd._denominator;
		ddd._numerator=-ddd._numerator;		
	}	
	int in1=bbb._denominator/gcd(bbb._denominator,ddd._denominator);
	int in2=ddd._denominator/gcd(bbb._denominator,ddd._denominator);
	bbb._denominator=in1*in2*gcd(bbb._denominator,ddd._denominator);
	ddd._numerator=ddd._numerator*in1;
	bbb._numerator=bbb._numerator*in2;
	ddd._denominator=in1*in2*gcd(bbb._denominator,ddd._denominator);
	if(bbb._numerator>ddd._numerator)
	{
		return true;
	}
	else
	{
		return false;
	}	
}

bool fraction::operator<=(const fraction &aaa) const
{
	fraction bbb=*this;
	fraction ddd=aaa;
	bbb.simp();
	ddd.simp();
	if(bbb._denominator<0&&bbb._numerator<0)
	{
	    bbb._denominator=-bbb._denominator;
		bbb._numerator=-bbb._numerator;	
	}
	if(bbb._denominator<0&&bbb._numerator>0)
	{
	    bbb._denominator=-bbb._denominator;
		bbb._numerator=-bbb._numerator;		
	}
	if(ddd._denominator<0&&ddd._numerator<0)
	{
	    ddd._denominator=-ddd._denominator;
		ddd._numerator=-ddd._numerator;	
	}
	if(ddd._denominator<0&&ddd._numerator>0)
	{
	    ddd._denominator=-ddd._denominator;
		ddd._numerator=-ddd._numerator;		
	}
	int in1=bbb._denominator/gcd(bbb._denominator,ddd._denominator);
	int in2=ddd._denominator/gcd(bbb._denominator,ddd._denominator);
	bbb._denominator=in1*in2*gcd(bbb._denominator,ddd._denominator);
	ddd._numerator=ddd._numerator*in1;
	bbb._numerator=bbb._numerator*in2;
	ddd._denominator=in1*in2*gcd(bbb._denominator,ddd._denominator);
	if(bbb._numerator<=ddd._numerator)
	{
		return true;
	}
	else
	{
		return false;
	}	
}

bool fraction::operator>=(const fraction &aaa) const
{
	fraction bbb=*this;
	fraction ddd=aaa;
	bbb.simp();
	ddd.simp();
	if(bbb._denominator<0&&bbb._numerator<0)
	{
	    bbb._denominator=-bbb._denominator;
		bbb._numerator=-bbb._numerator;	
	}
	if(bbb._denominator<0&&bbb._numerator>0)
	{
	    bbb._denominator=-bbb._denominator;
		bbb._numerator=-bbb._numerator;		
	}
	if(ddd._denominator<0&&ddd._numerator<0)
	{
	    ddd._denominator=-ddd._denominator;
		ddd._numerator=-ddd._numerator;	
	}
	if(ddd._denominator<0&&ddd._numerator>0)
	{
	    ddd._denominator=-ddd._denominator;
		ddd._numerator=-ddd._numerator;		
	}	
	int in1=bbb._denominator/gcd(bbb._denominator,ddd._denominator);
	int in2=ddd._denominator/gcd(bbb._denominator,ddd._denominator);
	bbb._denominator=in1*in2*gcd(bbb._denominator,ddd._denominator);
	ddd._numerator=ddd._numerator*in1;
	bbb._numerator=bbb._numerator*in2;
	ddd._denominator=in1*in2*gcd(bbb._denominator,ddd._denominator);
	if(bbb._numerator>=ddd._numerator)
	{
		return true;
	}
	else
	{
		return false;
	}	
}

std::istream & operator>>(std::istream &in, fraction &aaa)
{
	in >> aaa._numerator ;
	in >> aaa._denominator;
	return in;
}

std::ostream & operator<<(std::ostream &out, const fraction &aaa)
{
	fraction bbb=aaa;
	bbb.simp();
	if(bbb._denominator<0&&bbb._numerator<0)
	{
	    bbb._denominator=-bbb._denominator;
		bbb._numerator=-bbb._numerator;	
	}
	if(bbb._denominator<0&&bbb._numerator>0)
	{
	    bbb._denominator=-bbb._denominator;
		bbb._numerator=-bbb._numerator;		
	}
	out << bbb._numerator << '/' << bbb._denominator;
	return out;
}
