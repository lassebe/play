#include <iostream>
#include <vector>
#include <algorithm>    /* random_shuffle */
#include <set>
using namespace std;

int main(){
  int width;
  cin >> width;

  int p;
  cin >> p;

  vector<int> partitions = vector<int>();
  partitions.push_back(0);
  set<int> parts = set<int>();
  int part;
  for(int i=0; i < p; ++i){
    cin >> part;
    partitions.push_back(part);
  }
  partitions.push_back(width);
  
  sort(partitions.begin(),partitions.end());

  for(auto it = partitions.begin(); it != partitions.end(); ++it){
    for(auto it2 = it+1; it2 != partitions.end(); ++it2){
      parts.insert(*it2 - *it);
    }
  }

  for(auto it = parts.begin(); it != parts.end(); ++it){
    cout << *it << " ";
  }
  cout << "\n";
}