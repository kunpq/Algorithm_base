#include "../include/searchTree.h"

static ptrNode MakeNode(int &data)
{
    ptrNode newNode = new treeNode;
    newNode->left = newNode->right = nullptr;
    newNode->data = data;
    return newNode;
}

searchTree MakeEmpty(searchTree T)
{
    if (T != nullptr)
    {
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
    }
    return nullptr;
}

position Find(int x, searchTree T)
{
    if (T == nullptr)
    {
        return nullptr;
    }
    if (x < T->data)
    {
        return Find(x, T);
    }
    else if (x > T->data)
    {
        return Find(x, T);
    }
    return T;
}

position FindMin(searchTree T)
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
    {
        return FindMin(T->left);
    }
}

position FindMax(searchTree T)
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
    {
        return FindMax(T);
    }
}

searchTree Insert(int x, searchTree T)
{
    if (T == nullptr)
    {
        ptrNode newNode = MakeNode(x);
        return newNode;
    }
    else if (x <)
    {
    }
}