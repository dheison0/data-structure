#include "tree.h"
#include <cstddef>
#include <iostream>
#include <new>

using namespace std;

Tree::Tree() { root = NULL; }

Tree::~Tree() {}

void Tree::delete_tree(Node &) {}

Node *Tree::get_root() { return root; }

bool Tree::is_empty() { return root == NULL; }

bool Tree::is_full() {
  try {
    Node *tmp = new Node;
    delete tmp;
  } catch (bad_alloc exception) {
    return true;
  }
  return false;
}

void Tree::insert(Student student) {
  if (is_full()) {
    cout << "tree is full, can't insert" << endl; // throw
    return;
  }
  Node *newNode = new Node;
  newNode->student = student;
  newNode->left = NULL;
  newNode->right = NULL;
  if (root == NULL) {
    root = newNode;
    return;
  }
  Node *tmpNode = root;
  while (tmpNode != NULL) {
    if (student.get_ra() < tmpNode->student.get_ra()) {
      tmpNode = tmpNode->left;
    } else {
      tmpNode = tmpNode->right;
    }
  }
  tmpNode = newNode;
}

void Tree::remove(Student) {}

void Tree::get(Student &student, bool &found) {
  int wantedRA = student.get_ra();
  found = false;
  Node *tmpNode = root;
  while (tmpNode != NULL && !found) {
    int tmpRA = student.get_ra();
    if (tmpRA == wantedRA) {
      student = tmpNode->student;
      found = true;
    } else if (wantedRA < tmpRA) {
      tmpNode = tmpNode->left;
    } else {
      tmpNode = tmpNode->right;
    }
  }
}

void Tree::print_pre_order(Node *) {}

void Tree::print_order(Node *) {}

void Tree::print_pos_order(Node *) {}
