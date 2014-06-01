#include<iostream>
using std::cout;
using std::endl;

long fun1(long &param1, long param2){
  if (param1 < param2){
    param1 = param1 * 2;
    return param2;
  }
  else
    return param1;
}

int main () {
  long val1=10, val2=100;
  long &r_val = val1;
  const long &c_val = val1;

  cout << fun1(val1,val2) << endl; // Line 1: 100
  cout << val1 << endl;            // Line 2: 20
  cout << val2 << endl;            // Line 3: 100
  cout << r_val << endl;           // Line 4: 20
  cout << c_val << endl;           // Line 5: 20
  //c_val = 200;                   // wouldn't compile, can't change const

  return 0;
} // end main()
