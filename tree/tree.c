#include <stdlib.h>
#include <stdio.h>
#include <string.h>
  
#ifndef treed
#define treed
#include "tree.h"
#endif



string toString()

void writeTree(Tree * current){
  if(current == NULL){
    return;
  }

  printf("%d\n",current->data);
  if(current->left != NULL){
    printf("going left ");
    writeTree(current->left);
  }
  if(current->right != NULL){
    printf("going right ");
    writeTree(current->right);
  }
}

// Returns 1 if data is in tree, otherwise 0
int find(Tree * current,int data){
  if(current==NULL){
    return 0;
  }
  // data is in current node
  if( current->data == data){
    return 1;
  }
  // data is less than current, must be in left tree
  if( data < current->data){
    return find(current->left,data);
  }
  return find(current->right,data);
}


int numberOfElements(Tree * current){
  if(current==NULL){
    return 0;
  }

  return (1 +numberOfElements(current->left) + numberOfElements(current->right));
}

int depth(Tree * current){
  if(current==NULL){
    return 0;
  }

  return 1+max(depth(current->left),depth(current->right));
}

int numberOfLeaves(Tree * current){
  if(current==NULL){
    return 1;
  }

  return (numberOfLeaves(current->left) + numberOfLeaves(current->right));
}

void removeNode(Tree * current, int data){
  if(current == NULL){
    return;
  }


  if(data < current->data){
    removeNode(current->left,data);
    return;
  }

  removeNode(current->right,data);
}

void tearDown(Tree ** current){
  if((*current) == NULL || current == NULL){
    return;
  }

  if((*current)->left != NULL){
    tearDown(&(*current)->left);    
  }
  if((*current)->right != NULL){
    tearDown(&(*current)->right);
  }

  free((*current)); 
  (*current) = NULL; 
}

void insert(Tree * current, int data){
  if(current==NULL){
    current = (Tree*) malloc(sizeof(current));
    current->data = data;
    return;
  }
  
  //element is already in tree
  if(data == current->data){
    return;
  }

  //element is smaller than current node
  if(data < current->data){
    if(current->left == NULL){
        Tree * newNode = (Tree*) malloc(sizeof(current));
        newNode->data = data;
        current->left = newNode;
        return;
    }
    insert(current->left,data);
    return;
  }


  //element is larger than current node
  if(current->right == NULL){
      Tree * newNode = (Tree*) malloc(sizeof(current));
      newNode->data = data;
      current->right = newNode;
      return;
  }
  insert(current->right, data);
}

int max(int a, int b){
  if(a >= b){
    return a;
  }
  return b;
}

//Return 1 if true, 0 otherwise
int isLeaf(Tree * current){
  if(current->left == NULL && current->right == NULL){
    return 1;
  }
  return 0;
}
