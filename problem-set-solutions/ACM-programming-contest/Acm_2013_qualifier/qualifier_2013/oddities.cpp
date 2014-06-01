// Problem ID: Oddities
// Sebastian Raschka 11/11/2013
/*
Some numbers are just, well, odd. For example, the number 3 is odd, because it is not a multiple of two. Numbers
that are a multiple of two are not odd, they are even. More precisely, if a number n can be expressed as n = 2 ∗ k for
some integer k, then n is even. For example, 6 = 2 ∗ 3 is even.
Some people get confused about whether numbers are odd or even. To see a common example, do an internet
search for the query “is zero even or odd?” (Don’t search for this now! You have a problem to solve!)
Write a program to help these confused people.
*/


#include <iostream>
#include <sstream>

using std::endl;
using std::cout;
using std::cin;
using std::ostringstream;

int main () {
 
  int rows;
  int input_num;
  ostringstream oss;

  cin >> rows;

  for (int i = 0; i < rows; i++) {
    cin >> input_num;
    if (input_num % 2 == 0)
      oss << input_num << " is even" << endl;
    else
      oss << input_num << " is odd" << endl;
  } // end for()
  cout << oss.str();
  return 0;

} // end main()
