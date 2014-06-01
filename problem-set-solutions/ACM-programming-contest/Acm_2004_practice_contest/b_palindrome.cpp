// 2004 East Central Regional Contest
// Problem B - Palindrome
// C++11 
//
// 10/28/2013
// Sebastian Raschka

#include <iostream>
#include <string>
#include <cctype>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::isalpha;
using std::tolower;

string strip_string(string in_string) {
  string stripped = "";
  for (auto c : in_string) 
    if ( isalpha(c) ) 
      stripped += tolower(c);
  return stripped;
} // end strip_string()

string check_palindrom(string &in_string) {
  string is_palin = "Yes";
  int str_size = in_string.size();
  for (int i = 0; i < (str_size/2); i++) {
    if (in_string[i] != in_string[str_size-1-i]) {
      is_palin = "No";
      break;
    } // end if
  } // end for
  return is_palin;
} // end check_palindrom()

int main() {
  string line;
  string stripped;
  while (getline(cin, line)) {
    if (line.compare("THE END.") == 0)
      break;
    stripped = strip_string(line);
    cout << check_palindrom(stripped) << endl;
  } // end while()
  
    return 0;
}
