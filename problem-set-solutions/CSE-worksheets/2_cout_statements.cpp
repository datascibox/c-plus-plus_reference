/*
1. Give the output for the 5 cout statements. 
If the output is an address, just say it is "some address"

2. Describe in words Line6: 
(does it compile, is it a good idea, what does it do)?
*/

#include<iostream>
using std::cout; 
using std::endl;

int main() {
  int my_int = 123; 
  long my_long(456); 
  double my_double;
  double &r_double = my_double; 
  long *p_long = &my_long;
  r_double = 3.14159; 
  *p_long = 1000;
  cout << "Line1: " << my_int << endl;    // 123
  cout << "Line2: " << my_long << endl;   // 1000
  cout << "Line3: " << p_long << endl;    // some memory address
  cout << "Line4: " << my_double << endl; // 3.14159
  cout << "Line5: " << r_double << endl;  // 3.14159 (ref. to my_double)
  p_long = 0; // Line6: sets pointer to memory address 0

  return 0;
} // end main() 
