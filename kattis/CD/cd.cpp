#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n, m;
  int total = 0;
  vector<int> cds = vector<int>();
  cin >> n >> m;

  int jack;
  for(int i=0;i<n;++i){
    cin >> jack;
    cds.push_back(jack);
  }

  int jill;
  for(int i=0;i<m;++i){
    cin >> jill;
    for(auto it = cds.begin(); it != cds.end(); ++it){
      if(*it > jill)
        break;
      if(*it == jill){
        ++total;
        break;
      }
    }
  }
  cout << total << "\n";
}