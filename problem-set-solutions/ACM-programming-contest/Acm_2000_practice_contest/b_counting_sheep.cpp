// Sebastian Raschka 10/10/2013
// ACM International Collegiate Programming Contest 2000
// Practice Problem Set D - Untidy Desktops
//
//

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// Checks if lowercase version of the argument
// matches exactly the word "sheep".
bool check_word(string &word) {
  string sheep = "sheep";
  bool sheep_true = 1;
  if ((word != sheep) || word.length() < 5)
    sheep_true = 0;
  else if (word.substr(0,5) != sheep)
    sheep_true = 0;
  return sheep_true;
} // end check_word

int main() {
  string curr_line;
  string curr_word;
  int num_lines;
  int num_words;
  int sum_sheeps;

  cin >> num_lines;
  vector<int> ivec;
  for (int l = 0; l < num_lines; l++) {
    cin >> num_words;

    sum_sheeps = 0;
    for (int w = 0;  w < num_words; w++) {
      cin >> curr_word;
      //cout << curr_word << check_word(curr_word) << endl;
      sum_sheeps += check_word(curr_word);
    } // end for l
    ivec.push_back(sum_sheeps);
  }  // end for w
  for (decltype(ivec.size()) i = 0; i < ivec.size(); i++) {
    cout << "\nCase " << i+1 << ": This list contains " << ivec[i] << " sheep."
      << endl;
  }

  return 0;
} // end main
