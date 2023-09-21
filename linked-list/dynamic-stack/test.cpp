#include "stack.h"
#include <iostream>
#include <sys/types.h>

using namespace std;

int main() {
  DynamicStack stack;
  string d;
  while (1) {
    for (int i = 1; i <= 1000000; i++) {
      stack.insert(TypeItem(i * i));
    }
    cout << "Press enter to add more 1000000 items";
    cin >> d;
  }
  return 0;
}