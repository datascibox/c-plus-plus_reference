// 12/09/2013 sr
// CSE 232 - Lab 10 - Stack Class

#include <vector>
#include <iostream>
#include <sstream>
#include "stack.h"

using std::ostream;
using std::vector;
using std::ostringstream;

// ==============================
// FUNCTION MEMBERS
// ==============================


char Stack::top() {
  char ret = '\0';
  if (stack_.size() > 0)
    ret = stack_.back();
  return ret;
} // end top()


void Stack::push(char chr){
  stack_.push_back(chr);
} // end push()


void Stack::pop() {
  if (stack_.size() > 0)
    stack_.pop_back();
} // end pop()


bool Stack::empty() {
  return stack_.empty();
} // end empty()

// ==============================
// FRIEND FUNCTIONS
// ==============================

ostream& operator<<(ostream &out, Stack &s) {
  ostringstream oss;
  if (s.stack_.size() > 0) {
    for (auto iter=s.stack_.begin(); iter < s.stack_.end()-1; iter++)
      oss << *iter << ", ";
    oss << s.stack_.back();
    out << oss.str();
  }
  return out;
} // end operator<<()

