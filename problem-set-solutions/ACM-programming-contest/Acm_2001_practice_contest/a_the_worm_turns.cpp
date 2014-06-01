// Sebastian Raschka 10/14/13
// Practice Problem A - The Worm Turns
//
// 2001 East Central Regional Practice Contest

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::pair;
using std::make_pair;
using std::cout;
using std::endl;
using std::cin;
using std::string;



///////////////
// FUNCTIONS
//////////////

// Initializes worm with 20 column segments starting
// at position 11,25
void init_worm(vector<pair<int,int>> &worm) {
  int col = 11;
  int row = 25;
  for (int i = 0; i < 20; i++) {
    worm[i].first = row;
    worm[i].second = col+i;
  } // end for()
} // end init_worm()


// Move worm forward one field by first moving its head by one field,
// and then each segment gets the position the segment that comes after it.
void move(vector<pair<int,int>> &worm, char direction) {
  // move body
  for (int i = 0; i < 19; i++) {
    worm[i].first = worm[i+1].first;
    worm[i].second = worm[i+1].second;
  } // end for()
  // move head
  if (direction == 'N')
    worm[19].first += 1;
  else if (direction == 'S')
    worm[19].first -= 1;
  else if (direction == 'W')
    worm[19].second -= 1;
  else
    worm[19].second += 1;
} // end move()


// Check if worm ran into itself.
bool check_collide_body(vector<pair<int,int>> &worm) {
  bool result = 0;
  for (int i = 0; i < 19; i++) {
    if ((worm[i].first == worm[19].first) 
             && (worm[i].second == worm[19].second)) {
      result = 1;
      break;
    } // end if
  } // end for
  return result;
} // end check_collide_body()


// Check if worm rans out of the 50x50 field limitation
bool check_run_off(vector<pair<int,int>> &worm) {
  bool result = 0;
  if ((worm[19].first > 50) || (worm[19].second > 50) 
         || (worm[19].first < 1) || (worm[19].second < 1))
    result = 1;
  return result;
} // end check_collide_field()


///////////////
// MAIN
//////////////


int main() {
  vector<pair<int,int>> worm(20,make_pair(0,0));
  int move_num;
  bool valid_move;
  string directions;

  while (cin >> move_num) {
    if (move_num == 0)
      break;
    init_worm(worm);
    cin >> directions;
    valid_move = 1;
    for (int i = 0; i < directions.size(); i++){
      move(worm, directions[i]);
      if (check_collide_body(worm)) {
        cout << "The worm ran into itself on move " << i+1 << "." << endl;
        valid_move = 0;
        break;
      }
      else if (check_run_off(worm)) {
        cout << "The worm ran off the board on move " << i+1 << "." << endl;
        valid_move = 0;
        break;
      } // end if
    } // end for()
    if (valid_move)
      cout << "The worm successfully made all " << move_num << " moves." << endl;

  } // end while()
  return 0;
}






