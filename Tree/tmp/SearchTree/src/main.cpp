#include "../include/searchTree.h"

int main(void) {
  searchTree tree;
  InitTree(tree, 30);
  for (int i = 0; i < 51; i++) {
    if (i % 2 == 0) {
      Insert(i, tree);
    }
  }
  int a = 20;
  int b = 50;
  findBetween(tree, a, b);
  find_kth(tree, 4);
  return 0;
}