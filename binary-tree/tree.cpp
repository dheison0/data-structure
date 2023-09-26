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

void Tree::insert(Student) {}

void Tree::remove(Student) {}

void Tree::get(Student &, bool &) {}

void Tree::print_pre_order(Node *) {}

void Tree::print_order(Node *) {}

void Tree::print_pos_order(Node *) {}
