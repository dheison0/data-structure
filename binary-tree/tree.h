#include "student.h"
#include <iostream>

using namespace std;

struct Node {
  Student student;
  Node *left, *right;
};

class Tree {
private:
  Node *root;

public:
  Tree();
  ~Tree();
  void delete_tree(Node &);
  Node *get_root();
  bool is_empty();
  bool is_full();
  void insert(Student);
  void remove(Student);
  void get(Student &, bool &);
  void print_pre_order(Node *);
  void print_order(Node *);
  void print_pos_order(Node *);
};