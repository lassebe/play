
struct tree {
  int data;
  struct tree * left;
  struct tree * right;
};

typedef struct tree Tree;

void writeNode(Tree * t);

void writeTree(Tree * current);

// Returns 1 if data is in tree, otherwise 0
int find(int data, Tree * current); 

int numberOfElements(Tree * current);

int depth(Tree * current);

int numberOfLeaves(Tree * current);

void insert(int data, Tree * current);

void remove_node(Tree * target, Tree * current);

