#include "../include/AVL.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main(void) {
  avlTree T = nullptr;
  avlTree posi;
  srand(time(0));
  int number;
  for (int i = 0; i < 100; ++i) {
    number = rand() % 100 + 1;
    cout << number << endl;
    T = Insert(number, T);
  }
  posi = FindMin(T);
  cout << posi->data << endl;
  posi = FindMax(T);
  cout << posi->data << endl;
  posi = Find(29, T);
  if (posi) {
    cout << posi->data << endl;
  } else {
    cout << "not find" << endl;
  }
  cout << T->height << endl;
  return 0;
}