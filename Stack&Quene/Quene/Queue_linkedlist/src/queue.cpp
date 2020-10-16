/*队列实现ADT*/
#include "../include/queue.h"
#include <cstdio>
#include <cstdlib>

/* 本地函数 */
static void CopyToNode(Item item, Node *pn);
static void CopyToItem(Node *pn, Item *pi);

//初始化
void InitializeQueue(int max, Queue *pq) {
  pq = (Queue *)malloc(sizeof(Queue));
  pq->front = pq->rear = NULL; //初始化时队首队尾置为NULL
  pq->items = 0;               //初始化项数为0
  pq->maxSize = max;
}

// 进队列
void EnQueue(Item item, Queue *pq) {
  if (AddNode(pq))
    CopyToNode(item, pq->rear);
}

//出队列
void DeQueue(Item *pitem, Queue *pq) {
  MinusNode(pitem, pq); //减少节点同时存储数据
}

// 清空队列
void EmptyTheQueue(Queue *pq) {
  Item dummy;
  while (!QueueIsEmpty(pq))
    DeQueue(&dummy, pq);
}

//添加节点
bool AddNode(Queue *pq) {
  Node *pnew;

  if (QueueIsFull(pq)) {
    printf("%s", "Queue is full");
    return false;
  }
  pnew = (Node *)malloc(sizeof(Node));
  if (pnew == NULL) {
    fprintf(stderr, "Unable to allocate memory!\n"); //检查内存分配
    exit(1);
  }
  pnew->next = NULL;
  if (QueueIsEmpty(pq))
    pq->front = pnew; //第一个节点置为队首
  else
    pq->rear->next = pnew; //衔接操作
  pq->rear = pnew;         //记录队尾
  pq->items++;             //项数加一
  return true;
}

// 减少节点
bool MinusNode(Item *pitem, Queue *pq) {
  Node *pt;             //暂时存储节点
  if (QueueIsEmpty(pq)) //清空前判断队列是否为空
  {
    printf("%s", "The Queue is Empty!");
    return false;
  }
  CopyToItem(pq->front, pitem); //存储将删除的节点数据
  pt = pq->front;
  pq->front = pq->front->next;
  free(pt);
  pq->items--;
  if (pq->items == 0) //若节点为0，则重置尾节点
    pq->rear = NULL;
  return true;
}

void GetInfo(Item *pt) {
  printf("%s", "Enter the number please.\n");
  scanf("%d", &pt->data);
  printf("%s", "Enter the name please.\n");
  scanf("%s", pt->name);
}

void DisposeQueue(Queue *pq) {
  EmptyTheQueue(pq);
  free(pq);
}

bool QueueIsFull(const Queue *pq) { return pq->items == pq->maxSize; }
bool QueueIsEmpty(const Queue *pq) { return pq->items == 0; }

//本地函数
static void CopyToNode(Item item, Node *pn) { pn->item = item; }
static void CopyToItem(Node *pn, Item *pi) { *pi = pn->item; }
