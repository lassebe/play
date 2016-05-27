#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

unsigned int N = 13;

/*
 * Returns the greatest common divisor of a and b.
 */
unsigned int gcd(unsigned int a, unsigned int b) {
  if ( a == 0 )
    return b;
  if ( b == 0 )
    return a;

  return gcd(b, a % b);
}

/*
 * Returns base to the exponent power.
 */
unsigned int power(unsigned int base, unsigned int exponent ) {
  unsigned int ret = 1;
  while ( exponent-- != 0 ) {
    ret *= base;
  }
  return ret;
}

/*
 * Probabilistically returns true if n is prime.
 * If it returns false, n is definitely composite.
 * Fooled by Carmichael numbers. 
 */
bool is_prime(const unsigned int n) {
  unsigned int a = rand() % (n-1) + 1;  
  if( gcd(a,n) > 1 )
    return false;
  
  if ( (power(a,n-1) % n) == 1 ) 
    return true;
  
  return false;
}

/*
 * Probabilistically returns true if n is prime.
 * k defines the accuracy of the test.
 */
bool rabin_miller(unsigned int n, unsigned int k) {
  unsigned int rem = n-1;
  unsigned int d = 1;
  unsigned int r = 0;
  while ( gcd(rem,2) != 1 ) {
    rem /= 2;
    ++r;
  }
  d = rem;

  // buffer to prevent silly bugs in later loop
  if ( r == 0 )
    ++r;

  while ( k-- ) {
    unsigned int a = rand() % (n-2) + 2;
    unsigned int x = power(a,d) % n;

    //printf("a = %d\n", a);
    //printf("d = %d\n", d);
    //printf("x = %d\n", x);
    //printf("\n");
    
    if ( x == 1 || x == n-1 ) {
      continue;
    }

    bool witness = true;

    for(unsigned int i=0; i < r-1; ++i) {
      x = (x*x) % n;

      //printf("x^2 = %d\n\n", x);
      if ( x == 1 )
        return false;
      if ( x == n-1 ) {
        witness = false;
        break;
      }
    }
    if ( witness )
      return false;
  }

  return true;
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  if ( rabin_miller(N,4) )
    printf("%d is prime\n", N);
  else
    printf("%d is not prime\n", N);
  
  return 0;
}