#include "../include/Stack.h"

int main(void) {
  Stack S = CreateStack(100);
  for (int i = 0; i < 100; i++)
    Push(i, S);
  int a = Top(S);
  Pop(S);
  int b = Top(S);
  cout << S->capacity << endl;
  int c = TopAndPop(S);
  for (int i = 0; i < S->topOfStack; i++)
    cout << S->array[i] << endl;
  DisposeStack(S);
  cout << a << b << c << endl;
}