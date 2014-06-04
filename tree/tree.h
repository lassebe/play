
struct tree {
  int data;
  struct tree * left;
  struct tree * right;
};

typedef struct tree Tree;


void writeTree(Tree * current);

// Returns 1 if data is in tree, otherwise 0
int find(Tree * current, int data); 

int numberOfElements(Tree * current);

int depth(Tree * current);

int numberOfLeaves(Tree * current);

void insert( Tree * current,int data);

void removeNode(Tree * current, int data);

void tearDown(Tree ** current);
