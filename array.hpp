#ifndef ARRAY_H_
#define ARRAY_H_
 
class array {
  typedef int* pointer;
  typedef unsigned int size_t;
  typedef int data_type;
 
  pointer _data;//数组首地址 
  size_t _size;//数组大小 
 
 public:
  // constructor
  array(size_t size);
  // destructor
  ~array();
  // Capacity
  // Return maximum size
  size_t max_size(void);//返回size 
 
  // Element access
  // Access element
  // int& operator[](const int &i) {return data[i];}
  // Access element
  data_type& at(const data_type& i);//输出数组 
  // Access first element
  data_type& front();//返回第一个值 
  // Access last element
  data_type& back();//返回最后一个值 
  // Get pointer to data
  pointer data();//返回首地址 
 
  // Modifiers
  // Fill array with the same value
  void fill(const data_type& value);//数组赋相同值 
  // Resize the array (newSize > oldSize)
  void resize(int newSize);//重开一个大数组 
  // Sort the array in the section [from, to)
  void sort(int from, int to);//排序 
};
 
#endif 
