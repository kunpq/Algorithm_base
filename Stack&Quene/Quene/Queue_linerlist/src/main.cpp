#include "../include/queue.h"
#include <iostream>
//测试ADT
int main(void) {
  int a = 100; //设定容量为100
  Item arr[a]; //存储结构
  Queue *q = InitQueue(a);
  for (int i = 0; i < a; i++) {
    arr[i].data = i;
    EnQueue(arr[i], q);
  }
  cout << q->size << endl;
  for (int i = 0; i < a; i++) {
    cout << q->arr[i].data << endl;
  }
  for (int i = 0; i < a; i++) {
    DeQueue(q);
  }
  DeQueue(q);
  MakeEmpty(q); //清空列表
  EnQueue(arr[0], q);
  cout << "\n" << q->size << endl;
  DiseposeQueue(q);
  return 0;
}