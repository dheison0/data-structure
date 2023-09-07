typedef int ItemType;
const int MAX_ITEMS = 100;

class Stack {
private:
  int size;
  ItemType *structure;

public:
  Stack();
  ~Stack();
  int lenght();
  bool is_full();
  bool is_empty();
  void push(ItemType item);
  ItemType pop();
  void print();
};