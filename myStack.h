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
 myStack();//��ջ 
 myStack(const myStack &stack);//���� 
 myStack(const int *arr, const int _size); // �����鹹��,��˳��ѹջ���������ķ��ڶ��� 
 ~myStack();//ɾ���ռ� 
 bool empty() const;  // ջ���򷵻�true
 int top() const; // ����ջ��Ԫ�أ����ջΪ���򷵻�0
 bool pop();//�׳�  
 bool push(int _number); // ��ע��pushʧ�ܵ��������newʧ��
 int size() const;//����size 

 myStack& operator=(const myStack& stack);//��գ����� 
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
