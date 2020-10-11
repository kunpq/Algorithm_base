#include "../include/Stack.h"

int main(void) {
  Stack S = CreateStack();
  for (int i = 0; i < 100; i++)
    Push(i, S);
  int a = Top(S);
  Pop(S);
  int b = Top(S);
  cout << Top(S) << endl;
  int c = TopAndPop(S);
  MakeEmpty(S);
  DisposeStack(S);
  cout << a << b << c << endl;
}