#include "../include/BinaryHeap.h"
#define MIN -1
struct Heap {
  int capacity;
  int size;
  int* arr;
};

PriorityQueue Initialize(int maxmium) {
  PriorityQueue Queue = new Heap;
  Queue->arr =(int*) malloc(sizeof(int) * maxmium);
  Queue->capacity = maxmium;
  Queue->size = 0;
  Queue->arr[0]=MIN;
  return Queue;
}

void Destroy(PriorityQueue H) {
  free(H->arr);
  free(H);
}

void MakeEmpty(PriorityQueue H) { H->size = 0; }

void Insert(int x, PriorityQueue H) {
  if (IsFull(H)) {
    cout << "The heap is full" << endl;
    return;
  }
  int i, j;
  for ( i=++H->size,j=i/2; x<H->arr[j];i/=2) {
     H->arr[i] = H->arr[j];
  } 
  H->arr[i] = x;
}

int DeleteMin(PriorityQueue H) {
  if (IsEmpty(H)) {
    throw "The heap is empty";
  }

  int i, child;
  int min, last;
  min = H->arr[1];
  last = H->arr[H->size--];
  for (i=1; i*2<=H->size; i=child) {
    child = i * 2;
    if (child != H->size && H->arr[child] > H->arr[child + 1]) {
      child++;
    }
    if (last>=H->arr[child]) {
      H->arr[i]=H->arr[child];
    }else {
      break;
    }
  }
  H->arr[i] = last;
  return min;
}

int IsFull(PriorityQueue H) {
  return H->size==H->capacity;
}

int IsEmpty(PriorityQueue H) {
  return H->size==0;
}