#ifndef _CLASS_ADJLIST_MAP_
#define _CLASS_ADJLIST_MAP_
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
  int weight;
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
class Adjlist_map {
public:
  Graph map;
  Adjlist_map();
  ~Adjlist_map();
  //初始化图
  void Init();
  // 添加边节点
  void AddNode(VNode &vNode, ArcNode &arc);
  //从文件读取信息并设置参数
  void Read();
  // 展现图
  void Display_edge();
  //销毁申请的内存
  void DisPose();
};

void Get_Indegree(Graph &map, int arr[]);
void TopSort(Graph &map, int top_arr[]);
void DisplaySort(int top_arr[], int n);
#endif