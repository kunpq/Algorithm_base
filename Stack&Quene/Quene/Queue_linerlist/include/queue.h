#ifndef _QUEUE_H_
/*
  队列线性表实现ADT
*/
#include <iostream>
using namespace std;
//定义存储节点
typedef struct item {
  int data;
  string name = " ";
} Item;
//定义队列
typedef struct queue {
  Item *arr;   //存储节点地址
  int front;   //队首
  int rear;    //队尾
  int maxSize; //最大容纳量
  int size;    //当前节点数
} Queue;

Queue *InitQueue(int &maxsize);      //初始化队列
void EnQueue(Item &item, Queue *pq); //进队列
void DeQueue(Queue *pq); //出队列
void DiseposeQueue(Queue *pq);       //销毁队列
void MakeEmpty(Queue *pq);           //清空队列

//本地函数
bool QueueIsEmpty(const Queue *pq);  //判断队列是否为空
bool QueueIsFull(const Queue *pq);   //判断队列是否已满
#endif