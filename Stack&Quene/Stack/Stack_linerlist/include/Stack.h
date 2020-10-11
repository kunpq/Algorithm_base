#ifndef _STACK_H_
#include <cstdlib>
#include <iostream>
using namespace std;
struct StackRecord;
typedef struct StackRecord *Stack;

struct StackRecord {
  int capacity;
  int topOfStack;
  int *array;
};


int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(int x, Stack S);
int Top(Stack S);
void Pop(Stack S);
int TopAndPop(Stack S);
#endif