#include "../include/SplayTree.h"

static void InitNode(ptrToNode &node, ptrToItem &item);
static void CopyToNode(ptrToNode &node, ptrToItem &item);

static ptrToNode RightSingleRotate(ptrToNode &node);
static ptrToNode LeftSingleRotate(ptrToNode &node);
static ptrToNode Left_Right_Rotate(ptrToNode &node);
static ptrToNode Right_Left_Rotate(ptrToNode &node);
// static ptrToNode Left_Left_Rotate(ptrToNode &node);
// static ptrToNode Right_Right_Rotate(ptrToNode &node);

ptrToNode Insert(ptrToNode &root, ptrToItem &item) {
  if (root == nullptr) {
    ptrToNode newNode = new splayTreeNode;
    InitNode(root, item);
    return newNode;
  } else if (item->data > root->item->data || item->data == root->item->data) {
    root->right = Insert(root->right, item);
  } else if (item->data < root->item->data) {
    root->left = Insert(root->left, item);
  }
  return root;
}

ptrToNode FindMax(ptrToNode root) {
  if (root == nullptr) {
    throw "Empty tree";
  }
  while (root->right != nullptr) {
    root = root->right;
  }
  return root;
}

ptrToNode FindMin(ptrToNode root) {
  if (root == nullptr) {
    throw "Empty tree";
  }
  while (root->right != nullptr) {
    root = root->left;
  }
  return root;
}

ptrToNode Find(const ptrToItem &item, ptrToNode root) {
  if (root == nullptr) {
    throw "Empty tree";
  }
  while (root != nullptr) {
    if (item->data > root->item->data) {
      root = root->right;
    } else if (item->data < root->item->data) {
      root = root->left;
    } else {
      cout << "Find it" << endl;
      return root;
    }
  }
  cout << "Not find" << endl;
  return nullptr;
}

void MakeEmpty(ptrToNode &root) {
  if (root != nullptr) {
    MakeEmpty(root->left);
    MakeEmpty(root->right);
    delete root;
  }
}

ptrToNode Down_Top_Rotate(position n, splayTree &tr) {
  splayTreeNode l_tr, r_tr;
  position P, G;
  P = n->parent;
  while (P != nullptr) {
    G = P->parent;
    if (n == P->left) {
      if (G == nullptr)
        RightSingleRotate(P);
      else if (P == G->left) {
        RightSingleRotate(G);
        RightSingleRotate(P);
      } else {
        Right_Left_Rotate(G);
      }

    } else {
      if (G == nullptr) {
        LeftSingleRotate(P);
      } else if (G->right == P) {
        LeftSingleRotate(G);
        LeftSingleRotate(P);
      } else {
        Left_Right_Rotate(G);
      }
    }
    P = n->parent;
  }
  return n;
}

static void InitNode(ptrToNode &node, ptrToItem &item) {
  node->left = nullptr;
  node->right = nullptr;
  CopyToNode(node, item);
}

static void CopyToNode(ptrToNode &node, ptrToItem &item) { node->item = item; }

static ptrToNode RightSingleRotate(ptrToNode &node) {
  ptrToNode parent, k1;
  parent = node->parent;
  k1 = node->left;

  k1->parent = parent;

  if (k1->parent) {
    k1->right->parent = node;
  }
  node->left = k1->right;

  node->parent = k1;
  k1->right = node;

  if (parent) {
    if (parent->left == node) {
      parent->left = k1;
    } else {
      parent->right = k1;
    }
  }
  return k1;
}

static ptrToNode LeftSingleRotate(ptrToNode &node) {
  ptrToNode parent, k1;
  parent = node->parent;
  k1 = node->right;

  k1->parent = parent;

  if (k1->left) {
    k1->left->parent = k1;
  }
  k1->right = node->left;

  node->parent = k1;
  k1->left = node;
  if (parent) {
    if (parent->left == node) {
      parent->left = k1;
    } else {
      parent->right = k1;
    }
  }
  return k1;
}

static ptrToNode Left_Right_Rotate(ptrToNode &node) {
  node->left = LeftSingleRotate(node->left);
  return RightSingleRotate(node);
}

static ptrToNode Right_Left_Rotate(ptrToNode &node) {
  node->right = RightSingleRotate(node->right);
  return LeftSingleRotate(node);
}

// static ptrToNode Left_Left_Rotate(ptrToNode &node) {}