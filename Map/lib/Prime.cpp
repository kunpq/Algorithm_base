#include "EntryTable.h"
#include <iostream>
void Prime(Table &T) {
  vertex v, w;
  while (1) {
    v = SmallestDist_Vertex(T);
    if (v == NullVertex) {
      break;
    }
    T.allTable[v]->known = true;
    Edge cur = T.allTable[v]->head.firstArc;
    while (cur != nullptr) {
      w = cur->vertex;
      if (!T.allTable[w]->known) {
        if (T.allTable[w]->dist == Infinity ||
            T.allTable[w]->dist > cur->weight) {
          T.allTable[w]->dist = cur->weight;
          T.allTable[w]->path = v;
        }
      }
      cur = cur->next;
    }
  }
}

void Display(Table &T) {
  for (int i = 0; i < T.vertex_num; i++) {
    std::cout << "(" << T.allTable[i]->head.data.num << " , "
              << T.allTable[i]->path << ")" << std::endl;
  }
}