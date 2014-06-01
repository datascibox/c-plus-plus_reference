/*
Do the following:
  1. Write a function that factors:
    a. take 2 args: an integer num, a string factor_str
    b. Calculate the integer factors (excluding the number itself) of num
    c. Set the string factor_str to a print representation of the factors 
      (integers as a comma separated list)
    d. return the integer sum of the factors
  2. Write a main function that:
    a. continuously prompts for a integer
      i. quit when the prompt give is 0 or less 
    b. calls factors and prints:
      i. the number
      ii. the factors
      iii. the sum of the factors
*/

#include <string>
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ostringstream;

int factors(int num, string factor_str) {
  int sum = 0;
  ostringstream oss;
  for (int i = num-1; i >= 2; i--) {
    if (i % 2 == 0) {
      sum += i;
      oss << i << ", ";
    }
  }
  factor_str = oss.str();
  cout << "integer: " << num << endl;
  cout << factor_str << endl;
  cout << "sum: " << sum << endl;
  return sum;
} // end factors()



int main() {
  int a;
  string factor_str;
  while(1) {
    cout << "Enter an integer: ";
    cin >> a;
    if (a <= 0)
      break;
    factors(a, factor_str);
  }
  return 0;
} // end main()
