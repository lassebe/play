#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
  string s;
  cin >> s;
  int d_count = 0, u_count = 0, ego_count = 0;
  char current = s[1];
  if(s[1] != s[0]){
    ++d_count;
    ++u_count;
    ++ego_count;
  }
  if(s[1] == 'D')
    ++d_count;
  
  if(s[1] == 'U')
    ++u_count;

  for(int i=2;i<s.size();++i){
    if(s[i] == 'D')
      d_count += 2;
    if(s[i] == 'U')
      u_count += 2;

    if(s[i] != current){
      ++ego_count;
      current = s[i];
    }
  }
  cout << d_count << endl;
  cout << u_count << endl;
  cout << ego_count << endl;
  return 0;
}