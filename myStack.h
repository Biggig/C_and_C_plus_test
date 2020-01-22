#ifndef MYSTACK__H__
#define MYSTACK__H__
#include <iostream>
#include <cstdio>

using namespace std;

struct Node {
 int number;
 Node *next;
};

class myStack {
private:
 Node *mtop;
 int _size;
public:
 myStack();//空栈 
 myStack(const myStack &stack);//复制 
 myStack(const int *arr, const int _size); // 用数组构造,按顺序压栈，最后输入的放在顶部 
 ~myStack();//删除空间 
 bool empty() const;  // 栈空则返回true
 int top() const; // 返回栈顶元素，如果栈为空则返回0
 bool pop();//抛出  
 bool push(int _number); // 请注意push失败的情况，即new失败
 int size() const;//返回size 

 myStack& operator=(const myStack& stack);//清空，复制 
 friend ostream& operator<<(ostream& out, const myStack& stack) {
  Node *t = stack.mtop;
 if (t == NULL) {
  out << "The stack is empty!";
  return out;
 }
 while (t != NULL) {
  out << t->number << ' ';
  t = t->next;
 }
 return out;
 };
};

#endif
