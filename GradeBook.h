#include<iostream>
using std::cout;
using std::endl;

#include<string>
using std::string;

class Gra
{
	public:
		Gra(string name)
		{
			set(name);
		}
		
		void set(string name)
		{
			courseName=name;
		}
		
		string get()
		{
			return courseName;
		}
		
		void display()
		{
			cout << "Welcome to the grade book for\n" << get() << "!" << endl;
		}
	private:
	    string courseName;	
};
