// Lab 11 - Circular Buffer
// 12/11/2013 sr

#include<iostream>
#include<string>

using std::cout; 
using std::cin; 
using std::endl;
using std::string;

#include "circbuf.h"

int main(){
  const size_t sz = 4;
  CircBuf cb(sz);

  cb.add(4);
  cout << cb << " |exp. 4" << endl;
  cb.add(3);
  cb.add(2);
  cb.add(1);   
  cout << cb << " |exp. 4,3,2,1" << endl;
  cb.add(5);
  cout << cb << " |exp. 4,3,2,1" << endl;
  cout << cb.remove() << " |exp. 3,2,1" << endl;

  return 0;
}  // end main()
