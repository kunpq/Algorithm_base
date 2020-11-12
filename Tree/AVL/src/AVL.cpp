#include "../include/AVL.h"

static int Height(position P)
{
    if (P == nullptr)
    {
        return -1;
    }
    else
    {
        return P->height;
    }
}
static int Max(int left, int right)
{
    if (left > right)
    {
        return left;
    }
    else
    {
        return right;
    }
}

static position SingleRotateWithLeft(position k2)
{
    position k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = Max(Height(k2->left), Height(k2->right)) + 1;
    k1->height = Max(Height(k1->left), Height(k1->right)) + 1;
    return k1;
}
static position SingleRotateWithRight(position k1)
{
    position k2;
    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k1->height = Max(Height(k1->left), Height(k1->right)) + 1;
    k2->height = Max(Height(k2->left), Height(k2->right)) + 1;
    return k2;
}
static position DoubleRotateWithLeft(position k3)
{
    k3->left = SingleRotateWithRight(k3->left);
    return SingleRotateWithLeft(k3);
}
static position DoubleRotateWithRight(position k1)
{
    k1->right = SingleRotateWithLeft(k1->right);
    return SingleRotateWithRight(k1);
}
avlTree Insert(int x, avlTree T)
{
    if (T == nullptr)
    {
        T = new avlNode;
        T->height = 0;
        T->left = T->right = nullptr;
        T->data = x;
    }
    else if (x < T->data)
    {
        T->left = Insert(x, T->left);
        if (Height(T->left) - Height(T->right) == 2)
        {
            if (x < T->left->data)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
        }
    }
    else if (x > T->data)
    {
        T->right = Insert(x, T->right);
        if (Height(T->right) - Height(T->left) == 2)
        {
            if (x > T->right->data)
            {
                T = SingleRotateWithLeft(T);
            }
            else
            {
                T = DoubleRotateWithLeft(T);
            }
        }
    }
    T->height = Max(Height(T->left), Height(T->right)) + 1;
    return T;
}
avlTree MakeEMpty(avlTree T)
{
}
position FindMin(avlTree T)
{
    if (T == nullptr)
    {
        return nullptr;
    }
    else if (T->left == nullptr)
    {
        return T;
    }
    else
        return FindMin(T->left);
}

position FindMax(avlTree T)
{
    if (T == nullptr)
    {
        return nullptr;
    }
    else if (T->right == nullptr)
    {
        return T;
    }
    else
        return FindMax(T->right);
}

avlTree Delete(int x, avlTree T){
    
}