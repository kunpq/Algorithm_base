#include <fstream>
#include <iostream>
using namespace std;

#define MAX_V 50
// 点的结构，含标号
typedef struct {
  int num;
  // InfoType info 顶点其他信息
} Vertex;

// 边的结构
typedef struct ArcNode {
  int vertex; //弧的终点
  ArcNode *next;
  // InfoType info    弧的相关信息
} * Edge;
// 邻接表头节点类型
typedef struct vNode {
  Vertex data;
  Edge firstArc;
  Edge lastArc;
} VNode;
// 定义图结构
typedef struct {
  VNode adjList[MAX_V];
  int vertex_num, arc_num;
} Graph;
//初始化图
void Init(Graph &map);
void AddNode(VNode &vNode, int vertex);
//从文件读取信息并设置参数
void Read(Graph &map);
// 展现图
void Display_edge(Graph &map);
//销毁申请的内存
void DisPose(Graph &map);
int main(void) {
  Graph map;
  Init(map);
  Read(map);
  Display_edge(map);
  DisPose(map);
  return 0;
}

void Init(Graph &map) {
  map.vertex_num = map.arc_num = 0;
  for (int i = 0; i < MAX_V; i++) {
    map.adjList[i].data.num = 0;
    map.adjList[i].firstArc = map.adjList[i].lastArc = nullptr;
  }
}

void Read(Graph &map) {
  fstream in;
  in.open("data.txt", ios::in);
  //   编号
  string number;
  //   起点，终点
  int v1, v2;

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
        in >> v1;
        if (!in.eof()) {
          in >> v2;
        } else {
          break;
        }
        AddNode(map.adjList[v1 - 1], v2);
        map.arc_num++;
      }
    } else {
      cout << "Format Error." << endl;
    }
  }
  in.close();
}

void Display_edge(Graph &map) {
  Edge cur;
  for (int i = 0; i < map.vertex_num; i++) {
    cur = map.adjList[i].firstArc;
    while (cur != nullptr) {
      cout << "There is an edge between " <<map.adjList[i].data.num << " and " << cur->vertex
           << endl;
      cur = cur->next;
    }
  }
  cout << "There are " << map.vertex_num << "  vertices and " << map.arc_num
       << " edges" << endl;
}

void AddNode(VNode &vNode, int vertex) {
  Edge newArc = new ArcNode;
  newArc->vertex = vertex;
  newArc->next = nullptr;

  if (vNode.firstArc == nullptr) {
    vNode.firstArc = vNode.lastArc = newArc;
  } else {
    vNode.lastArc->next = newArc;
    vNode.lastArc = newArc;
  }
}

void DisPose(Graph &map) {
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