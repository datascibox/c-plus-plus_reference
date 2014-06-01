/*Write your basic C++ program that:
• prompts for two integers (however you like to do that)
• adds the two integers
• prints out the original two integers and the resulting sum
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
  int i1;
  int i2;
  cout << "Enter the 1st integer: ";
  cin >> i1;
  cout << "Enter the 2nd integer: ";
  cin >> i2;
  cout << "i1 = " << i1 << "\ni2 = " << i2 << "\nsum = " << (i1+i2) <<endl;

  return 0;

} // end main()
