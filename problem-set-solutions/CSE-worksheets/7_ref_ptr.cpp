#include<iostream>
#include<string>

using std::cout;
using std::endl; 
using std::cin;
using std::string;

int main (){
  long l = 123;
  long &r_l = l;
  long *p_l = &r_l;

  cout << "line1: " << p_l <<endl;                     // some memory address
  cout << "line2: " << *p_l <<endl;                    // 123
  r_l = 456;
  cout << "line3: " << l << endl;                      // 456
  cout << "line4: " << (p_l == &l ? "yes\n" : "no\n"); // yes
  return 0;
} // end main()
