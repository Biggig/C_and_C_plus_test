#include"Selectlesson.h"

void starter()//开头判断是否要进入系统 
{
	cout << endl;
	cout << "Welcome to lesson selecting system!" << endl;
	cout << "Now please select your order." << endl;
	cout << "1.use this system" << endl;
	cout << "2.quit this system" << endl;
	cout << "Enter your order: "; 
	return ; 
}

void forStarter(int ord,fstream& aaa)//接收指令，判断是否进入 
{
	if(ord==1)
	{
	    cout << endl; 
		cout << "Please enter your identity.(Teacher or Student)" << endl;
		cout << "Then,enter your name." << endl;
		return;
	}
	else
	quit(aaa);
}

int existedIdentity(string _name,string _identity)
{
	if(numOfUsers==0)
	return 0;
	else
	{
		int in1;
		int counter=0;
		for(in1=0;in1<numOfUsers;in1++)
		{
			if(users[in1].getUserName()==_name&&users[in1].getIdentity()==_identity)
			break;
			else
			counter++;
		}
		if(counter==numOfUsers)
		return 0;
		else
		return in1+1;//避免有效返回值==0 
	}
}

void printForTeacher()
{
	cout << endl;
	cout << "Please select the order you need:" << endl;
	cout << "1.open lesson     2.delete lesson" << endl;
	cout << "3.check time      4.check place  " << endl;
	cout << "5.check num of students          " << endl;
	cout << "6.list all lessons               " << endl;
	cout << "7.list your lessons              " << endl;
	cout << "8.exit the system                " << endl;
	cout << "9.make an reentry                " << endl;
	cout << "Enter your order: ";
    return ;
}

void printForStudent()
{
	cout << endl;
    cout << "Please select the order you need:" << endl;
    cout << "1.list your lessons  2.select lesson" << endl;
	cout << "3.drop lesson       4.check time   " << endl;
	cout << "5.check place       6.check students" << endl;
	cout << "7.list all lessons                  " << endl; 
	cout << "7.exit the system                   " << endl;	
    cout << "8.make an reentry                " << endl;    
	cout << "Enter your order: ";
	return ;
}

void printForLessons(lesson& _les)
{
	cout << endl;
	cout << "Name of Lesson: " << _les.getNameOfLesson() << endl;
	cout << "Teacher for Lesson: " << _les.getNameOfTeacher() << endl;
	cout << "Place for Lesson: " << _les.getPlace() << endl;
	cout << "Time for Lesson: " << _les.getTime() << endl;
	cout << "Num of Students: " << _les.getNumOfStudents() << endl;
	cout << endl ;
	return;
}

void listLessons(lesson* _les,int num)
{
	if(num==0)
	{
		cout << endl;
		cout << "Sorry,there are no lessons." << endl;
		return ;
	}
	int in1;
	for(in1=0;in1<num;in1++)
	{
		if(lessons[in1].getNameOfLesson()!="deleted")
		printForLessons(lessons[in1]);
	}
}

user::user()
{
	numOfLessons=0;
}

user::user(string& _identity, string& _name)
{
	setUser( _identity, _name);
}

void user::setUser(string& _identity, string& _name)
{
	identity=_identity;
	userName=_name;
	numOfLessons=0;
}

string user::getIdentity() const
{
	return this->identity;
}

string user::getUserName() const
{
	return this->userName;
}

int user::getNumOfLessons() const
{
	return numOfLessons;
}

lesson::lesson()
{
	numOfStudents=0;
}

lesson::lesson(string nameOfLesson,string nameOfTeacher,string time,string place,int num)
{
	setLesson(nameOfLesson,nameOfTeacher,time,place,num);
}

void lesson::setLesson(string _nameOfLe,string _name,string _time,string _place,int num)
{
	nameOfLesson=_nameOfLe;
	nameOfTeacher=_name;
	numOfStudents=num;
	time=_time;
	place=_place; 
}

string lesson::getTime() const
{
	return time;
}

string lesson::getPlace() const
{
	return place;
}

int lesson::getNumOfStudents() const
{
	return numOfStudents;
}

string lesson::getNameOfTeacher() const
{
	return nameOfTeacher;
}

string lesson::getNameOfLesson() const
{
	return nameOfLesson;
}

void lesson::addNumOfStudents()
{
	numOfStudents++;
}

void lesson::subNumOfStudents()
{
	numOfStudents--;
}

void openLesson(user& tea)
{
	cout << endl;
	cout << "Please enter the name of the lesson you want to open:" << endl;
	string _name;
	cin >> _name;
	int in1;
	int counter=0;
	for(in1=0;in1<numOfLessons;in1++)
	{
		if(_name==lessons[in1].getNameOfLesson())
		{
			counter=1;
			break;
		}
	}
	if(counter==1)
	{
		cout << endl;
		cout << "Sorry,the lesson has existed.\nYou can't open it." << endl;
	}
	else
	{
		string _time;
		string _place;
		string _tea;
		cout << "Please enter your name again: " << endl;
		cin >> _tea;
		cout << "Please enter the time for lesson: " << endl;
		cin >> _time;
		cout << "Please enter the place for lesson: " << endl;
		cin >> _place;
		lessons[numOfLessons].setLesson(_name,_tea,_time,_place);
		numOfLessons++;
		tea._lessons[tea.numOfLessons].setLesson(_name,_tea,_time,_place);
		tea.numOfLessons++;
		cout << endl;
		cout << "Open new lesson successfully!" << endl;
		printForLessons(lessons[numOfLessons-1]); 
	}
}

void selectLesson(user& stu)
{
	cout << endl;
	cout << "Please enter the name of the lesson you want to delete:" << endl;
	string _name;
	cin >> _name;
	int in1;
	int counter=0;
	for(in1=0;in1<numOfLessons;in1++)
	{
		if(_name==lessons[in1].getNameOfLesson())
		{
			break;
		}
		else
		{
			counter++;
		}
	}
	if(counter==numOfLessons)
	{
		cout << endl;
		cout << "Sorry,the lesson doesn't' exist.\nYou can't select it." << endl;
	}
	else
	{
		stu._lessons[stu.numOfLessons].setLesson(lessons[in1].getNameOfLesson(),lessons[in1].getNameOfTeacher(),lessons[in1].getTime(),lessons[in1].getPlace());
		stu.numOfLessons++;
		lessons[in1].addNumOfStudents();
		cout << endl;
		cout << "Select the lesson successfully!" << endl;
	}
}

void deleteLesson(user& tea)
{
	cout << endl;
	cout << "Please enter the name of the lesson you want to delete:" << endl;
	string _name;
	cin >> _name;
	int in1;
	int counter=0;
	for(in1=0;in1<numOfLessons;in1++)
	{
		if(_name==lessons[in1].getNameOfLesson())
		{
			break;
		}
		else
		{
			counter++;
		}
	}
	if(counter==numOfLessons)
	{
		cout << endl;
		cout << "Sorry,the lesson doesn't' exist.\nYou can't delete it." << endl;
	}
	else
	{
		lessons[in1].setLesson("deleted","deleted","deleted","deleted");
		int in2;
		for(in2=0;in2<tea.numOfLessons;in2++)
		{
			if(tea._lessons[in1].getNameOfLesson()==_name)
			{
				tea._lessons[in1].setLesson("deleted","deleted","deleted","deleted");
			}
		}
		cout << endl;
		cout << "Delete the lesson successfully!" << endl;
	}	
}

void dropLesson(user& stu)
{
	cout << endl;
	cout << "Please enter the name of the lesson you want to drop:" << endl;
	string _name;
	cin >> _name;
	int in1;
	int counter=0;
	for(in1=0;in1<stu.numOfLessons;in1++)
	{
		if(stu._lessons[in1].getNameOfLesson()==_name)
		{
			break;
		}
		else
		{
			counter++;
		}
	}
	if(counter==stu.numOfLessons)
	{
		cout << endl;
		cout << "Sorry,you didn't select this lesson" << endl;
	}
	else
	{
		stu._lessons[in1].setLesson("deleted","deleted","deleted","deleted");
	    int in2;
	    for(in2=0;in2<numOfLessons;in2++)
	    {
	    	if(_name==lessons[in2].getNameOfLesson())
	    	{
	    		lessons[in2].subNumOfStudents();
	    		cout << endl;
	    		cout << "Drop the lesson successfully!" << endl;
			}
		}
	}	
}

void checkNumOfStudents(string _les) 
{
	int in1;
	int counter=0;
	for(in1=0;in1<numOfLessons;in1++)
	{
		if(lessons[in1].getNameOfLesson()==_les)
		{
			counter++;
			break;
		}
	}
	if(counter==0)
	{
		cout << endl;
		cout << "Sorry,this lesson doesn't exist" << endl;
	}
	else
	{
		cout << endl;
		cout << "The num of students of the lesson is: " << lessons[in1].getNumOfStudents() << endl;
	}
}

void checkTime(string _les)
{
	int in1;
	int counter=0;
	for(in1=0;in1<numOfLessons;in1++)
	{
		if(lessons[in1].getNameOfLesson()==_les)
		{
			counter++;
			break;
		}
	}
	if(counter==0)
	{
		cout << endl;
		cout << "Sorry,this lesson doesn't exist" << endl;
	}
	else
	{
		cout << endl;
		cout << "The time for the lesson is: " << lessons[in1].getTime() << endl;
	}
}

void checkPlace(string _les)
{
	int in1;
	int counter=0;
	for(in1=0;in1<numOfLessons;in1++)
	{
		if(lessons[in1].getNameOfLesson()==_les)
		{
			counter++;
			break;
		}
	}
	if(counter==0)
	{
		cout << endl;
		cout << "Sorry,this lesson doesn't exist" << endl;
	}
	else
	{
		cout << endl;
		cout << "The place for lesson is: " << lessons[in1].getNameOfLesson() << endl;
	} 
}

void quit(fstream& file1)
{
    cout << endl; 
	cout << "Thank you for using this system,goodbye!" << endl;
	file1 << numOfLessons;
	file1 << numOfUsers;
	int in3;
	for(in3=0;in3<numOfLessons;in3++)
	{

		file1 << lessons[in3].getNameOfLesson() << ' '; 
		file1 << lessons[in3].getNameOfTeacher() << ' ';
		file1 << lessons[in3].getNumOfStudents() << ' ';
		file1 << lessons[in3].getTime() << ' ';
		file1 << lessons[in3].getPlace() << ' ';
	}
	for(in3=0;in3<numOfUsers;in3++)
	{
		file1 << users[in3].getIdentity() << ' ';
		file1 << users[in3].getUserName() << ' ';
		int in4;
		for(in4=0;in4<users[in3].numOfLessons;in4++)
		{
			file1 << users[in3]._lessons[in4].getNameOfLesson() << ' ';
			file1 << users[in3]._lessons[in4].getNameOfTeacher() << ' ';
			file1 << users[in3]._lessons[in4].getNumOfStudents() << ' ';
			file1 << users[in3]._lessons[in4].getTime() << ' ';
			file1 << users[in3]._lessons[in4].getPlace() << ' ';
		}
		file1.close();
		exit(0);
	}
}

void acceptOrderOfTeacher(int order,user Tea,fstream& aaa)
{
	string checker;
	int _order;
	switch(order)
	{
		case 1: openLesson(Tea);
		        printForTeacher();
				cin >> _order;
				acceptOrderOfTeacher(_order,Tea,aaa);		        
		        break;
		case 2: deleteLesson(Tea);
		        printForTeacher();
				cin >> _order;
				acceptOrderOfTeacher(_order,Tea,aaa);		        
		        break;
		case 3: cout << "Please enter the name of the lesson you want to check:" << endl;
		        cin >> checker;
				checkTime(checker);
				printForTeacher();
				cin >> _order;
				acceptOrderOfTeacher(_order,Tea,aaa);		        
		        break;
		case 4: cout << "Please enter the name of the lesson you want to check:" << endl;
		        cin >> checker;
		        checkPlace(checker);
		        printForTeacher();
				cin >> _order;
				acceptOrderOfTeacher(_order,Tea,aaa);
		        break;
		case 5: cout << "Please enter the name of the lesson you want to check:" << endl;
		        cin >> checker;
		        checkNumOfStudents(checker);
		        printForTeacher();
				cin >> _order;
				acceptOrderOfTeacher(_order,Tea,aaa);
		        break;
		case 6: listLessons(lessons,numOfLessons);
		        printForTeacher();
				cin >> _order;
				acceptOrderOfTeacher(_order,Tea,aaa);		        
		        break;      
		case 7: listLessons(Tea._lessons,Tea.numOfLessons);
		        printForTeacher();
				cin >> _order;
				acceptOrderOfTeacher(_order,Tea,aaa);		        
		        break;
		case 8: quit(aaa);break; 
		case 9: operation(aaa);break;
		default:break;
	}	
}

void acceptOrderOfStudent(int order,user Stu,fstream& aaa)
{
	string checker;
	int _order;
	switch(order)
	{
		case 1: listLessons(Stu._lessons,Stu.numOfLessons);
		        printForStudent();
				cin >> _order;
				acceptOrderOfStudent(_order,Stu,aaa);
				break;
		case 2: selectLesson(Stu);
		        printForStudent();
				cin >> _order;
				acceptOrderOfStudent(_order,Stu,aaa);
				break;
		case 3: dropLesson(Stu);
		        printForStudent();
				cin >> _order;
				acceptOrderOfStudent(_order,Stu,aaa);
				break;
		case 4: cout << "Please enter the name of the lesson you want to check:" << endl;
		        cin >> checker;
		        checkTime(checker);
		        printForStudent();
				cin >> _order;
				acceptOrderOfStudent(order,Stu,aaa);
		        break;
		case 5: cout << "Please enter the name of the lesson you want to check:" << endl;
		        cin >> checker;
		        checkPlace(checker);
				printForStudent();
				cin >> _order;
				acceptOrderOfStudent(order,Stu,aaa);
		        break;
		case 6: cout << "Please enter the name of the lesson you want to check:" << endl;
		        cin >> checker;
		        checkNumOfStudents(checker);
		        printForStudent();
				cin >> _order;
				acceptOrderOfStudent(order,Stu,aaa);
		        break;
		case 7: listLessons(lessons,numOfLessons);
		        printForTeacher();
				cin >> _order;
				acceptOrderOfTeacher(_order,Stu,aaa);		        
		        break;        
		case 8: quit(aaa);break; 
		case 9: operation(aaa);break;
		default:break;
	}
}

void operation(fstream& aaa)
{
	starter();
	int order1;
	cin >> order1;
	forStarter(order1,aaa);
    string identity;
    cout << "Enter your identity: ";
	cin >> identity;
	string name;
	cout << "Enter your name: ";
	cin >> name;
	if(identity!="Teacher"&&identity!="Student")
	{
	    cout << "Wrong identity!" << endl;
	    operation(aaa);
	}
	else
	{
		int num=-1;//user编号
	    if(!existedIdentity(name,identity))//如果user不存在，创建 
	   {
		    users[numOfUsers].setUser(identity,name);
		    num=numOfUsers; 
	        numOfUsers++;
	   }
		else//如果已存在，num接收该编号 
	   {
		    num=existedIdentity(name,identity)-1;
	   }
	   if(users[num].getIdentity()=="Teacher")
	   {
		    printForTeacher();
		    int order;
		    cin >> order;
		    acceptOrderOfTeacher(order,users[num],aaa);
	   }
	   else
	   {
	   		printForStudent();
		    int order;
		    cin >> order;
		    acceptOrderOfStudent(order,users[num],aaa);
	   }   		
	}		
}
