/*Do the following:
  1. Write a function that calculates the greatest common divisor of two integers
    a. takes two integer parameters (call them a and b)
    b. returns an integer, the gcd
    c. function calculates the gcd using Euclid's algorithm:
      it is assumed that a > b, fix it otherwise 
      repeat until remainder is 0
      rem = a % b
      a is set to b, b is set to the remainder
      return a
  2. Write a main program that continuously prompts for two integers
    a. if either value is less than or equal to 0, quit and print a message 
    b. otherwise print the two entered integers and their gcd.
*/

#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int gcd(int A, int B) {
  int rem, a, b;
  if (A < B) {
    a = B;
    b = A;
  }
  else {
    a = A;
    b = B;
  }
  do {
    rem = a % b;
    a = b;
    b = rem;
  } while (rem > 0);
  return a;
} // end gcd()


int main() {
  int a;
  int b;
  while(1) {
    cout << "Enter integer a: ";
    cin >> a;
    cout << "Enter integer b: ";
    cin >> b;
    if (a <= 0 || b <= 0)
      break;
    cout << "integer a: " << a << "\ninteger b: " << b << endl;
    cout << "GCD: " << gcd(a, b) << endl;
  }
  cout << "Goodbye" << endl;
  return 0;
} // end main()

