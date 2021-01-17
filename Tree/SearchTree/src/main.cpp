#include "../include/searchTree.h"
#include <iostream>

using namespace std;
int main(void) {

  searchTree T = nullptr;
  T=Insert(4, T);
  T=Insert(2, T);
  T=Insert(1, T);
  T=Insert(3, T);
  T=Insert(6, T);
  T=Insert(5, T);
  T=Insert(7, T);
  cout << size(T) << endl;
  cout<<Find_kth_large(2, T)->data<<endl;
  return 0;
}