#ifndef LIST
#define LIST
 
#include <string>
#include <iostream>
 
typedef struct node {
  int data;//数据 
  struct node* next;//指向下一节 
  node(int data = 0, struct node* next = NULL) : data(data), next(next) {}
} node;
 
class list {
 private:
  node* head;//首地址 
  int _size;//长度 
 
 public:
  list();// 不分配空间 
  list(const list&);//复制，开空间 
  list& operator=(const list&);//重开空间，复制 
  ~list();//删除空间 
 
  // Capacity
  bool empty(void) const;// 
  int size(void) const;//返回长度 
 
 public:
  // output
  // list: [1,2,3,4,5]
  // output: 1->2->3->4->5->NULL
  std::string toString(void) const;//输出链表 
 
  void insert(int position, const int& data);// 
  void erase(int position);//清除 
  void clear(void) {
    if (this->head != NULL) {
      node* p = this->head;
      while (p != NULL) {
        node* temp = p;
        p = p->next;
        delete temp;
      }
      this->head = NULL;
    }
    this->_size = 0;
  }
  list& sort(void);//排序 
};
 
#endif
