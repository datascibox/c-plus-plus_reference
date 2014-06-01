#include<iostream>
#include<string>

using std::cout;
using std::endl; 
using std::cin;
using std::string;

int main (){

long i = 100;
  long cnt1=0, cnt2=0, cnt3=0;
  for(long i=0;i<10;i++){
    if ((i % 2) && (i != 6))
      cnt1++;
    else if (!(i % 4))
      cnt2++;
    else
      cnt3++;
  }
  cout << "line1: " << cnt1 << endl;         // 5
  cout << "line2: " << cnt2 << endl;         // 3
  cout << "line3: " << cnt3 << endl;         // 2
  cout << "line4: " << i << endl;            // 100 

  return 0;
} // end main()
  
