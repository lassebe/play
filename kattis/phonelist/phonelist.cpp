#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool prefix_free(vector<string>& numbers,unordered_set<string>& dict){
  sort(numbers.begin(),numbers.end());
  bool flag = true;
  for(int i=0;i<numbers.size();++i){
    string s = "";
    for(int j=0;flag && j<numbers[i].size()-1;++j){
      s += numbers[i][j];
      if(dict.find(s) != dict.end())
        return false;
    }
  }
  
  return true;
}

int main(int argc, char const *argv[]) {
  int tests, n;
  cin >> tests;
  while(tests--){
    cin >> n;
    vector<string> numbers(n);
    unordered_set<string> dict;
    for(int i=0;i<n;++i){
      cin >> numbers[i]; 
      dict.insert(numbers[i]);
    }

    if(prefix_free(numbers,dict))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}