#ifndef OBJ_H
#define OBJ_H
#include <iostream>
#include <string>
using namespace std;
class obj {
  public:
    explicit obj(string st):str(st) {
    }
    void print() {
        cout << str << endl;
    }
  private:
    string str;
};
#endif
