#include "student.h"

Student::Student()
{
  ra = -1;
  name = "";
}

Student::Student(string n, int r)
{
  name = n;
  ra = r;
}

string Student::get_name() { return name; }

int Student::get_ra() { return ra; }
