#include "student.h"

Student::Student() {
  ra = -1;
  name = "";
}

Student::Student(int r, string n) {
  ra = r;
  name = n;
}

int Student::get_ra() { return ra; }

string Student::get_name() { return name; }
