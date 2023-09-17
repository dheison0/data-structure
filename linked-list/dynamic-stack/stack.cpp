#include "stack.h"
#include <cstddef>
#include <iostream>

using namespace std;

DynamicStack::DynamicStack() { LastNode = NULL; }

DynamicStack::~DynamicStack() {
  Node *node = LastNode;
  while (node != NULL) {
    Node *next = node->next;
    delete node;
    node = next;
  }
}

bool DynamicStack::is_full() {
  Node *NewNode;
  try {
    NewNode = new Node;
    delete NewNode;
    return false;
  } catch (bad_alloc exception) {
    return true;
  }
}

bool DynamicStack::is_empty() { return LastNode == NULL; }

void DynamicStack::insert(TypeItem item) {
  if (is_full()) {
    cout << "system memory is full"; // throw
    return;
  }
  LastNode = new Node{item, LastNode};
}

TypeItem DynamicStack::pop() {
  if (is_empty()) {
    cout << "stack is empty"; // throw
    return TypeItem();
  }
  Node *oldNode = LastNode;
  LastNode = oldNode->next;
  TypeItem data = oldNode->data;
  delete oldNode;
  return data;
}

void DynamicStack::print() {
  Node *node = LastNode;
  cout << "[";
  while (node != NULL) {
    cout << node->data << ", ";
    node = node->next;
  }
  cout << "]" << endl;
}
