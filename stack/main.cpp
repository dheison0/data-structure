#include "stack.h"
#include <iostream>

using namespace std;

int main() {
  Stack stack;
  cout << "Stack initialized" << endl;
  cout << "Size " << stack.lenght() << ", full? " << stack.is_full()
       << ", empty? " << stack.is_empty() << endl;
  stack.print();

  for (ItemType i = 1; i <= 101; i++) {
    ItemType v = i * i;
    cout << "Trying to insert value " << v << "..." << endl;
    stack.push(v);
    cout << "Size " << stack.lenght() << ", full? " << stack.is_full()
         << ", empty? " << stack.is_empty() << endl;
  }
  stack.print();
  while (!stack.is_empty()) {
    cout << "Pop item " << stack.pop() << ", new size " << stack.lenght()
         << endl;
  }
  stack.print();
  return 0;
}