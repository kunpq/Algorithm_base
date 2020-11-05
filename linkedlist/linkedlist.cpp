#include <iostream>
using namespace std;

// 定义节点
typedef struct node
{
    int a;
    struct node *next;
} Node, *PtrToNode;

// 定义链表
typedef struct list
{
    PtrToNode head;
    PtrToNode end;
    int items;
} List, *linkedList;
linkedList CreateList(linkedList &l); //创建链表
void AddNode(linkedList &l);          //添加节点
void GetInfo(linkedList &l);          //得到信息
void Add(linkedList &l);              //添加数据
bool IsEmpty(linkedList &l);          //判断链表是否为空
void Delete(linkedList &l);           //删除节点
void Search(linkedList &l);           //查找数据
void MakeEmpty(linkedList &l);        //清空链表
void Dispose(linkedList &l);          //销毁链表

int main(void)
{
    linkedList l = CreateList(l);
    for (int i = 0; i < 10; i++)
    {
        Add(l);
    }
    Delete(l);
    Search(l);
    Dispose(l);
    return 0;
}

linkedList CreateList(linkedList &l)
{
    l = (linkedList)malloc(sizeof(List));
    if (l == NULL)
    {
        cout << "Out of space!" << endl;
        exit(0);
    }

    l->head = l->end = NULL;
    l->items = 0;
    return l;
}

void AddNode(linkedList &l)
{
    PtrToNode newNode = (PtrToNode)malloc(sizeof(Node));
    newNode->next = NULL;
    if (l->items == 0)
        l->head = l->end = newNode;
    else
    {
        l->end->next = newNode;
        l->end = newNode;
    }
    l->items++;
}

void Add(linkedList &l)
{
    AddNode(l);
    GetInfo(l);
}

void GetInfo(linkedList &l)
{
    int data;
    cout << "Enter the data:" << endl;
    cin >> data;
    l->end->a = data;
}

bool IsEmpty(linkedList &l)
{
    return l->items == 0;
}

void Delete(linkedList &l)
{
    // 查找操作
    int data;
    cout << "Enter the data to delete." << endl;
    cin >> data;
    PtrToNode currentNode = l->head;
    PtrToNode preNode = NULL;
    while (currentNode)
    {
        if (currentNode->a == data)
            break;
        preNode = currentNode;
        currentNode = currentNode->next;
    }

    // 删除操作
    if (currentNode == l->head)
    {
        l->head = currentNode->next;
        free(currentNode);
    }
    else if (currentNode == l->end)
    {
        preNode->next = NULL;
        l->end = preNode;
    }

    else if (currentNode == NULL)
    {
        cout << "Not find,Can't delete." << endl;
        return;
    }
    else
    {
        preNode->next = currentNode->next;
        free(currentNode);
    }
    cout << "Done" << endl;
}

void Search(linkedList &l)
{
    int data;
    cout << "Enter the data to search." << endl;
    cin >> data;
    PtrToNode currentNode = l->head;
    while (currentNode)
    {
        if (currentNode->a == data)
        {
            cout << "Find it." << endl;
            return;
        }
        currentNode = currentNode->next;
    }
    cout << "Not find it." << endl;
}

void MakeEmpty(linkedList &l)
{
    PtrToNode currentNode = l->head;
    PtrToNode tmp;
    while (currentNode)
    {
        tmp = currentNode;
        currentNode = currentNode->next;
        free(tmp);
    }
}

void Dispose(linkedList &l)
{
    MakeEmpty(l);
    free(l);
}