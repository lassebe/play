#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
  int n, cap;
  cin >> n >> cap;

  int v[n];
  int w[n];
  for(int i=0; i < n; ++i){
    cin >> v[i] >> w[i];
  }

  int value = 0;
  int weight = 0;
  int taken[n];
  for(int i=0; i<n;++i){
    taken[i] = 0;
  }

  int table[n+1][cap+1];

  for (int j=0;j<=cap; ++j){
    table[0][j] = 0;
  }
  
  for(int i=1;i<=n;++i){
    for (int j=0;j<=cap; ++j){
      if(w[i-1] <= j){
        table[i][j] = max(table[i-1][j],table[i-1][j-w[i-1]] + v[i-1]);
      }else{
        table[i][j] = table[i-1][j];
      }
    }
  }

  for(int i=0;i<=n;++i){
    for (int j=0;j<=cap; ++j){
      cout << table[i][j] << " ";
    }
    cout << "\n";
  }


  int j = cap;
  for(int i=n;i>0;--i){
    if(table[i][j] == 0)
      break;
    if(table[i][j] != table[i-1][j]){
      j -= w[i-1];
      taken[i-1] = 1;
      value += v[i-1];
    }
  }

  cout << value << " 1\n";
  for(int i=0; i < n; ++i){
    cout << taken[i] << " ";
  }
  cout << "\n";
  return 0;
}