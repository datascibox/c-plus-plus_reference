// Sebastian Raschka 10/06/2013
// ACM International Collegiate Programming Contest 2000
// Practice Problem Set D - Untidy Desktops
//
//

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;


/////////////////////////////////
// FUNCTION DEFINITIONS
////////////////////////////////

// Gets window coordinates for top-left and bottom-right corner from standard 
// input and returns it as a vector of 4 integers.
vector<int> get_windw_coords(){
  vector<int> windw(4);
  for (int i = 0; i < 4; i++) 
    cin >> windw[i];
  return windw;
} // end get_windw_coords()


// Adds n windows from istream to a vector where
// each window is a subvector consisting of 4 integers that
// represent the x,y coordinates of the top-left corner, width, and height.
vector<vector<int>> get_windows(const int &windw_cnt){
  vector<vector<int>> screen_windows(windw_cnt);
  for (int i = 0; i < windw_cnt; i++)
    screen_windows[i] = get_windw_coords();
  return screen_windows;
} // end get_windows()


// Returns true if 2 windows are exactly the same
char windows_equal(const vector<int> &win1, const vector<int> &win2){
  for (int i = 0; i < 4; i++){
    if (!(win1[i] == win2[i]))
      return 0;
  }
  return 1;
} // end windows_equal()


// checks if to windows overlap and returns 1 if windows overlap,
// else returns 0.
char check_overlap(const vector<int> &win1, const vector<int> &win2) {
  if (windows_equal(win1, win2))
    return 1;
  char zone_overlap = 0;
  int col_zone_x1 = win1[0];
  int col_zone_x2 = win1[0] + win1[2];
  int row_zone_y1 = win1[1];
  int row_zone_y2 = win1[1] + win1[3];
  int win2_left_x = win2[0];
  int win2_right_x =  win2[0] + win2[2];
  int win2_top_y = win2[1];
  int win2_bottom_y = win2[1] + win2[3];
  // check left-top corner of win2
  if ( ( win2_top_y >= row_zone_y1 && win2_top_y <= row_zone_y2 ) ) {
    cout << "overlap1" << endl;
    ++zone_overlap;
  }
  if ( ( win2_left_x > col_zone_x1 && win2_left_x < col_zone_x2 ) ) {
    cout << "overlap2" << endl;
    ++zone_overlap;
  }
  if (zone_overlap == 2)
    return 1;
  else
    zone_overlap = 0;
  // check bottom right corner of win2
  if ( ( win2_bottom_y > row_zone_y1 && win2_bottom_y < row_zone_y2 ) ) {
    cout << "overlap3" << endl;
    ++zone_overlap;
  }
  if ( ( win2_right_x > col_zone_x1 && win2_right_x < col_zone_x2 ) ) {
    cout << "overlap4" << endl;
    ++zone_overlap;
  }
  return (zone_overlap == 2);
} // end check_overlap()


/////////////////////////////////
// MAIN
////////////////////////////////

int main() {

  unsigned int window_cnt;
  unsigned int overlap_cnt = 0;

  // Getting user input:
  //  prompt user for n number of windows - quit if 0
  while (1) {
    cin >> window_cnt;
    if (window_cnt == 0) 
      break;
    vector<vector<int>> windows = get_windows(window_cnt);
    vector<bool> overlapping_track(window_cnt,0);

    // for each window loop through other windows and if they
    // overlap mark both as overlapping windows
    for (int i = 0; i < windows.size(); i++) {
      for (int j = 0; j < windows.size(); j++) {
        if (i != j && check_overlap(windows[i], windows[j])){
          overlapping_track[i] = 1;
          overlapping_track[j] = 1;
        } // end if
      } // end inner for (j)
    } // end outer for (i)
    for (auto o : overlapping_track)
      overlap_cnt += o;
    cout << overlap_cnt << endl;
    overlap_cnt = 0;
  } // end while (1)

  return 0;
} // end main()
