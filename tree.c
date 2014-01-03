#include <stdlib.h>
#include <stdio.h>
#include <string.h>
  
#ifndef treed
#define treed
#include "tree.h"
#endif

/*
  struct tree {
    int data;
    struct tree * left;
    struct tree * right;
  };
*/



void writeNode(Tree * t){
}

void writeTree(Tree * current){
}

// Returns 1 if data is in tree, otherwise 0
int find(int data, Tree * current){
  if(current==NULL){
    return 0;
  }
  // data is in current node
  if( (*current).data == data){
    return 1;
  }
  // data is less than current, must be in left tree
  if( data < (*current).data){
    return find(data, current->left);
  }
  return find(data,current->right);
}


int numberOfElements(Tree * current){
  if(current==NULL){
    return 0;
  }

  return (1 +numberOfElements(current->left) + numberOfElements(current->right));
}

int depth(Tree * current){
}

int numberOfLeaves(Tree * current){
  if(current==NULL){
    return 1;
  }

  return (numberOfLeaves(current->left) + numberOfLeaves(current->right));
}

void remove_node(Tree * target, Tree * current){
}

void insert(int data, Tree * current){
}
