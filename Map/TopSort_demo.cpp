#include "./lib/Class_adjList_map.h"
#include "iostream"
#include <queue>
using namespace std;
int main() {
  Adjlist_map map;
  Graph Map = map.map;
  int top_arr[Map.vertex_num];
  Get_Indegree(Map, top_arr);
  TopSort(Map, top_arr);
  DisplaySort(top_arr, Map.vertex_num);
  return 0;
}
