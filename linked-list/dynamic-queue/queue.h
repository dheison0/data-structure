typedef int TypeItem;

struct Node {
  TypeItem data;
  Node *next;
};

class DynamicQueue {
private:
  Node *first, *last;

public:
  DynamicQueue();
  ~DynamicQueue();
  void push(TypeItem);
  TypeItem pop();
  bool is_empty();
  bool is_full();
  void print();
};