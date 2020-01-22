 #include<iostream>
using namespace std;

class A
{
public:
    A()
    {
    }
    virtual ~A()
    {
    cout<<"A::~A()called"<<endl;
    }    
    virtual void Prin()
    {
    cout<<"Prin come from class A"<<endl;
    }
    
};

class B:public A
{
char* buf;
public:
    B(int bbb)
      :A()
    {

    }
    ~B()
    {
    cout<<"B::~B()called"<<endl;
    }
    void Prin()
    {
    cout<<"Prin come from class B"<< endl;
    }
};

void fun(A* aaa)
{
delete aaa;
}

int main()
{
A *a=new B(10);
a->Prin();
fun(a);
B* b=new B(20);
fun(b);
return 0;
}
