#ifndef ARRAY_H_
#define ARRAY_H_
 
class array {
  typedef int* pointer;
  typedef unsigned int size_t;
  typedef int data_type;
 
  pointer _data;//�����׵�ַ 
  size_t _size;//�����С 
 
 public:
  // constructor
  array(size_t size);
  // destructor
  ~array();
  // Capacity
  // Return maximum size
  size_t max_size(void);//����size 
 
  // Element access
  // Access element
  // int& operator[](const int &i) {return data[i];}
  // Access element
  data_type& at(const data_type& i);//������� 
  // Access first element
  data_type& front();//���ص�һ��ֵ 
  // Access last element
  data_type& back();//�������һ��ֵ 
  // Get pointer to data
  pointer data();//�����׵�ַ 
 
  // Modifiers
  // Fill array with the same value
  void fill(const data_type& value);//���鸳��ֵͬ 
  // Resize the array (newSize > oldSize)
  void resize(int newSize);//�ؿ�һ�������� 
  // Sort the array in the section [from, to)
  void sort(int from, int to);//���� 
};
 
#endif 
