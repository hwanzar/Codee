#include <bits/stdc++.h>
using namespace std;

template <typename E> class List {
private:
  void operator=(const List &) {} // Protect assignment
  List(const List &) {}           // Protect copy constructor
public:
  List() {}          // Default constructor
  virtual ~List() {} // Base destructor

  // Clear contents from the list, to make it empty
  virtual void clear() = 0;
};

int main() {
  int *num = NULL;
  *num = 42;
  cout << &num;
  return 0;
}
