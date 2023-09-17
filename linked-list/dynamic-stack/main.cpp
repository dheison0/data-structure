#include "stack.h"
#include <iostream>

using namespace std;

int main() {
  DynamicStack stack;
  cout << "Stack initialized" << endl;
  cout << "Is full? " << stack.is_full() << ", empty? " << stack.is_empty()
       << endl;
  stack.print();

  for (TypeItem i = 1; i <= 101; i++) {
    TypeItem v = i * i;
    cout << "Trying to insert value " << v << "..." << endl;
    stack.insert(v);
    cout << "Is full? " << stack.is_full() << ", empty? " << stack.is_empty()
         << endl;
  }
  stack.print();
  while (!stack.is_empty()) {
    cout << "Pop item " << stack.pop() << endl;
  }
  stack.print();
  return 0;
}