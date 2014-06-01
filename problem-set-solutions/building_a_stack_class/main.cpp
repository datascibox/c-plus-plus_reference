// 12/09/2013 sr
// CSE 232 - Lab 10 - Stack Class

#include <iostream>
#include <string>
#include <fstream>
using std::cout; 
using std::endl; 
using std::cin;
using std::string;
using std::ifstream;

#include "stack.h"

int main (){
  Stack stk;
  string user_string="", reverse_string="";

  cout << "Give me a string to reverse:";
  getline(cin, user_string);

  for (auto ch : user_string)
    stk.push(ch);

  cout << "After processing, stack contains:"<<endl;
  cout << stk << endl;

  while (!stk.empty()){
    reverse_string = reverse_string + stk.top();
    stk.pop();
  }

  cout<<"Original String was:"<<user_string<<endl;
  cout<<"Reversed String was:"<<reverse_string<<endl;


  // test braces

  ifstream iss("./test.txt");
  string line;
  Stack braces;
  bool okay = 1;
  long open_braces = 0;
  long close_braces = 0;

  while (getline(iss, line)) {
    for (char e : line) {
      if (e == '{')
        braces.push(e);          
      else if (e == '}') {
        if (braces.empty())
          okay = 0;
        else 
          braces.pop();
      } // end if
    } // end for
  } // end while
  iss.close();

  if (!braces.empty())
    cout << "Not all opening braces were closed" << endl;
  else if (!okay)
    cout << "More closing than opening braces" << endl;
  else
    cout << "Everything okay" << endl;

  return 0;
} // end main()
