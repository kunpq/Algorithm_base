#include "../include/queue.h"
#include <cstdlib>

Queue *InitQueue(int &maxsize) {
  Queue *pq = (Queue *)malloc(sizeof(Queue));
  pq->front = pq->rear = -1; //初始化队首与队尾,在没有存储数据时置为-1
  pq->maxSize = maxsize;
  pq->size = 0;
  pq->arr =
      (Item *)malloc(sizeof(Item) * maxsize); //一次性将所有所需存储空间进行分配
  return pq;
}

void EnQueue(Item &item, Queue *pq) {
  //判断队列是否已满
  if (QueueIsFull(pq)) {
    fprintf(stdout, "The Queue is full!");
    return;
  }
  if (pq->size == 0) {
    pq->rear = pq->front = 0; //节点数为零则重置首尾位置到0
  } else {
    pq->rear = (pq->rear + 1) % (pq->maxSize);
  }
  pq->arr[pq->rear] = item;
  pq->size++;
}

void DeQueue(Queue *pq) {
  //判断队列是否为空
  if (QueueIsEmpty(pq)) {
    fprintf(stdout, "Empty Queue");
    return;
  }
  pq->front = (pq->front + 1) % (pq->maxSize);
  pq->size--;
}

bool QueueIsEmpty(const Queue *pq) { return pq->size == 0; }
bool QueueIsFull(const Queue *pq) {
  return (pq->rear + 1) % (pq->maxSize) ==
         pq->front; //若队尾的下一个节点为队首则说明已满
}

void DiseposeQueue(Queue *pq) {
  free(pq->arr);
  free(pq);
}

void MakeEmpty(Queue *pq) {
  pq->front = pq->rear = -1;
  pq->size = 0;
}