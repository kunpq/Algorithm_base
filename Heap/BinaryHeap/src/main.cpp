#include "../include/BinaryHeap.h"


int main(void) {
  PriorityQueue q = Initialize(200);
  for (int i=0; i<200; i++) {
  Insert(i, q);
  }
  DeleteMin(q);
  cout<<q->size<<endl;
  return 0;
}