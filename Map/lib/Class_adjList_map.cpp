#include "Class_adjList_map.h"
#include <fstream>
#include <iostream>
using namespace std;
void Adjlist_map::Init() {
  map.vertex_num = map.arc_num = 0;
  for (int i = 0; i < MAX_V; i++) {
    map.adjList[i].data.num = 0;
    map.adjList[i].firstArc = map.adjList[i].lastArc = nullptr;
  }
}

void Adjlist_map::Read() {
  fstream in;
  in.open("D:/Algorithm_base/Map/Data/TopSort_data.txt", ios::in);
  //   编号
  string number;
  //   起点和待存储的边
  int start;
  ArcNode arc;
  Vertex v;
  if (in.fail()) {
    cout << "Fail to open the file" << endl;
  } else {
    in >> number;
    if (number == "vertices:") {
      while (!in.eof()) {
        in >> number;
        if (number == "edges:")
          break;
        v.num = stoi(number);
        map.adjList[map.vertex_num++].data = v;
      }
      while (!in.eof()) {
        in >> start;
        if (!in.eof()) {
          in >> arc.vertex;
        } else {
          break;
        }
        in >> arc.weight;
        AddNode(map.adjList[start], arc);
        map.arc_num++;
      }
    } else {
      cout << "Format Error." << endl;
    }
  }
  in.close();
}

void Adjlist_map::Display_edge() {
  Edge cur;
  for (int i = 0; i < map.vertex_num; i++) {
    cur = map.adjList[i].firstArc;
    while (cur != nullptr) {
      cout << "There is an edge between " << map.adjList[i].data.num << " and "
           << cur->vertex << ", the weight is " << cur->weight << endl;
      cur = cur->next;
    }
  }
  cout << "There are " << map.vertex_num << "  vertices and " << map.arc_num
       << " edges" << endl;
}

void Adjlist_map::AddNode(VNode &vNode, ArcNode &arc) {
  Edge newArc = new ArcNode;
  newArc->vertex = arc.vertex;
  newArc->weight = arc.weight;
  newArc->next = nullptr;

  if (vNode.firstArc == nullptr) {
    vNode.firstArc = vNode.lastArc = newArc;
  } else {
    vNode.lastArc->next = newArc;
    vNode.lastArc = newArc;
  }
}

void Adjlist_map::DisPose() {
  Edge cur;
  Edge tmp;
  for (int i = 0; i < map.vertex_num; i++) {
    cur = map.adjList[i].firstArc;
    while (cur != nullptr) {
      tmp = cur->next;
      delete cur;
      cur = tmp;
    }
  }
}

Adjlist_map::Adjlist_map() {
  Init();
  Read();
}

Adjlist_map::~Adjlist_map() { DisPose(); }