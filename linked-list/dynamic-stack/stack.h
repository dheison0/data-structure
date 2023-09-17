typedef int TypeItem;

struct Node {
  TypeItem data;
  Node *next;
};

class DynamicStack {
private:
  Node *LastNode;

public:
  DynamicStack();
  ~DynamicStack();
  bool is_full();
  bool is_empty();
  void insert(TypeItem);
  TypeItem pop();
  void print();
};