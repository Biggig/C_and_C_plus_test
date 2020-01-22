#ifndef LIBRARY_H
#define LIBRARY_H 

#include<string>
using namespace std;

void printHeadline();
void printLine();
void getOrder();
void exitProgram();
void addBooks(const string &,int);
void deleteBooks(const string &);
void borrowBooks(const string &);
void returnBooks(const string &);
void findBooks(const string &);

#endif 
