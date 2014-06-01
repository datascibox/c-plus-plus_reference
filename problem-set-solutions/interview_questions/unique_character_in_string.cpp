// In a string, give the first character that is not repeated in a string.
// Sebastian Raschka 11/11/2013

#include <iostream>
#include <string>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
  string in_str;
  cout << "Enter a string: ";
  cin >> in_str;
  int i;

  for (i = 0; i < in_str.size(); i++) {
    if (in_str.find(in_str[i]) == in_str.rfind(in_str[i])) {
      cout << "First unique character: "<< in_str[i] << endl;
      break;
    } // end if (in_str.find()...)
  } // end for
  
} // end main
