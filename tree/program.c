#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

int main(){
  //There really must be a better way to write test-code...
  Tree * t = (Tree *) malloc(sizeof(Tree));
  t->data = 5;
  Tree * t2 = (Tree *) malloc(sizeof(Tree));
  Tree * t3 = (Tree *) malloc(sizeof(Tree));
  t2->data = 4;
  t3->data = 6;
  t->left = t2;
  t->right = t3;
  writeTree(t);
  printf("Depth is %d\n",depth(t));
  insert(t,7);
  writeTree(t);
  printf("Depth is %d\n",depth(t));
  tearDown(&t);
  if(t==NULL){
    printf("HEJ");
  }
  writeTree(t);

  return 0;

}
