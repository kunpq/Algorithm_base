#ifndef _DIJKSTRA_
#define _DIJKSTRA_
#define NullVertex -1
#define Infinity -1
typedef int vertex;
#include "Class_adjList_map.h"
typedef struct TableEntryUnit {
  VNode head;
  vertex path;
  bool known;
  int dist;
} * unitTable;
typedef struct table {
  int vertex_num;
  unitTable *allTable;
} Table;
void PrintPath(vertex v, Table &T);
void Dijkstra(Table &T);
void InitTable(vertex start, Graph &map, Table &T);
#endif
