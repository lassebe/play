#include <iostream>
using namespace std;

const int SIZE = 256;
unsigned char * S;
int KEYSIZE = 0;

void key_scheduling(const unsigned char*);
void generate_stream(int);
void print_S(){
  for(int i=0;i<SIZE;++i){
    printf("%d ",S[i]);
  }
  printf("\n");
}
/*
  An implementation of RC4.
  Usage: ./rc4 *key*
  Where key is between a string of between 5 and 16 characters. (40-128 bits)

*/
int main(int argc, char const *argv[]) {
  KEYSIZE = 5;

  const unsigned char key [] = "abqde";
  S = new unsigned char[SIZE];
  for(int i=0;i<KEYSIZE;++i){
    printf("%d ", key[i]);
  }
  printf("\n");
  key_scheduling(key);
  
  printf("\n");
  printf("\n");
  
  generate_stream(200);

  delete[](S);

  return 0;
}

void key_scheduling(const unsigned char * key) {
  /*
    Initialize to identity permutation.
  */
  for(int i=0;i<SIZE;++i){
    S[i] = i;
  }

  /*
    Initial shuffle with key.
  */
  unsigned char j = 0;
  for(int i=0;i<SIZE;++i){
    j = (j + S[i] + key[i % KEYSIZE]) % SIZE;
    unsigned char tmp = S[i];
    S[i] = S[j];
    S[j] = tmp;
  }

  print_S();
}

/*
  Generate a the pseudo-random stream.
*/
void generate_stream(int stream_size) {
  unsigned char i = 0;
  unsigned char j = 0;
  while(stream_size--){
    i += (i + 1);
    j += S[i];
    unsigned char tmp = S[i];
    S[i] = S[j];
    S[j] = tmp;
    tmp = S[(S[i] + S[j]) % SIZE];
    printf("%d ",tmp);
  }
  printf("\n");
}