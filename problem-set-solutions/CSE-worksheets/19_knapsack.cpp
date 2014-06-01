// 12/11/2013 sr
// Knapsack

/*
1. Knapsack is a data structure that is discussed in algorithms.
  a. it has a fixed capacity.
  b. every Element that is added to a Knapsack has a particular size.
  c. the total size of all the Elements added to the Knapsack cannot exceed its capacity.
2. Knapsack has to be templated class so it can deal with different kinds of Elements that might be added to it.
    Knapsack assumes that
  a. the added Element has a .size() member function, returning a size_t
  b. the added Element has a .type() member function, returning a string.
3. You don't have to do dynamic memory, use any/all of the STL you choose to accomplish this 
  a. you need an Element class
  b. you need a Knapsack class
*/

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>

using std::boolalpha;
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::ostream;
using std::ostringstream;

template <typename T>
class Knapsack {
  private:
    vector<T> sack_;
    size_t capacity_;
    size_t sz_;
  public:
    Knapsack(size_t sz) : capacity_(sz), sz_(0){};
    string add(T);
    string remove();
    void print();
    };


class Element {
  private:
    size_t size_;
    string type_;
  public:
    size_t size() const {return size_;};
    string type() const {return type_;};
    Element(string st, size_t sz) : size_(sz), type_(st) {};
};


template <typename T>
string Knapsack<T>::add(T ele) {
  string val = "exceeded capacity: ";
  if (sz_ + ele.size() <= capacity_) {
    sack_.push_back(ele);
    sz_ += ele.size();
    val = "item added: ";
  } 
  val += ele.type();
  return val;
}


template <typename T>
string Knapsack<T>::remove() {
  string val = "no item to remove.";
  if (!sack_.empty()) {
    T ele = sack_.back();
    sack_.pop_back();
    sz_ -= ele.size();
    val = "removed: " + ele.type();
  } 
  return val;
}



template <typename T>
void Knapsack<T>::print() {
  cout << "Size: " << sz_ << ", Capacity: " << capacity_ << endl;
  ostringstream oss;
  oss << "ELEMENTS: ";
  for (T ele : this->sack_)
    oss << ele.type() << ", ";
  oss << '\n';
  cout << oss.str();
}


int main() {
  cout << boolalpha;
  Knapsack<Element> k(200);
  Element rock("rock", 100);
  Element feather("feather", 1);
  Element car("car", 1000);
  k.print();

  cout << k.add(rock) << endl;
  k.print();
  cout << k.add(feather) << endl;
  cout << k.add(car) << endl;
  cout << k.remove() << endl;
  k.print();
  return 0;
} // end main()


