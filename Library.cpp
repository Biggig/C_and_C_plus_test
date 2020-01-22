#include<iostream>
#include<iomanip>
#include<string>
using namespace std;


struct Book
{
	string name;//书名 
	int number;//总数 
	int borrowed;//借出数 
	int left;//剩余数 
};//构造需要的结构体 

Book *books = new Book[10000];//构造结构体数组 
int num=0;//计数用变量 

void printLine()//打印一排星状符 
{
	cout << "**************************************************" << endl;
}

void exitProgram()//退出系统 
{
	cout << "Thank you for using!\nGoodbye!" << endl;
	printLine();
	delete []books;//释放先前分配的内存 
	exit(0);
}

void printHeadline()//打印初始界面 
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

void addBooks(const string book_name,int book_num)//添加新书 ,书名：book_name，数量：book_num 
{
	int in1;
	int counter=0;//标记用变量 
	Book *result=0;
	for(in1=0;in1<=num;in1++)//查找该书，确认其是否已存在 
	{
		if(book_name==books[in1].name) //已存在 
		{
			result=&books[in1];
			break;
		}
		if(in1==num)//未存在，为新书 
		{
		    printLine();		
			cout << "It is a new book." << endl;
	        printLine();			
			counter++;
			break;
		}
	}
	if(counter==1)//为新书，添加新书 
	{
		num++;
		books[num].name=book_name;//书名 
		books[num].number=book_num;//总数 
		books[num].left=book_num;//剩余数 
		books[num].borrowed=0;//借出数 
		cout << "You have added books successfully!" << endl;
		printLine();
		cout << "The name of book: << " << books[num].name << " >>" <<endl;//打印相关数据 
		cout << "Total number: " << books[num].number << "\n" 
		     << "Left: " << books[num].left << "\n"
		     << "Borrowed: " << books[num].borrowed << endl;
	}
	else//已存在，将新添加的书的数量加入到原书中 
	{
		result->number+=book_num;//总数 
		result->left+=book_num;//剩余数 
		printLine();
		cout << " You have added books successfully!" << endl;
		printLine();
		cout << "The name of book: << " << result->name << " >>" << endl;//打印相关数据 
	    cout << "Total number: " << result->number << endl;
		cout << "Left: " << result->left << "\n"
		     << "Borrowed: " << result->borrowed << endl;
	}
}

void findBooks(const string needed_Books)//查找书籍 ,书名：needed_Books 
{
	int in1=0;
	for(in1=0;in1<=num;in1++)
	{
		if(needed_Books==books[in1].name)//书籍存在 
		{
			printLine();
			cout << "Find the book successfully!" << endl;
			printLine();	
	        cout << "The name of book: << " << books[in1].name << " >>" << endl;//打印相关数据 
	        cout << "Total number: " << books[in1].number << endl;
	        cout << "Left: " << books[in1].left << "\n"
		         << "Borrowed: " << books[in1].borrowed << endl;
	        break;
		}
		if(in1==num)//书籍不存在 
		{
			printLine();
			cout << "Sorry, this book does not exist." << endl;
			break;
		}
	}	  
}

void deleteBooks(const string book_name)//删除书籍,书名：book_name 
{
	int in1;
	for(in1=0;in1<=num;in1++)//查找书籍 
	{
		if(books[in1].name==book_name)//书籍存在，将数据初始化 
		{
			books[in1].name.clear();
			books[in1].left=0;
			books[in1].number=0;
			books[in1].borrowed=0;
			printLine();
			cout << "You have deleted this book successfully!" << endl;
			break;
	    }
	    if(in1==num)//书籍不存在 
	    {
	    	printLine();	
	    	cout << "Sorry, this book does not exist." << endl;
			break;
		}
	}
}

void borrowBooks(const string book_name)//借书 ,书名：book_name 
{
	int in1;
	for(in1=0;in1<=num;in1++)//查找书籍 
	{
		if(books[in1].name==book_name)//书籍存在 
		{
			if(books[in1].left==0)//借书失败 
			{
				printLine();
				cout << "Sorry,you have failed to borrow this book.\n"
				     << "None of these books are left. " << endl;
				break;	  
			}
			else//借书成功 
			{
				printLine();
			    cout << "You have borrowed this book successfully!" << endl;
			    printLine();  
			    books[in1].borrowed++;
			    books[in1].left--;

			    cout << "The name of book: << " << books[in1].name << " >>" <<endl;//打印相关数据 
		        cout << "Total number: " << books[in1].number << "\n" 
		             << "Left: " << books[in1].left << "\n"
		             << "Borrowed: " << books[in1].borrowed << endl;
			    break; 
		    }
		}
		if(in1==num)//书籍不存在 
	    {
	    	printLine();	
	    	cout << "Sorry, this book does not exist." << endl;
			break;
		}
	}
}

void returnBooks(const string book_name)//还书 ，书名：book_name 
{ 
	int in1;
	for(in1=0;in1<=num;in1++)//查找书籍 
	{
		if(books[in1].name==book_name)//书籍存在 
		{
			printLine();
			cout << "You have returned this book successfully!" << endl;
			printLine();	
			books[in1].borrowed--;
			books[in1].left++;
			cout << "The name of book: << " << books[in1].name << " >>" <<endl;//打印相关数据 
		    cout << "Total number: " << books[in1].number << "\n" 
		         << "Left: " << books[in1].left << "\n"
		         << "Borrowed: " << books[in1].borrowed << endl;			
			break; 
		}
		if(in1==num)//书籍不存在 
	    {
	    	printLine();	
	    	cout << "Sorry, this book does not exist." << endl;
			break;
		}
	}
}

void getOrder()//接收命令 
{
	int order;
	cout << "Please enter the proper number to use the function." << endl;
	cin >> order;//输入命令 
	string book_name; 
	int number;
	switch(order)//选择调用的函数 
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
	getOrder();//调用自身 
}




