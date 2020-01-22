#include<iostream>
#include<iomanip>
#include<string>
using namespace std;


struct Book
{
	string name;//���� 
	int number;//���� 
	int borrowed;//����� 
	int left;//ʣ���� 
};//������Ҫ�Ľṹ�� 

Book *books = new Book[10000];//����ṹ������ 
int num=0;//�����ñ��� 

void printLine()//��ӡһ����״�� 
{
	cout << "**************************************************" << endl;
}

void exitProgram()//�˳�ϵͳ 
{
	cout << "Thank you for using!\nGoodbye!" << endl;
	printLine();
	delete []books;//�ͷ���ǰ������ڴ� 
	exit(0);
}

void printHeadline()//��ӡ��ʼ���� 
{
	printLine();
	cout << setfill('*') << setw(50) << "Welcome to this liarbry management system!****"
	     << endl;
	cout << setfill('*') << setw(50) << "Please choose the function you want.*******"
	     << endl;
	cout <<	setfill('*') << setw(51) << "1.Add books.          2.Delete books********\n"
	     << setfill('*') << setw(51) << "3.Borrow books.       4.Return books********\n"
		 << setfill('*') << setw(50) << "5.Find books.         6.Exit system*********"
									 << endl;      
	printLine();
}

void addBooks(const string book_name,int book_num)//������� ,������book_name��������book_num 
{
	int in1;
	int counter=0;//����ñ��� 
	Book *result=0;
	for(in1=0;in1<=num;in1++)//���Ҹ��飬ȷ�����Ƿ��Ѵ��� 
	{
		if(book_name==books[in1].name) //�Ѵ��� 
		{
			result=&books[in1];
			break;
		}
		if(in1==num)//δ���ڣ�Ϊ���� 
		{
		    printLine();		
			cout << "It is a new book." << endl;
	        printLine();			
			counter++;
			break;
		}
	}
	if(counter==1)//Ϊ���飬������� 
	{
		num++;
		books[num].name=book_name;//���� 
		books[num].number=book_num;//���� 
		books[num].left=book_num;//ʣ���� 
		books[num].borrowed=0;//����� 
		cout << "You have added books successfully!" << endl;
		printLine();
		cout << "The name of book: << " << books[num].name << " >>" <<endl;//��ӡ������� 
		cout << "Total number: " << books[num].number << "\n" 
		     << "Left: " << books[num].left << "\n"
		     << "Borrowed: " << books[num].borrowed << endl;
	}
	else//�Ѵ��ڣ�������ӵ�����������뵽ԭ���� 
	{
		result->number+=book_num;//���� 
		result->left+=book_num;//ʣ���� 
		printLine();
		cout << " You have added books successfully!" << endl;
		printLine();
		cout << "The name of book: << " << result->name << " >>" << endl;//��ӡ������� 
	    cout << "Total number: " << result->number << endl;
		cout << "Left: " << result->left << "\n"
		     << "Borrowed: " << result->borrowed << endl;
	}
}

void findBooks(const string needed_Books)//�����鼮 ,������needed_Books 
{
	int in1=0;
	for(in1=0;in1<=num;in1++)
	{
		if(needed_Books==books[in1].name)//�鼮���� 
		{
			printLine();
			cout << "Find the book successfully!" << endl;
			printLine();	
	        cout << "The name of book: << " << books[in1].name << " >>" << endl;//��ӡ������� 
	        cout << "Total number: " << books[in1].number << endl;
	        cout << "Left: " << books[in1].left << "\n"
		         << "Borrowed: " << books[in1].borrowed << endl;
	        break;
		}
		if(in1==num)//�鼮������ 
		{
			printLine();
			cout << "Sorry, this book does not exist." << endl;
			break;
		}
	}	  
}

void deleteBooks(const string book_name)//ɾ���鼮,������book_name 
{
	int in1;
	for(in1=0;in1<=num;in1++)//�����鼮 
	{
		if(books[in1].name==book_name)//�鼮���ڣ������ݳ�ʼ�� 
		{
			books[in1].name.clear();
			books[in1].left=0;
			books[in1].number=0;
			books[in1].borrowed=0;
			printLine();
			cout << "You have deleted this book successfully!" << endl;
			break;
	    }
	    if(in1==num)//�鼮������ 
	    {
	    	printLine();	
	    	cout << "Sorry, this book does not exist." << endl;
			break;
		}
	}
}

void borrowBooks(const string book_name)//���� ,������book_name 
{
	int in1;
	for(in1=0;in1<=num;in1++)//�����鼮 
	{
		if(books[in1].name==book_name)//�鼮���� 
		{
			if(books[in1].left==0)//����ʧ�� 
			{
				printLine();
				cout << "Sorry,you have failed to borrow this book.\n"
				     << "None of these books are left. " << endl;
				break;	  
			}
			else//����ɹ� 
			{
				printLine();
			    cout << "You have borrowed this book successfully!" << endl;
			    printLine();  
			    books[in1].borrowed++;
			    books[in1].left--;

			    cout << "The name of book: << " << books[in1].name << " >>" <<endl;//��ӡ������� 
		        cout << "Total number: " << books[in1].number << "\n" 
		             << "Left: " << books[in1].left << "\n"
		             << "Borrowed: " << books[in1].borrowed << endl;
			    break; 
		    }
		}
		if(in1==num)//�鼮������ 
	    {
	    	printLine();	
	    	cout << "Sorry, this book does not exist." << endl;
			break;
		}
	}
}

void returnBooks(const string book_name)//���� ��������book_name 
{ 
	int in1;
	for(in1=0;in1<=num;in1++)//�����鼮 
	{
		if(books[in1].name==book_name)//�鼮���� 
		{
			printLine();
			cout << "You have returned this book successfully!" << endl;
			printLine();	
			books[in1].borrowed--;
			books[in1].left++;
			cout << "The name of book: << " << books[in1].name << " >>" <<endl;//��ӡ������� 
		    cout << "Total number: " << books[in1].number << "\n" 
		         << "Left: " << books[in1].left << "\n"
		         << "Borrowed: " << books[in1].borrowed << endl;			
			break; 
		}
		if(in1==num)//�鼮������ 
	    {
	    	printLine();	
	    	cout << "Sorry, this book does not exist." << endl;
			break;
		}
	}
}

void getOrder()//�������� 
{
	int order;
	cout << "Please enter the proper number to use the function." << endl;
	cin >> order;//�������� 
	string book_name; 
	int number;
	switch(order)//ѡ����õĺ��� 
	{
		case 1: cout << "Please enter the name and the number of the book: " << endl;
		        cin >> book_name >> number; 
		        addBooks(book_name,number);
		        break;
		case 2: cout << "Please enter the name of the book that you want to find: " << endl;
		        cin >> book_name;
		        deleteBooks(book_name);
				break;
		case 3: cout << "Please enter the name of the book that you want to borrow: " << endl;
		        cin >> book_name;
		        borrowBooks(book_name);
		        break;
		case 4: cout << "Please enter the name of the book that you want to return: " << endl;
		        cin >> book_name;
				returnBooks(book_name);
				break;
		case 5: cout << "Please enter the name of the book that you want to find: " << endl;
		        cin >> book_name;
		        findBooks(book_name);
				break;
		case 6:exitProgram();break;
		default: cout << "Wrong order!\nPlease enter the correct number." << endl;break; 
	}
	printLine();
	getOrder();//�������� 
}




