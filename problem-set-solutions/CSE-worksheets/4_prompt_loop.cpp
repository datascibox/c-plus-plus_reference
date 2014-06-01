/*Write a program that does the following:
• continuously prompt for two integers
    - if either of the two integers are 0 or less, end the program 
    - otherwise the first int is the lower bound
    - the second is int the upper bound
• for all the integers in the range lower bound to upper bound (inclusive):
    - if any integer in that range is both evenly divisible by 3 and is odd, print it.
• when the inner loop ends, print out how many integers in the range met the above criteria.
• when the outer loop ends, print an exit message.
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
  int lower = 0;
  int upper = 0;

  while (1) {
    cout << "lower bound: ";
    cin >> lower;
    if (lower <= 0)
      break;
    
    cout << "upper bound: ";
    cin >> upper;
    if (upper <= 0)
      break;
    else if (upper <= lower) {
      cout << "upper bound must be larger than lower bound" << endl;
      continue;
    }

    int count = 0;
    for (int i = lower; i <= upper; i++) {
      if (i % 2 != 0 && i % 3 == 0) {
        cout << i << endl;
        count++; 
      } // end if()
    } // end for()
    cout << count << " integer(s) met the criteria" << endl;

  } // end while()
  cout << "Program exits" << endl;

  return 0;
} // end main()
