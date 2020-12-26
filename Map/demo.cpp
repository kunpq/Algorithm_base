#include "./lib/EntryTable.h"
#include <iostream>
#include <vector>
using namespace std;
void Problem1(Table &T, Adjlist_map &map);
void Problem2(Table &T, Adjlist_map &map);
int main(void) {
  Adjlist_map map;
  vector<int> arr;
  Table T;
  Problem1(T, map);
  Problem2(T, map);
  return 0;
}
void Problem1(Table &T, Adjlist_map &map) {
  int max;
  int min;
  int village;
  bool IsFirst = true;
  //大循环，每次循环更新当前min的值与village
  for (int i = 0; i < map.map.vertex_num; i++) {
    max = 0;
    InitTable(i, map.map, T);
    Dijkstra(T);
    // 小循环，每次循环找到相距距离最大的村庄
    for (int j = 0; j < map.map.vertex_num; j++) {
      // 跳过当前村庄,只比较其他村庄
      if (j == i) {
        continue;
      }
      if (max < GetCost(j, T)) {
        max = GetCost(j, T);
      }
    }
    if (IsFirst || max < min) {
      min = max;
      village = i;
      IsFirst = false;
    }
  }
  cout << "The hospital should be built on the vertex " << village << endl;
}
void Problem2(Table &T, Adjlist_map &map) {
  int sum = 0;
  int min;
  int village;
  bool IsFirst = true;
  for (int i = 0; i < map.map.vertex_num; i++) {
    sum = 0;
    InitTable(i, map.map, T);
    Dijkstra(T);
    // 小循环，每次循环找到相距距离最大的村庄
    for (int j = 0; j < map.map.vertex_num; j++) {
      // 跳过当前村庄,只比较其他村庄
      if (j == i) {
        continue;
      }
      sum += GetCost(j, T);
    }
    if (IsFirst || sum < min) {
      min = sum;
      village = i;
      IsFirst = false;
    }
  }
  cout << "The hospital should be built on the vertex " << village << endl;
}
