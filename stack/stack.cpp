#include "stack.h"
#include <iostream>

using namespace std;

Stack::Stack() {
  size = 0;
  structure = new ItemType[MAX_ITEMS];
}

Stack::~Stack() { delete[] structure; }

int Stack::lenght() { return size; }

bool Stack::is_full() { return size == MAX_ITEMS; }

bool Stack::is_empty() { return size == 0; }

void Stack::push(ItemType item) {
  if (is_full()) {
    cout << "stack is full" << endl; // throw
    return;
  }
  structure[size] = item;
  size++;
}

ItemType Stack::pop() {
  if (is_empty()) {
    cout << "stack is empty" << endl; // throw
    ItemType item;
    return item;
  }
  size--;
  return structure[size];
}

void Stack::print() {
  cout << "[";
  for (int i = 0; i < size; i++) {
    cout << structure[i] << " ";
  }
  cout << "]" << endl;
}
