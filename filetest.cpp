#include <fstream>
using namespace std;
 
int main
{
	fstream aaa;
 
	aaa.open("Example");		
 
	aaa<<"Hello file/n"<<75;		
 
	aaa.close();
	return 0;				
}
