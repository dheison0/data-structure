#include "queue.h"
#include <iostream>

using namespace std;

Queue::Queue() {
  first = 0;
  last = 0;
  data = new TypeItem[MAX_ITEMS];
}

Queue::~Queue() { delete[] data; }

int Queue::lenght() { return last - first; }
bool Queue::is_empty() { return lenght() == 0; }
bool Queue::is_full() { return lenght() == MAX_ITEMS; }

void Queue::insert(TypeItem item) {
  if (is_full()) {
    cout << "queue is full"; // throw
    return;
  }
  data[last % MAX_ITEMS] = item;
  last++;
}

TypeItem Queue::pop() {
  if (is_empty()) {
    cout << "queue is empty"; // throw
    return TypeItem();
  }
  return data[first++ % MAX_ITEMS];
}

void Queue::print() {
  cout << "[";
  for (int i = first; i < last; i++) {
    cout << data[i] << ", ";
  }
  cout << "]";
}