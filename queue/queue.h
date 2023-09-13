typedef int TypeItem;
const int MAX_ITEMS = 5;

class Queue {
private:
  int first, last;
  TypeItem *data;

public:
  Queue();
  ~Queue();
  void insert(TypeItem);
  TypeItem pop();
  int lenght();
  bool is_full();
  bool is_empty();
  void print();
};