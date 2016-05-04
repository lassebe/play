#include <vector>

struct union_find {
public:
  union_find(const int n){
    uf = std::vector<int>(n, -1);
  }

  bool unify(int x, int y){
    int x_root = find(x);
    int y_root = find(y);
    if(x_root == y_root){
      return false;
    }
    if(uf[x_root] < uf[y_root]){
      uf[x_root] += uf[y_root];
      uf[y_root] = x_root;
    }else{
      uf[y_root] += uf[x_root];
      uf[x_root] = y_root;
    }
    return true;
  }

  int find(int x){
    if(uf[x] < 0){
      return x;
    }else{
      uf[x] = find(uf[x]);
    }
  }

private:
  std::vector<int> uf;
};
