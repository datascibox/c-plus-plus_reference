// Sebastian Raschka 10/10/2013
// ACM International Collegiate Programming Contest 2000
// Practice Problem Set A - Ride My Bicycle
//
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::vector;
using std::ostringstream;
using std::string;
using std::setprecision;
using std::fixed;
using std::sort;

/////////////////////////////////
// FUNCTION DEFINITIONS
////////////////////////////////

//collects the number of gears per ring in a vector
vector<int> get_gears(int ring_num) {
  vector<int> rings(ring_num);
  for (int i = 0; i < ring_num; i++)
    cin >> rings[i];
  return rings;
} // end get_gears()


/////////////////////////////////
// MAIN
////////////////////////////////

int main() {
  ostringstream tmp_ratio;
  vector<string> gear_ratios;
  auto front_rings = get_gears(3); 
  auto back_rings = get_gears(7);
  for (int f = 0; f < front_rings.size(); f++) {
    for (int b = 0; b < back_rings.size(); b++) {
      tmp_ratio.str(string());
      tmp_ratio << fixed << setprecision(2) 
        << static_cast<float>(front_rings[f])/back_rings[b]  
        << " " << f+1 << " " << b+1 << flush;
      gear_ratios.push_back(tmp_ratio.str());
    } // end innter for (b)
  } // end for (f)
  sort(gear_ratios.begin(), gear_ratios.end());
  for (auto e : gear_ratios)
    cout << e << endl;
  return 0;
} // end main()

