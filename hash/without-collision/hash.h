#include "student.h"

class Hash {
private:
  int hash_function(Student);
  int max_items;
  int max_positions;
  int lenght;
  Student *structure;

public:
  Hash(int, int);
  ~Hash();
  bool is_full();
  int size();
  void add(Student);
  void remove(Student);
  void get(Student &student, bool &search);
};