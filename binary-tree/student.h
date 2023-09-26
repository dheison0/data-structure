#include <iostream>

using namespace std;

class Student {
private:
  string name;
  int ra;

public:
  Student();
  Student(string, int);
  string get_name();
  int get_ra();
};