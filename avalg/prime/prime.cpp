#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

unsigned int N = 13;

unsigned int gcd(unsigned int a, unsigned int b) {
  if ( b == 0 )
    return a;

  return gcd(b, a % b);
}

unsigned int power(unsigned int base, unsigned int exponent ) {
  unsigned int ret = 1;
  while ( exponent-- != 0 ) {
    ret *= base;
  }
  return ret;
}

bool is_prime(const unsigned int n) {
  unsigned int a = rand() % (n-1) + 1;  
  if( gcd(a,n) > 1 ){
    return false;
  }

  if ( (power(a,n-1) % n) == 1 ) {
    return true;
  }

  return false;
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  if ( is_prime(N) )
    printf("%d is prime\n", N);
  else
    printf("%d is not prime\n", N);
  return 0;
}