#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  stringstream ss;
  while(n != 0){
    if((n & 1) !=0){
      ss << "1";
    }else{
      ss << "0";
    }

    n = n >> 1;
  }
  string str = ss.str();

  char * ptr;

  long parsed = strtol(str.c_str(), &ptr,2);
  printf("%d\n", parsed);
  return 0;
}