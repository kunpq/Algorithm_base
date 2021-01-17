#ifndef _AVL_H_
#define _AVL_H_
#include <iostream>
struct avlNode;
typedef struct avlNode *position;
typedef struct avlNode *avlTree;

struct avlNode {
  int data;
  avlTree left;
  avlTree right;
  int height;
};

void MakeEMpty(avlTree T);
position Find(int x, avlTree T);
position FindMin(avlTree T);
position FindMax(avlTree T);
avlTree Insert(int x, avlTree T);
// avlTree Delete(int x, avlTree T);
int Retrieve(position P);
#endif