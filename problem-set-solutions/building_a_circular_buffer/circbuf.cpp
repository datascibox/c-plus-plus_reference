// Lab 11 - Circular Buffer
// 12/11/2013 sr

#include <cstddef>
#include <limits>
#include <iostream>

using std::ostream;
using std::size_t;


#include "circbuf.h"


// =======================
// Constructor
// =======================

CircBuf::CircBuf(size_t sz) {
  size_ = sz;
  buffer_ = new long [size_];
  count_ = 0; 
  front_ = buffer_;
  back_ = buffer_;
}

// =======================
// Destructor
// =======================

CircBuf::~CircBuf() {
  delete [] buffer_;
} 

// =======================
// Member Functions
// =======================


// if CircBuf is not empty, returns the long indexed by front 
// then advances front by one.
// if the CircBuf is empty, returns the smallest long.

long CircBuf::remove() {
  long val = std::numeric_limits<long>::min();
  if (!empty()) {
    val = *front_;
    ++front_;
    --count_;
  }
  return val;
} // end CircBuf::remove()


// returns true if the CircBuf is empty, false otherwise.
bool CircBuf::empty() {
  bool val = 0;
  if (count_ == 0)
    val = 1;
  return val;
} // end CircBuf::empty()


// returns true if the CircBuf is full, false otherwise.
bool CircBuf::full() {
  bool val = 0;
  if (count_ == size_)
    val = 1;
  return val;
} // end CircBuf::full()


// returns true if it can add to the CircBuf (it isn't full) 
// and advances the back index by one.
bool CircBuf::add(long l) {
  bool val = 0;
  if (!full()) {
    *back_ = l;
    ++back_;
    ++count_;
    val = 1;
  }
  return val;
} // end CircBuf::add()    



// =======================
// Regular functions
// =======================

ostream& operator<<(ostream &out, const CircBuf &cb) {
  for (size_t i = 0; i < cb.count_; i++)
    out << cb.buffer_[i] << ", ";
  return out;
}

