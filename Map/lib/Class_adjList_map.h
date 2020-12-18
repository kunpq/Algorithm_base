#define MAX_V 50
class Adjlist_map {
private:
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
  Graph map;

public:
  Adjlist_map();
  ~Adjlist_map();
  //初始化图
  void Init();
  // 添加边节点
  void AddNode(VNode &vNode, int vertex);
  //从文件读取信息并设置参数
  void Read();
  // 展现图
  void Display_edge();
  //销毁申请的内存
  void DisPose();
};
