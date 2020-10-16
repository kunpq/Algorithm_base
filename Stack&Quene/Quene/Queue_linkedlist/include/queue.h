/*队列链表实现ADT*/
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <stdbool.h>

//数据域
typedef struct item {
  int data;
  char name[50];
} Item;

//节点
typedef struct node {
  Item item;
  struct node *next;
} Node;

// 队列
typedef struct queue {
  Node *front; //队首
  Node *rear;  //队尾
  int items;   //项数
  int maxSize; //最大值
} Queue;

void InitializeQueue(int max, Queue *pq); //初始化队列
bool QueueIsFull(const Queue *pq);        //判断队列是否已满
bool QueueIsEmpty(const Queue *pq);       //判断队列是否为空
void EnQueue(Item item, Queue *pq);       //进入队列
bool AddNode(Queue *pq);                  //节点加一
bool MinusNode(Item *pitem, Queue *pq);   //节点减一
void DeQueue(Item *pitem, Queue *pq);     //离开队列
void EmptyQueue(Queue *pq);               //清空队列
void DisposeQueue(Queue *pq);             //销毁队列
void GetInfo(Item *pt);                   //获取信息
#endif