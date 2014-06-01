// Selection Sort Algorithm
// sr 11/28/2013
//
// Algorithm
//    Work through a list
//  1.  Find the smallest element in the list and put it at the beginning: its proper spot.
//  2.  The list is now trivially sorted at the beginning -- only the first element.
//  3.  Find the smallest element in the rest of the list, the unsorted part, 
//      and put it at the beginning of the unsorted part: its proper spot.
//  4.  Now the first two elements are sorted.
//  5.  Repeat step 3 until done with list.

#include<limits>  // size_t
#include<iostream>

using std::endl;
using std::cout;

template<typename Type>
void sel_sort(Type ary[], size_t sz) {
  size_t pos = 0;
  for (size_t i = 0; i < sz; i++) {
      Type min = ary[i];
      size_t pos = i;
    for(size_t j = pos+1; j < sz; j++) {
      if (ary[j] < min) {
        min = ary[j];
        pos = j;
      } // end if
    } // end inner for
    ary[pos] = ary[i];
    ary[i] = min; 
  } // end outer for

} // end sel_sort()


int main() {
  // sorting integers
  int new_ary[5] = {2,4,5,1,3};
  sel_sort(new_ary, 5);
  for (int i : new_ary)
    cout << i << ",";
  cout << endl;

  // sorting characters
  char new_ary2[5] = {'d','a','c','b','e'};
  sel_sort(new_ary2, 5);
  for (char i : new_ary2)
    cout << i << ",";
  cout << endl;

  return 0;
}
