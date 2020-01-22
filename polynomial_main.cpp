#include"polynomial.h"
#include<stdlib.h>
#include<iomanip>
using namespace std;



int main()
{
	int counter=0;
	printOutSet();
	displayOrderList();
	while(counter==0)
	{
		int order;
		cout << endl;
		cout << "Please enter the order you want:" << endl;
		cin >> order;
		if(order<0||order>9)
		{
			cout << endl;
			cout << "Wrong order!!!" << endl;
			cout << "Please read the list of order again." << endl;
			displayOrderList();
	    }
	    else
	    {
			switch(order)
			{
				case 0 ://退出系统 
				{
					counter=1;
					cout << endl;
					cout << "Exit the system sucessfully!" << endl;
					exitTheSystem();
					break;
				}
				case 1 ://输入多项式 
				{
					cout << endl;
					cout << "Please enter your polynomial:" << endl;
					string plo;
					cin >> plo;
					if(!plo.compare("Back"))
					{
						cout << endl;
						cout << "Return to the main menu!" << endl;
						break;
					}
					if(validPolynomial(plo))
					{
						Polynomial test(plo);
						cout << endl;
						cout << "The polynimal you enter is: " << endl;
						cout << test.displayPolynomial() << endl;
						test.findPolynomial(test); 
					}
					else
					{
						cout << endl;
						cout << "Wrong format!" << endl;
						cout << "Fail to enter your polynomial." << endl;
					}
					break;
				}
				case 2://多项式加法 
				{
					cout << endl;
					cout << "Please enter the two polynomials you want to calculate:" << endl;
					cout << "The first polynomial is: " << endl;
					string test1;
					cin >> test1;
					if(test1=="Back")
					{
						cout << endl;
						cout << "Return to the main menu!" << endl;
						break;
					}
					if(validPolynomial(test1))
					{
						Polynomial ele1(test1);
						cout << endl;
						cout << "The polynimal you enter is: " << endl;
						cout << ele1.displayPolynomial() << endl;
					    ele1.findPolynomial(ele1);
					    cout << endl;
					    cout << "The second polynomial is: " << endl;
						string test2;
						cin >> test2;
						if(test2=="Back")
						{
							cout << endl;
							cout << "Return to the main menu!" << endl;
							break;
						}
						if(validPolynomial(test2))
						{
							Polynomial ele2(test2);
							cout << endl;
							cout << "The polynimal you enter is: " << endl;
						    cout << ele2.displayPolynomial() << endl;
							ele2.findPolynomial(ele2);
							Polynomial result=ele1.polynomialAddition(ele2);
							cout << endl;
							cout << "The result of the calculation is: " << endl;
							cout << result.displayPolynomial() << endl;
							result.findPolynomial(result);
							break;
						}
						else
						{
							cout << endl;
							cout << "Wrong Polynomial! Fail to continue!" << endl;
							break;
						}
					}
					else
					{
						cout << endl;
						cout << "Wrong Polynomial! Fail to continue!" << endl;
						break;
					}
				}
				case 3://多项式减法 
				{
					cout << endl;
					cout << "Please enter the two polynomials you want to calculate:" << endl;
					cout << "The first polynomial is: " << endl;
					string test1;
					cin >> test1;
					if(test1=="Back")
					{
						cout << endl;
						cout << "Return to the main menu!" << endl;
						break;
					}
					if(validPolynomial(test1))
					{
						Polynomial ele1(test1);
						cout << endl;
						cout << "The polynimal you enter is: " << endl;
						cout << ele1.displayPolynomial() << endl;
					    ele1.findPolynomial(ele1);
					    cout << endl;
					    cout << "The second polynomial is: " << endl;
						string test2;
						cin >> test2;
						if(test2=="Back")
						{
							cout << endl;
							cout << "Return to the main menu!" << endl;
							break;
						}
						if(validPolynomial(test2))
						{
							Polynomial ele2(test2);
							cout << endl;
							cout << "The polynimal you enter is: " << endl;
							cout << ele2.displayPolynomial() << endl;
							ele2.findPolynomial(ele2);
							Polynomial result=ele1.polynomialSubtraction(ele2);
							cout << endl;
							cout << "The result of the calculation is: " << endl;
							cout << result.displayPolynomial() << endl;
							result.findPolynomial(result);
							break;
						}
						else
						{
							cout << endl;
							cout << "Wrong Polynomial! Fail to continue!" << endl;
							break;
						}
					}
					else
					{
						cout << endl;
						cout << "Wrong Polynomial! Fail to continue!" << endl;
						break;
					}
				}
				case 4://多项式与常数的乘法 
				{
					cout << endl;
					cout << "Please enter your polynomial: " << endl;
					string test;
					cin >> test;
					if(test=="Back")
					{
						cout << endl;
						cout << "Return to the main menu!" << endl;
						break;
					}
					if(validPolynomial(test))
					{
						Polynomial ele1(test);
						cout << endl;
						cout << "The polynimal you enter is: " << endl;
						cout << ele1.displayPolynomial() << endl;
					    ele1.findPolynomial(ele1);
					    cout << endl;
					    cout << "Please enter the multiplier(integer): " << endl;
						string num1;
						cin >> num1;
						int num;
						if(num1=="Back")
						{
							cout << endl;
							cout << "Return to the main menu!" << endl;
							break;
						}
						else
						{
							num=atoi(num1.c_str());
						}
						cout << endl;
						cout << "The result of the calculation is: " << endl;
						Polynomial result=ele1.polynomialMultiplitication(num);
						cout << result.displayPolynomial() << endl;
						result.findPolynomial(result);
						break;
					}
					else
					{
						cout << endl;
						cout << "Wrong Polynomial! Fail to continue!" << endl;
						break;
					}
				}
				case 5://将常数代入多项式，求值 
				{
					cout << endl;
					cout << "Please enter your polynomial: " << endl;
					string test;
					cin >> test;
					if(test=="Back")
					{
						cout << endl;
						cout << "Return to the main menu!" << endl;
						break;
					}
					if(validPolynomial(test))
					{
						Polynomial ele1(test);
						cout << endl;
						cout << "The polynimal you enter is: " << endl;
						cout << ele1.displayPolynomial() << endl;
					    ele1.findPolynomial(ele1);
					    cout << endl;
					    cout << "Please enter the value of x: " << endl;
					    string num1;
						cin >> num1;
						double num;
					    if(num1=="Back")
					    {
					    	cout << endl;
					    	cout << "Return to the main menu." << endl;
					    	break;
						}
						else
						{
							num=atof(num1.c_str());
						}
						cout << endl;
						cout << "The result of the calculation is: " << endl;
						cout << setw(15) << fixed << left << ele1.polynomialValue(num) << endl;
						break;
					}
					else
					{
						cout << endl;
						cout << "Wrong Polynomial! Fail to continue!" << endl;
						break;
					}
				}
				case 6://显示所有储存的多项式 
				{
					cout << endl;
					disolayAllPolynimal();
					break;
				}
				case 7://比较多项式 
				{
					cout << endl;
					cout << "Please enter the first polynomial: " << endl;
					string test1;
					cin >> test1;
					if(test1=="Back")
					{
						cout << endl;
						cout << "Return to the main menu!" << endl;
						break;
					}
					if(validPolynomial(test1))
					{
						Polynomial ele1(test1);
						cout << endl;
						cout << "The polynimal you enter is: " << endl;
						cout << ele1.displayPolynomial() << endl;
					    ele1.findPolynomial(ele1);
					    cout << endl;
					    cout << "Please enter the second polynomial: " << endl;
						string test2;
						cin >> test2;
						if(test2=="Back")
						{
							cout << endl;
							cout << "Return to the main menu!" << endl;
							break;
						}
						if(validPolynomial(test2))
						{
							Polynomial ele2(test2);
							cout << endl;
							cout << "The polynimal you enter is: " << endl;
							cout << ele1.displayPolynomial() << endl;
							ele2.findPolynomial(ele2);
							if(ele1.comparePolynomial(ele2))
							{
								cout << endl;
								cout << "The two polynomials are the same." << endl;
								break;
							}
							else
							{
								cout << endl;
								cout << "The two polynomials are diffrent." << endl;
								break;
							}
						}
						else
						{
							cout << endl;
							cout << "Wrong Polynomial! Fail to continue!" << endl;
							break;
						}
					}
					else
					{
						cout << endl;
						cout << "Wrong Polynomial! Fail to continue!" << endl;
						break;
					}
				}
				case 8://多项式求导 
				{
					cout << endl;
					cout << "Please enter your polynomial: " << endl;
					string test;
					cin >> test;
					if(test=="Back")
					{
						cout << endl;
						cout << "Return to the main menu!" << endl;
						break;
					}
					if(validPolynomial(test))
					{
						Polynomial ele1(test);
						cout << endl;
						cout << "The polynimal you enter is: " << endl;
						cout << ele1.displayPolynomial() << endl;
					    ele1.findPolynomial(ele1);
					    cout << endl;
					    cout << "The derivative of this polynomial is: " << endl;
					    Polynomial ele2=ele2.derivativeOfPlo(ele1);
					    cout << ele2.displayPolynomial() << endl;
					    ele2.findPolynomial(ele2);
					    break;
					}
					{
						cout << endl;
						cout << "Wrong Polynomial! Fail to continue!" << endl;
						break;
					}
				}
				case 9://打印命令列表 
				{
					cout << endl;
					displayOrderList();
					break;
				}
				default:
				{
					cout << endl;
					cout << "Wrong order!!!" << endl;
					cout << "Please read the list of order again." << endl;
					displayOrderList();
					break;
				}
		    }
		}
	}
	return 0;
}


