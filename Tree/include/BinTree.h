#include <iostream>
using namespace std;

typedef struct TreeNode *BinTree;
typedef BinTree Position;

struct TreeNode
{
    int data;
    BinTree left;
    BinTree right;
};

// 先续遍历
void PreOrderTraversal(BinTree BT)
{
    if (BT)
    {
        cout << BT->data << endl;
    }
    PreOrderTraversal(BT->left);
    PreOrderTraversal(BT->right);
}

// 中续遍历
void InOrderTraversal(BinTree BT)
{
    if (BT)
    {
        InOrderTraversal(BT->left);
        cout << BT->data << endl;
        InOrderTraversal(BT->right);
    }
}

// 后续遍历
void PostOrderTraversal(BinTree BT)
{
    if (BT)
    {
        PostOrderTraversal(BT->left);
        PostOrderTraversal(BT->right);
        cout << BT->data << endl;
    }
}

// 中续非递归遍历(堆栈)
void InOrderTraversal_(BinTree BT)
{
    /*
    BinTree T = BT;
    Stack S = CreateStack(MaxSize);
    while (T || !IsEmpty(S))
    {
            while (T) {
                Push(S, T)
                    T = T->left;
            }
            if (!IsEmpty(S)) {
                T = Pop(S);
                Operations_Function;
                T = T->right;
            }
    }
    */
}

// 前续非递归遍历(堆栈)
void PreOrderTraversal_(BinTree BT)
{
    /*
    BinTree T = BT;
    Stack S = CreateStack(MaxSize);
    while (T || !IsEmpty(S))
    {
            while (T) {
                Push(S, T)
                    T = T->left;
            }
            if (!IsEmpty(S)) {
                T = Pop(S);
                Operations_Function;
                T = T->right;
            }
    }
    */
}

// 后续非递归遍历
void PostOrderTraversal_(BinTree BT)
{
    bool check = true;
    /*
    BinTree T = BT;
    Stack S = CreateStack(MaxSize);
    while (T || !IsEmpty(S))
    {
            while (T) {
                Push(S, T)
                T->First=true;
                    T = T->left;
            }
            if (!IsEmpty(S)) {
                T = Pop(S);
                if(T->first)
                    T->First=false;
                    Push(S,T);
                    T = T->right;
                else{
                    Operations_Function;
                    T=NULL;
            }
            }
            
    }
    */
}

