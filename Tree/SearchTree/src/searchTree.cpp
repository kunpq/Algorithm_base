#include "../include/searchTree.h"

static ptrNode MakeNode(int &data) {
  ptrNode newNode = new treeNode;
  newNode->left = newNode->right = nullptr;
  newNode->data = data;
  return newNode;
}

searchTree MakeEmpty(searchTree T) {
  if (T != nullptr) {
    MakeEmpty(T->left);
    MakeEmpty(T->right);
    free(T);
  }
  return nullptr;
}

position Find(int x, searchTree T) {
  if (T == nullptr) {
    return nullptr;
  }
  if (x < T->data) {
    return Find(x, T);
  } else if (x > T->data) {
    return Find(x, T);
  }
  return T;
}

position FindMin(searchTree T) {
  if (T == nullptr) {
    return nullptr;
  } else if (T->left == nullptr) {
    return T;
  } else {
    return FindMin(T->left);
  }
}

position FindMax(searchTree T) {
  if (T == nullptr) {
    return nullptr;
  } else if (T->right == nullptr) {
    return T;
  } else {
    return FindMax(T);
  }
}

searchTree Insert(int x, searchTree T) {
  if (T == nullptr) {
    ptrNode newNode = MakeNode(x);
    return newNode;
  }
  if (x > T->data) {
    T->right = Insert(x, T->right);
  } else {
    T->left = Insert(x, T->left);
  }
  return T;
}

int size(searchTree T) {
  if (T == nullptr) {
    return 0;
  }
  int a = 0;
  a = size(T->left) + 1;
  a += size(T->right);
  return a;
}

position Find_kth_large(int k, searchTree T) {
  if (k <=size(T->right)) {
    return Find_kth_large(k, T->right);
  }else if (k==size(T->right)+1) {
  return T;
  }else if (k<=size(T)) {
  return Find_kth_large(size(T)-k-1, T->left);
  }else {
  return nullptr;
  }
}