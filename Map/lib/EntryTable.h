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
void InitTable(vertex start, Graph &map, Table &T);
// 得到表中dist最小的未知顶点
vertex SmallestDist_Vertex(Table &T);
// 初始化表的子函数，将图的邻接表链接到表中
void ReadGraph(Table &T, Graph &map);
// 狄克斯特拉相关函数
void PrintPath(vertex v, Table &T);
int GetCost(vertex v, Table &T);
void Dijkstra(Table &T);
// 普利姆算法相关函数
void Prime(Table &T);
void Display(Table &T);
#endif
