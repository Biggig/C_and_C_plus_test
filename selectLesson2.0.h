#include<iostream>
#include<string>
#include<fstream> 
using namespace std;


class Lesson
{
	public:
		Lesson();//Ĭ�Ϲ��캯�� 
		void setLesson(string nameOfLesson,string nameOfTeacher,string time,string place,int=0);//ΪLesson��������ֵ 
		Lesson(string nameOfLesson,string nameOfTeacher,string time,string place,int=0);//���캯�� 
		string getTime()const;//�õ��Ͽ�ʱ�� 
		string getPlace()const;//�õ��Ͽεص� 
		int getNumOfStudents()const;//����ѧ���� 
		bool addNumOfStudents();//���ɹ���ӣ�����true 
		bool subNumOfStudents();//���ɹ����٣�����true 
		string getNameOfTeacher()const;//������ʦ���� 
		string getNameOfLesson()const;//���ؿγ��� 
		friend class LessonOperation;//LessonOperation�ɵ���Lesson��public���� 
	private:
	    string nameOfLesson;//�γ��� 
		string nameOfTeacher;//��ʦ�� 
		int numOfStudents;//ѧ������ 
		string time;//�Ͽ�ʱ�� 
		string place;//�Ͽεص� 
};

class LessonOperation//��Lesson�Ĳ��� 
{
	public:
		friend class User;
		LessonOperation();//Ĭ�Ϲ��캯�� 
		bool printForLessons(Lesson& _les);//��ӡ�ÿε������Ϣ,���ÿβ����ڣ�����false 
		bool listLessons(Lesson* _les,int num);//���ٳ����пγ� �����γ���Ϊ�㣬����false
		bool searchLessons(string name);//�����γ̣����Ѵ��ڣ�����true 
	private:
		static Lesson Lessons[100];//�ܿγ� 
		static int numOfLessons;//�γ��������		
};

class User//ʹ���� 
{
	public:
		User();//Ĭ�Ϲ��캯�� 
		User(string& identity,string& Name);//���캯�� 		
		void setUser(string& identity,string& Name);//��ֵ 
		string getIdentity()const;//������� 
		string getUserName()const;//����ʹ�������� 
		int getNumOfLessons()const;//�õ�ʹ����ѡ/������ 
		User* existedIdentity(string _name,string _identity);//���Ѵ��ڣ�����true 
	private:
		string identity;//��� 
		string UserName;//���� 
		Lesson _Lessons[100];//ѡ/���� 
		int numOfLessons;// ѡ/������ 
		static User Users[100];//��ʹ���� 
		static int numOfUsers;//ʹ��������		 
};

class Teacher:public User
{
	public:
		Teacher();
		Teacher(string name);
		void printForTeacher();
		bool deleteLesson(string name);//ɾ���Σ����ÿβ����ڣ�����false
		bool openLesson(string nameOfLesson,string nameOfTeacher,string time,string place,int=0);//��һ���¿Σ����ÿ��Ѵ��ڣ�����false 
		void acceptOrderOfTeacher(int order);
};

class Student:public User
{
	public:
		Student();
		Student(string name);
		void printForStudent();
		bool selectLesson(string name);//ѡ�� ��������Ա��γ̲����ڣ�����false
		bool dropLesson(string name);//ȡ��ѡ�Σ����ÿ�û�б�ѡ������false
		void acceptOrderOfStudent(int order);		
};

void starter();
void quit();
void forStarter(int ord);








 
