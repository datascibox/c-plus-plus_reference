// Lab 11 - Circular Buffer
// 12/11/2013 sr

#include <cstddef>
#include <iostream>

using std::size_t;
using std::ostream;

#ifndef CIRCBUF_H
#define CIRCBUF_H

class CircBuf {
  public:
    CircBuf(size_t sz=10);
    ~CircBuf();
    long remove();
    bool add(long);
    bool empty();
    bool full();
    friend ostream& operator<<(ostream &out, const CircBuf &cb);
  private:
    long *buffer_;  // array of long
    size_t size_;   // capacity
    size_t count_;  // number of active elements
    long *front_;   // an index to the next element that will be read
    long *back_;    // an index to where the next element will be written
}; // end CircBuf

#endif
