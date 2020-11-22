#ifndef _BINARY_HEAP_
#define _BINARY_HEAP_
#include <iostream>
using namespace std;
struct Heap;
typedef struct Heap *PriorityQueue;
PriorityQueue Initialize(int maxmium);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(int x, PriorityQueue H);
int DeleteMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);

#endif