#ifndef _SPLAYTREE_H_
#define _SPLAYTREE_H_
#include <iostream>
using namespace std;

struct Item;
struct splayTreeNode;
struct splayTree;
typedef splayTreeNode* ptrToNode;
typedef Item* ptrToItem;

struct Item {
  int data;
  string str;
};

struct splayTreeNode {
  ptrToItem item;
  splayTreeNode *left;
  splayTreeNode *right;
};

struct splayTree {
  ptrToNode root;
  int size;
};

ptrToNode Insert(ptrToNode&root,ptrToItem &item);
ptrToNode Delete(splayTree &tr);

ptrToNode Find(const ptrToItem &item,ptrToNode root);
ptrToNode FindMax(const ptrToItem &item,ptrToNode root);
ptrToNode FindMin(const ptrToItem &item, ptrToNode root);



void Down_Top_Rotate(splayTree&tr);
void MakeEmpty(ptrToNode&root);
#endif