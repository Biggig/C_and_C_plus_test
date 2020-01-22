 #include"SingleDog.h"
#include<string.h>

SingleDog::SingleDog(int id_,char* name_)
:id(id_)
{
  name=new char[20];
  strcpy(name,name_);
  count++;
}

SingleDog::SingleDog(const SingleDog &other)
  :id(other.id)
{
  name=new char[20];
  strcpy(name,other.name);
  count++;
}

SingleDog::~SingleDog()
{
  delete []name;
  count--;
}

int SingleDog::getCount()
{
  return count;
}

int SingleDog::count=0;
