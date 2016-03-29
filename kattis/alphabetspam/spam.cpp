#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  string s;
  cin >> s;
  int total = s.size();
  int white_space = 0, lowercase = 0, uppercase = 0, symbols = 0;
  for(int i=0;i<s.size();++i){
    int x = s.at(i);
    if(x == 95){
      ++white_space;
    }else if(x >= 65 && x <= 90){
      ++uppercase;
    }else if(x >= 97 && x <= 122){
      ++lowercase;
    }else{
      ++symbols;
    }
  }

  printf("%f\n", (double)white_space/total);
  printf("%f\n", (double)lowercase/total);
  printf("%f\n", (double)uppercase/total);
  printf("%f\n", (double)symbols/total);

  return 0;
}