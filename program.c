#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

int main(){
  printf("Hello world!\n");
  //There really must be a better way to write test-code...
  Tree * t = (Tree *) malloc(sizeof(Tree));
  t->data = 5;
  Tree * t2 = (Tree *) malloc(sizeof(Tree));
  Tree * t3 = (Tree *) malloc(sizeof(Tree));
  t2->data = 4;
  t3->data = 6;
  t->left = t2;
  t->right = t3;

  printf("%d \n",numberOfLeaves(t));

  free(t);
  free(t2);
  free(t3);

  return 0;

}
