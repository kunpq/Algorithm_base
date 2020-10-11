#include "../include/Stack.h"
#define Empty_0 -1;
#define MinStackcSize 5

Stack CreateStack(int MaxElements) {
  Stack S;
  // size should be big enough
  if (MaxElements < MinStackcSize) {
    cout << "Too small" << endl;
    return NULL;
  }
  S = (struct StackRecord *)new (struct StackRecord);
  // malloc error
  if (S == NULL) {
    cout << "Out of Space";
    return NULL;
  }
  S->array = (int *)malloc(sizeof(int) * MaxElements);
  // malloc error
  if (S->array == NULL) {
    cout << "Out of Space!" << endl;
    return NULL;
  }
  S->capacity = MaxElements;
  MakeEmpty(S);
  return S;
}

void MakeEmpty(Stack S) { S->topOfStack = -1; }

void DisposeStack(Stack S) {
  if (S != NULL) {
    free(S->array);
    free(S);
  }
}

int IsEmpty(Stack S) { return S->topOfStack == Empty_0; }
int IsFull(Stack S) { return S->topOfStack == S->capacity; }

void Push(int x, Stack S) {
  if (IsFull(S)) {
    cout << "Full Stack!" << endl;
    return;
  } else {
    S->array[++S->topOfStack] = x;
  }
}

// pop the top data
int Top(Stack S) {
  if (!IsEmpty(S))
    return S->array[S->topOfStack];
  cout << "Empty Stack!" << endl;
  return 0;
}

void Pop(Stack S) {
  if (IsEmpty(S)) {
    cout << "Empty Stack" << endl;
  } else {
    S->topOfStack--;
  }
}

int TopAndPop(Stack S) {
  if (!IsEmpty(S))
    return S->array[S->topOfStack--];
  cout << "Empty Stack" << endl;
  return 0;
}
