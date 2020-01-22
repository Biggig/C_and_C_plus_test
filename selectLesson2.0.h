#include<iostream>
#include<string>
#include<fstream> 
using namespace std;


class Lesson
{
	public:
		Lesson();//默认构造函数 
		void setLesson(string nameOfLesson,string nameOfTeacher,string time,string place,int=0);//为Lesson各变量赋值 
		Lesson(string nameOfLesson,string nameOfTeacher,string time,string place,int=0);//构造函数 
		string getTime()const;//得到上课时间 
		string getPlace()const;//得到上课地点 
		int getNumOfStudents()const;//返回学生数 
		bool addNumOfStudents();//若成功添加，返回true 
		bool subNumOfStudents();//若成功减少，返回true 
		string getNameOfTeacher()const;//返回老师名字 
		string getNameOfLesson()const;//返回课程名 
		friend class LessonOperation;//LessonOperation可调用Lesson的public函数 
	private:
	    string nameOfLesson;//课程名 
		string nameOfTeacher;//老师名 
		int numOfStudents;//学生数量 
		string time;//上课时间 
		string place;//上课地点 
};

class LessonOperation//对Lesson的操作 
{
	public:
		friend class User;
		LessonOperation();//默认构造函数 
		bool printForLessons(Lesson& _les);//打印该课的相关信息,若该课不存在，返回false 
		bool listLessons(Lesson* _les,int num);//例举出所有课程 ，若课程数为零，返回false
		bool searchLessons(string name);//搜索课程，若已存在，返回true 
	private:
		static Lesson Lessons[100];//总课程 
		static int numOfLessons;//课程最大数量		
};

class User//使用者 
{
	public:
		User();//默认构造函数 
		User(string& identity,string& Name);//构造函数 		
		void setUser(string& identity,string& Name);//赋值 
		string getIdentity()const;//返回身份 
		string getUserName()const;//返回使用者姓名 
		int getNumOfLessons()const;//得到使用者选/开课数 
		User* existedIdentity(string _name,string _identity);//若已存在，返回true 
	private:
		string identity;//身份 
		string UserName;//名字 
		Lesson _Lessons[100];//选/开课 
		int numOfLessons;// 选/开课数 
		static User Users[100];//总使用者 
		static int numOfUsers;//使用者数量		 
};

class Teacher:public User
{
	public:
		Teacher();
		Teacher(string name);
		void printForTeacher();
		bool deleteLesson(string name);//删除课，若该课不存在，返回false
		bool openLesson(string nameOfLesson,string nameOfTeacher,string time,string place,int=0);//开一门新课，若该课已存在，返回false 
		void acceptOrderOfTeacher(int order);
};

class Student:public User
{
	public:
		Student();
		Student(string name);
		void printForStudent();
		bool selectLesson(string name);//选课 ，若已满员或课程不存在，返回false
		bool dropLesson(string name);//取消选课，若该课没有被选，返回false
		void acceptOrderOfStudent(int order);		
};

void starter();
void quit();
void forStarter(int ord);








 
