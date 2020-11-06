#ifndef _SEARCH_TREE_
#define _SEARCH_TREE_
#include <iostream>
using namespace std;
typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
}*ptrNode;
typedef struct treeNode *position;
typedef struct treeNode *searchTree;
searchTree MakeEmpty(searchTree T);
position Find(int x, searchTree T);
position FindMin(searchTree T);
position FindMax(searchTree T);
searchTree Insert(int x, searchTree T);
searchTree Delete(int x, searchTree T);
int Retrieve(position P);
#endif