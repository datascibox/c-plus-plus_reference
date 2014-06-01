// ACM International Collegiate Programming Contest 
// 2003 East Central Regional Practice Contest
// Problem Set A - Euchre Results
//
// 10/21/13 sr

#include <vector>
#include <iostream>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

bool test_quit(vector<int> &v) {
  int sum = 0;
  for (int i : v)
    sum += i;
  return (sum == 0);
} // end test_quit()

int get_wins(vector<int> &v) {
  int result = v[1] + v[3] - v[4];
  return result;
} // end get_wins()

int get_losses(vector<int> &v) {
  int result = v[0] + v[2] - v[5];
  return result;
} // end get_losses()

int main() {

  int next;
  while (1) {
    vector<int> ivec;
    for (int i = 0; i < 6; i++) {
      cin >> next;
      ivec.push_back(next);
    } // end for
    if (test_quit(ivec))
      break;
  cout << "Anna's won-loss record is " << get_wins(ivec) << '-' 
       << get_losses(ivec) << '.' << endl;
  } // end while 

return 0;
} // end main()
