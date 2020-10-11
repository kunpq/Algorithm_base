#include "../include/Stack.h"
#include <cstddef>
#include <cstdlib>
int IsEmpty(Stack S) { return S->next == NULL; }
Stack CreateStack(void) {
  Stack S = (Stack)malloc(sizeof(struct Node));
  if (S == NULL) {
    std::cout << "Out of Sapce!" << endl;
  }
  S->next = NULL;
  MakeEmpty(S);
  return S;
}

void MakeEmpty(Stack S) {
  if (S == NULL)
    cout << "Create Stack first!" << endl;
  else {
    while (!IsEmpty(S)) {
      Pop(S);
    }
  }
}

void Pop(Stack S) {
  PtrToNode FirstCell;
  if (IsEmpty(S))
    cout << "Empty!" << endl;
  else {
    FirstCell = S->next;
    S->next = S->next->next;
    free(FirstCell);
  }
}
int Top(Stack S) {
  if (IsEmpty(S)) {
    cout << "Empty Stack" << endl;
    return 0;
  }
  return S->next->data;
}

void Push(int x, Stack S) {
  PtrToNode TmpCell;
  TmpCell = (PtrToNode) new (struct Node);
  if (TmpCell == NULL) {
    cout << "Out of Space!" << endl;
  } else {
    TmpCell->data = x;
    TmpCell->next = S->next;
    S->next = TmpCell;
  }
}

int TopAndPop(Stack S) {
  PtrToNode FirstCell;
  if (S->next == NULL) {
    cout << "Empty Stack" << endl;
    return -1;
  } else {
    int x = S->next->data;
    PtrToNode TopCell = S->next;
    S->next = S->next->next;
    free(TopCell);
    return x;
  }
}

void DisposeStack(Stack S) {
  if (S != NULL) {
    free(S);
  }
}