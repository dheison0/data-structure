#include "hash.h"
#include <iostream>
using namespace std;

Hash::Hash(int size) {
  lenght = 0;
  max_items = size * 1.3;
  max_positions = size;

  structure = new Student[max_items];
}

Hash::~Hash() { delete[] structure; }

int Hash::hash_function(Student student) {
  return (student.get_ra() % max_positions);
}

bool Hash::is_full() { return max_positions == lenght; }

int Hash::size() { return lenght; }

void Hash::add(Student student) {
  if (is_full()) {
    cout << "hash table is full"; // throw
    return;
  }
  int p = hash_function(student);
  while (structure[p].get_ra() > 0) {
    p = (p + 1) % max_positions;
  }
  structure[p] = student;
  lenght++;
}

void Hash::remove(Student student) {
  int p = hash_function(student);
  if (structure[p].get_ra() == -1)
    return;
  while (structure[p].get_ra() != -1) {
    if (structure[p].get_ra() == student.get_ra()) {
      structure[p] = Student(-2, "");
      lenght--;
      break;
    }
    p = (p + 1) % max_positions;
  }
}

void Hash::get(Student &student, bool &search) {
  search = false;
  int p = hash_function(student);
  while (structure[p].get_ra() != -1) {
    if (structure[p].get_ra() == student.get_ra()) {
      student = structure[p];
      search = true;
      break;
    }
    p = (p + 1) % max_positions;
  }
}

void Hash::print() {
  cout << "{" << endl;
  for (int i = 0; i < max_items; i++) {
    if (structure[i].get_ra() > 0) {
      cout << "  " << i << "->" << structure[i].get_ra() << ": "
           << structure[i].get_name() << "," << endl;
      ;
    }
  }
  cout << "}" << endl;
}