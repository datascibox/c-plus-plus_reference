// 12/09/2013 sr
// CSE 232 - Lab 10 - Stack Class

#include <vector>
#include <iostream>

using std::vector;
using std::ostream;

#ifndef STACK_H
#define STACK_H
class Stack {
  public:
    Stack() = default;
    char top();
    void push(char);
    void pop();
    bool empty();
    friend ostream& operator<<(ostream &out, Stack &);
  private:
    vector<char> stack_;
    

};

#endif

