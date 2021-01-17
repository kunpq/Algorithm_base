#include "Class_adjList_map.h"
#include <iostream>
#include <queue>
using namespace std;
void TopSort(Graph &map, int top_arr[]) {
  queue<Vertex> Q;
  int counter = 0;
  int indegree_arr[map.vertex_num];
  Get_Indegree(map, indegree_arr);
  Vertex v, w;
  for (int i = 0; i < map.vertex_num; i++) {
    if (indegree_arr[i] == 0) {
      Q.push(map.adjList[i].data);
    }
  }
  while (!Q.empty()) {
    v = Q.front();
    Q.pop();
    top_arr[v.num] = ++counter;
    Edge cur = map.adjList[v.num].firstArc;
    while (cur != nullptr) {
      if (--indegree_arr[cur->vertex] == 0) {
        Q.push(map.adjList[cur->vertex].data);
      }
      cur = cur->next;
    }
  }
  if (counter != map.vertex_num) {
    cout << "Error,Graph has a circle" << endl;
  }
}

void Get_Indegree(Graph &map, int arr[]) {
  for (int i = 0; i < map.vertex_num; i++) {
    arr[i] = 0;
  }

  Edge cur;
  for (int i = 0; i < map.vertex_num; i++) {
    cur = map.adjList[i].firstArc;
    while (cur != nullptr) {
      arr[cur->vertex]++;
      cur = cur->next;
    }
  }
}

void DisplaySort(int top_arr[], int n) {
  cout << "The topsort is as follows:" << endl;
  for (int i = 0; i < n; i++) {
    cout << top_arr[i] << " ";
  }
  cout << endl;
}
