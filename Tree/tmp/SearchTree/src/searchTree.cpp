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

void InitTree(searchTree T);

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
  } else if (x < T->data) {
    T->left = Insert(x, T->left);
  } else if (x > T->data) {
    T->right = Insert(x, T->right);
  }
  return T;
}

searchTree Delete(int x, searchTree T) {
  if (T == nullptr) {
    throw "Not found the data";
  } else if (x > T->data) {
    T->right = Delete(x, T->right);
  } else if (x < T->data) {
    T->left = Delete(x, T->left);
  }
  // 此时找到待删除节点
  else if (T->left && T->right) {
    int tmp;
    DeleteMin(T->right, tmp);
    T->data = tmp;
  } else {
    ptrNode tmpNode = T;
    if (T->left == nullptr) {
      T = T->right;
    } else {
      T = T->left;
    }
    delete tmpNode;
  }
  return T;
}

searchTree DeleteMin(searchTree T, int &x) {
  if (T->left == nullptr) {
    ptrNode tmpNode = T->right;
    delete T;
    return tmpNode;
  }
  T->left = DeleteMin(T->left, x);
  return T;
}

searchTree DeleteMax(searchTree T, int &x) {
  if (T->right == nullptr) {
    ptrNode tmpNode = T->left;
    x = T->data;
    delete T;
    return tmpNode;
  }
  T->right = DeleteMax(T->right, x);
  return T;
}

void findBetween(searchTree T, int &a, int &b) {
  if (T == nullptr) {
    return;
  }
  if (!(a > T->data || b < T->data))
    cout << T->data << endl;
  {
    findBetween(T->left, a, b);
    findBetween(T->right, a, b);
    return;
  }
}

void InitTree(searchTree &T, int n) { T = MakeNode(n); }
bool check = false;
int count = 0;
searchTree find_kth(searchTree T, int i) {
  if (T == nullptr)
    return nullptr;
  else {
    if (T->left == nullptr)
      check = true;

    find_kth(T->left, i);
    if (check) {
      count++;
    }
    if (i == count) {
      cout << "The element is " << T->data << endl;
    }
    find_kth(T->right, i);

    return T;
  }
}
