#include "queue.h"
#include <iostream>
using namespace std;

int main() {
  Queue queue;
  int option;
  TypeItem item;
  cout << "This program can insert items into a queue." << endl;
  do {
    cout << "Actual size is: " << queue.lenght() << endl;
    cout << "Queue is full? " << queue.is_full() << ", is empty? "
         << queue.is_empty() << endl;
    cout << "Items are: ";
    queue.print();
    cout << endl << endl;
    cout << "1. Insert item" << endl;
    cout << "2. Pop the first item" << endl;
    cout << "0. Quit program" << endl << endl;
    cout << "Insert an option > ";
    cin >> option;
    switch (option) {
    case 1:
      cout << "Put a value: ";
      cin >> item;
      queue.insert(item);
      break;
    case 2:
      cout << "Removed item is: " << queue.pop() << endl;
    }
    cout << endl;
  } while (option != 0);
  return 0;
}