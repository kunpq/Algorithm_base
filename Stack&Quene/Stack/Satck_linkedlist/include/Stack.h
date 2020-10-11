#include <type_traits>
#ifndef _Stack_H_
#include <iostream>
using namespace std;
struct Node {
  int data;
  struct Node *next;
};
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
int TopAndPop(Stack S);
void Push(int x, Stack S);
int Top(Stack S);
void Pop(Stack S);
#endif