#include "tree.h"
#include <iostream>
using namespace std;

int main()
{
  Tree tree;
  Student student;
  int option, ra;
  string name;
  bool found = false;
  cout << "That is a Binary Search Tree program." << endl;
  do
  {
    cout << "Tree is full? " << tree.is_full() << ", is empty? "
         << tree.is_empty() << endl;
    cout << endl
         << endl;
    cout << "1. Insert item" << endl;
    cout << "2. Remove item" << endl;
    cout << "3. Get item" << endl;
    cout << "4. Print: pre order" << endl;
    cout << "5. Print: order" << endl;
    cout << "6. Print: pos order" << endl;
    cout << "0. Quit program" << endl
         << endl;
    cout << "Insert an option > ";
    cin >> option;
    switch (option)
    {
    case 1:
      cout << "Insert student informations:" << endl;
      cout << "  RA: ";
      cin >> ra;
      cout << "  Name: ";
      cin >> name;
      student = Student{name, ra};
      tree.insert(student);
      break;
    case 2:
      cout << "What is the student RA? ";
      cin >> ra;
      student = Student{"", ra};
      tree.remove(student);
      break;
    case 3:
      cout << "Insert student RA: ";
      cin >> ra;
      student = Student("", ra);
      tree.get(student, found);
      if (found)
      {
        cout << "Student: name='" << student.get_name()
             << "' ra=" << student.get_ra() << endl;
      }
      else
      {
        cout << "Student not found!" << endl;
      }
      break;
    case 4:
      tree.print_pre_order(tree.get_root());
      break;
    case 5:
      tree.print_order(tree.get_root());
      break;
    case 6:
      tree.print_pos_order(tree.get_root());
      break;
    }
    cout << endl;
  } while (option != 0);
  return 0;
}