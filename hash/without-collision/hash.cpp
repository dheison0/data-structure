#include "hash.h"
#include <iostream>
using namespace std;

Hash::Hash(int size, int max) {
  lenght = 0;
  max_items = max;
  max_positions = size;

  structure = new Student[max_positions];
}

Hash::~Hash() { delete[] structure; }

int Hash::hash_function(Student student) {
  return (student.get_ra() % max_positions);
}

bool Hash::is_full() { return max_items == lenght; }

int Hash::size() { return lenght; }

void Hash::add(Student student) {
  if (is_full()) {
    cout << "hash table is full"; // throw
    return;
  }
  int p = hash_function(student);
  if (structure[p].get_ra() == -1) {
    lenght++;
  }
  structure[p] = student;
}

void Hash::remove(Student student) {
  int p = hash_function(student);
  if (structure[p].get_ra() == -1)
    return;
  structure[p] = Student(-1, "");
  lenght--;
}

void Hash::get(Student &student, bool &search) {
  int p = hash_function(student);
  if (structure[p].get_ra() != student.get_ra()) {
    search = false;
    return;
  }
  student = structure[p];
  search = true;
}
