#include "hash.h"
#include <iostream>
using namespace std;

int main() {
  int ra;
  string name;
  bool found;
  Student student;
  Hash hash = Hash(10);
  int option;
  cout << "This program can insert items into a hash table." << endl;
  do {
    cout << "Actual size is: " << hash.size() << endl;
    cout << "hash is full? " << hash.is_full() << endl << endl;
    cout << "1. Insert" << endl;
    cout << "2. Remove" << endl;
    cout << "3. Get" << endl;
    cout << "4. Print" << endl;
    cout << "0. Quit program" << endl << endl;
    cout << "Insert an option > ";
    cin >> option;
    switch (option) {
    case 1:
      if (hash.is_full()) {
        cout << "Hash table is full!!!" << endl;
        break;
      }
      cout << "Insert student informations:" << endl;
      cout << " > RA: ";
      cin >> ra;
      cout << " > Nome: ";
      cin >> name;
      hash.add(Student{ra, name});
      break;
    case 2:
      cout << "Insert student RA: ";
      cin >> ra;
      hash.remove(Student{ra, ""});
      break;
    case 3:
      cout << "Insert student ra: ";
      cin >> ra;
      student = Student{ra, ""};
      hash.get(student, found);
      if (found) {
        cout << "Student name is " << student.get_name() << endl;
      } else {
        cout << "Student not found" << endl;
      }
      break;
    case 4:
      cout << "Hash table content:" << endl;
      hash.print();
    }
    cout << endl;
  } while (option != 0);
  return 0;
}