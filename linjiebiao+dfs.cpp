#include<iostream>
using namespace std;

// 记录某一点是否遍历过
int Visited[100]={0};

typedef struct ENode
{
	int V1,V2;
	int Weight;
} Edge;

//邻接点的定义 
typedef struct AdjVNode
{
	int AdjV; //邻接点下标 
	int Weight;
	struct AdjVNode* Next;
} PtrAdjV;

//顶点表头结点的定义 
typedef struct VNode
{
	PtrAdjV* FirstEdge; //边表头指针 
	int Data; //存顶点数据 
} AdjList[100]; //AdjList是邻接表类型 

//图结点的定义 
typedef struct GNode
{
	int Nv;
	int Ne;
	AdjList G; //邻接表 
} LGraph;

LGraph* CreateGraph(int VertexNum)
{
	int V;
	LGraph* Graph;
	
	Graph=new LGraph;
	Graph->Nv=VertexNum;
	Graph->Ne=0;
	
	for (V=0;V<Graph->Nv;V++)
	{
		// 把对应顶点的邻接位置先清零
		Graph->G[V].FirstEdge=NULL;
	}
	
	return Graph;
}

void InsertEdge(LGraph* Graph,Edge* E)
{
	PtrAdjV* NewNode;

	// 给v1创建邻接表
	NewNode=new PtrAdjV;
	NewNode->AdjV=E->V2;
	NewNode->Weight=E->Weight;
	// 新来的点加在前面
	NewNode->Next=Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge=NewNode;
	//G[E->V1].FirstEdge->next=NewNode;


	NewNode=new PtrAdjV;
	NewNode->AdjV=E->V1;
	NewNode->Weight=E->Weight;
	NewNode->Next=Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge=NewNode;
	//G[E->V2].FirstEdge->next=NewNode;
}

LGraph* BuildGraph(LGraph* Graph)
{
	Edge* E;
	int V;
	int Nv,Ne,i;
	
	// 定义要输入的顶点和边的数量
	cin>>Nv>>Ne;
	Graph=CreateGraph(Nv);
	Graph->Ne=Ne;
	
	for (V=0;V<Graph->Nv;V++)
	{
		// 输入每个点的值
		cin>>Graph->G[V].Data;
	}
	
	// 边的数量不为零就开始创造边
	if (Graph->Ne!=0)
	{
		E=new Edge;// 先检查有没有边再看要不要给边分配内存
		for (i=0;i<Graph->Ne;i++)
		{
			// 输入边断点的值以及边的权重
			cin>>E->V1>>E->V2>>E->Weight;
			InsertEdge(Graph,E); 
		}
	}
	
	return Graph;
}

void Visit(int V)
{
	cout<<V<<" ";
}

//void DFS(LGraph* Graph,int V,void(* Visit)(int))
void DFS(LGraph* Graph,int V)
{
	PtrAdjV* W;
	
	Visit(V);
	Visited[V]=1;
	
	for (W=Graph->G[V].FirstEdge;W;W=W->Next)
	{
		if (Visited[W->AdjV]==0)
		{
//			DFS(Graph,W->AdjV,Visit);
			DFS(Graph,W->AdjV);
		}
	}
}

int main()
{
	LGraph* Graph;
	int V=1;
	
	Graph=BuildGraph(Graph);
	DFS(Graph,V);
	
	return 0;
}
