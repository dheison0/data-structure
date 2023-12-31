#include "tree.h"
#include <cstddef>
#include <iostream>

using namespace std;

Tree::Tree() { root = NULL; }

Tree::~Tree() { delete_tree(root); }

void Tree::delete_tree(Node *node)
{
  if (node != NULL)
  {
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
  }
}

Node *Tree::get_root() { return root; }

bool Tree::is_empty() { return root == NULL; }

bool Tree::is_full()
{
  try
  {
    Node *tmp = new Node;
    delete tmp;
  }
  catch (bad_alloc exception)
  {
    return true;
  }
  return false;
}

void Tree::insert(Student student)
{
  if (is_full())
  {
    cout << "tree is full, can't insert" << endl; // throw
    return;
  }
  Node *newNode = new Node;
  newNode->student = student;
  newNode->left = NULL;
  newNode->right = NULL;
  if (root == NULL)
  {
    root = newNode;
    return;
  }
  Node *tmpNode = root;
  while (tmpNode != NULL)
  {
    if (student.get_ra() < tmpNode->student.get_ra())
    {
      if (tmpNode->left == NULL)
      {
        tmpNode->left = newNode;
        break;
      }
      tmpNode = tmpNode->left;
    }
    else if (tmpNode->right == NULL)
    {
      tmpNode->right = newNode;
      break;
    }
    else
    {
      tmpNode = tmpNode->right;
    }
  }
}

void Tree::remove(Student student) { removeSearch(student, root); }

void Tree::removeSearch(Student student, Node *&actual)
{
  int ra = student.get_ra();
  if (ra == actual->student.get_ra())
  {
    delete_node(actual);
  }
  else if (ra < actual->student.get_ra())
  {
    removeSearch(student, actual->left);
  }
  else
  {
    removeSearch(student, actual->right);
  }
}

void Tree::delete_node(Node *&actual)
{
  Node *tmpNode = actual;
  if (actual->left == NULL)
  {
    actual = actual->right;
    delete tmpNode;
  }
  else if (actual->right == NULL)
  {
    actual = actual->left;
    delete tmpNode;
  }
  else
  {
    Student nextStudent;
    get_next(nextStudent, actual);
    actual->student = nextStudent;
    removeSearch(nextStudent, actual->right);
  }
}

void Tree::get_next(Student &student, Node *actual)
{
  actual = actual->right;
  while (actual->left != NULL)
    actual = actual->left;
  student = actual->student;
}

void Tree::get(Student &student, bool &found)
{
  int wantedRA = student.get_ra();
  found = false;
  Node *tmpNode = root;
  while (tmpNode != NULL)
  {
    int tmpRA = tmpNode->student.get_ra();
    if (tmpRA == wantedRA)
    {
      student = tmpNode->student;
      found = true;
      break;
    }
    else if (wantedRA < tmpRA)
    {
      tmpNode = tmpNode->left;
    }
    else
    {
      tmpNode = tmpNode->right;
    }
  }
}

void Tree::print_pre_order(Node *node)
{
  if (node != NULL)
  {
    cout << "Name: '" << node->student.get_name()
         << "' Ra: " << node->student.get_ra() << endl;
    print_pre_order(node->left);
    print_pre_order(node->right);
  }
}

void Tree::print_order(Node *node)
{
  if (node != NULL)
  {
    print_order(node->left);
    cout << "Name: '" << node->student.get_name()
         << "'\tRa: " << node->student.get_ra() << endl;
    print_order(node->right);
  }
}

void Tree::print_pos_order(Node *node)
{
  if (node != NULL)
  {
    print_pos_order(node->left);
    print_pos_order(node->right);
    cout << "Name: '" << node->student.get_name()
         << "' Ra: " << node->student.get_ra() << endl;
  }
}
