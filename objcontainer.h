#include<iostream>
#include"obj.h"
using namespace std;

class objcontainer
{
	public:
		objcontainer(string str)
				 	:o(str)
		{
		}
		objcontainer(obj ob)
					:o(ob.str)
		{
			
		}
		obj* operator->()
		{
			return &o;
		} 
	private:
		obj o;
};

