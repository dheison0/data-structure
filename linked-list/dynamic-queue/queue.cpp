#include "queue.h"
#include <cstddef>
#include <iostream>

using namespace std;

DynamicQueue::DynamicQueue() {
  first = NULL;
  last = NULL;
}

DynamicQueue::~DynamicQueue() {
  Node *tmp;
  while (first != NULL) {
    tmp = first;
    first = tmp->next;
    delete tmp;
  }
  last = NULL;
}

void DynamicQueue::push(TypeItem item) {
  if (is_full()) {
    cout << "queue is full"; // throw
    return;
  }
  Node *tmp = new Node{item, NULL};
  if (first == NULL) {
    first = tmp;
  } else {
    last->next = tmp;
  }
  last = tmp;
}

TypeItem DynamicQueue::pop() {
  if (is_empty()) {
    cout << "queue is empty"; // throw
    return TypeItem();
  }
  Node *tmp = first;
  first = tmp->next;
  return tmp->data;
}

bool DynamicQueue::is_empty() { return first == NULL; }

bool DynamicQueue::is_full() {
  Node *tmp;
  try {
    tmp = new Node;
    delete tmp;
  } catch (bad_alloc exception) {
    return true;
  }
  return false;
}

void DynamicQueue::print() {
  Node *node = first;
  cout << "[";
  while (node != NULL) {
    cout << node->data << ", ";
    node = node->next;
  }
  cout << "]";
}
