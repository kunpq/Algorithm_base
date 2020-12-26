#include "./lib/EntryTable.h"
#include <iostream>
using namespace std;
int main(void) {
  Adjlist_map map;
  map.Display_edge();
  Table T;
  InitTable(3, map.map, T);
  for (int i = 0; i < T.vertex_num; i++) {
    cout << T.allTable[i]->dist << endl;
  }
  Dijkstra(T);
  PrintPath(5, T);
  return 0;
}