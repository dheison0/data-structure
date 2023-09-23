#include <iostream>

using namespace std;

class Student {
private:
  int ra;
  string name;

public:
  Student();
  Student(int ra, string name);
  int get_ra();
  string get_name();
};