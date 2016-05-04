#include "union_find.hpp"
#include <iostream>
using namespace std;

int main(){
  int n, lines, x, y;
  string operation;
 
  cin >> n;
  union_find uf(n);
  cin >> lines;
  for(int i=0;i<lines;++i){
    cin >> operation;
    cin >> x >> y;
    if(operation == "?"){
      if(uf.find(x) == uf.find(y)){
        cout << "yes\n";
      }else{
        cout << "no\n";
      }
    }else{
      uf.unify(x,y);
    }
  }

  return 0;
}