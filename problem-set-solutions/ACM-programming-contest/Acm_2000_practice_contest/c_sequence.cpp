// Sebastian Raschka 10/12/2013
// ACM International Collegiate Programming Contest 2000
// Practice Problem Set C - Sequence
//
//

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::pow;
using std::to_string;

/////////////////////////////////
// FUNCTION DECLARATIONS
////////////////////////////////

// Reads the arithmetic sequence into a vector
vector<int> get_input_sequence(int length) {
  vector<int> arithm_seq;
  int tmp_num;
  for (int i = 0; i < length; i++) {
    cin >> tmp_num;
    arithm_seq.push_back(tmp_num);
  }// end for
  return arithm_seq;
} // get_input_sequence()

// Converts integers from base < 10 to base 10.
// Function that converts integers from base x < 10 to base 10
int convert_to_base10(int in_num, int base) {
  int number = in_num;
  int sum = 0;
  vector<int> reversed;
  while(number > 9) {
    reversed.push_back(number % 10);
    number /= 10;
  } // end while
  reversed.push_back(number);
  for (decltype(reversed.size()) i = 0; i < reversed.size(); i++)
    sum += reversed[i] * pow(base,i);
  return sum;
} // end convert_base10()

// Convert integers in a vector to base 10 
vector<int> convert_vector_base10(const int &base, vector<int> &ivec) {
  int base10_digit;
  vector<int> converted_seq;
  for (decltype(ivec.size()) i = 0; i < ivec.size(); i++)
    converted_seq.push_back(convert_to_base10(ivec[i], base));
  return converted_seq;
} // end convert_vector_base10()

// Check if vector is an arithmetic sequence
bool is_arithmetic(vector<int> &ivec) {
  bool result = 1;
  int diff = ivec[0] - ivec[1];
  for (decltype(ivec.size()) i = 1; i < ivec.size() - 1; i++ ){
  //  cout << "   " << diff << "   " << ivec[i] - ivec[i+1] << endl;
    if ((ivec[i] - ivec[i+1]) != diff) {
      result = 0;
      break;
    } // end if
  }
  return result;
} // end is_arithmetic()


/////////////////////////////////
// MAIN
////////////////////////////////

int main() {
  string result;
  int seq_length;
  vector<int> input_seq;
  vector<int> base10_seq;

  while (cin >> seq_length) {
    if (seq_length == 0)
      break;
    input_seq = get_input_sequence(seq_length);
    result = "No base <= 10 can be found.";
    for (int i = 1; i <= 10; i++) {
      base10_seq = convert_vector_base10(i, input_seq);
      if (is_arithmetic(base10_seq)) {
        result = "Minimum base = " + to_string(i);
        break;
      } // end if
    } // end for
    cout << result << endl;
  } // end while

} // end main()
