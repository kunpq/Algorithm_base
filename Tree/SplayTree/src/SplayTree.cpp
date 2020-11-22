#include "../include/SplayTree.h"


static void InitNode(ptrToNode &node, ptrToItem &item);
static void CopyToNode(ptrToNode& node,ptrToItem& item);
ptrToNode Insert(ptrToNode&root,ptrToItem& item) {
  if (root==nullptr) {
    ptrToNode newNode = new splayTreeNode;
    InitNode(root, item);
    return newNode;
  }
  else if (item->data>root->item->data || item->data==root->item->data) {
    root->right=Insert(root->right, item);
  }
  else if(item->data<root->item->data){
    root->left=Insert(root->left, item);
  }
  return root;
}

ptrToNode FindMax(ptrToNode root) {
  if (root == nullptr) {
    throw "Empty tree";
  }
  while (root->right!=nullptr) {
  root=root->right;
  }
  return root;
}

ptrToNode FindMin(ptrToNode root) {
  if (root==nullptr) {
  throw "Empty tree";
  }
  while (root->right!=nullptr) {
  root=root->left;
  }
  return root;
}

ptrToNode Find(const ptrToItem &item, ptrToNode root) {
  if (root==nullptr) {
  throw "Empty tree";
  }
  while (root!=nullptr) {
  if (item->data>root->item->data) {
    root=root->right;
  } else if (item->data<root->item->data) {
    root = root->left;
  }
  else {
    cout << "Find it" << endl;
    return root;
  }
  }
  cout << "Not find" << endl;
  return nullptr;
}

void MakeEmpty(ptrToNode &root) {
  if (root!=nullptr) {
    MakeEmpty(root->left);
    MakeEmpty(root->right);
    delete root;
  }
}



static void InitNode(ptrToNode &node,ptrToItem& item){
  node->left = nullptr;
  node->right = nullptr;
  CopyToNode(node, item);
}

static void CopyToNode(ptrToNode &node, ptrToItem &item){
  node->item=item;
}