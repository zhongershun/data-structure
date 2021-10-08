#include<iostream>
using namespace std;
#define Infinity 65535
#define ERROR -1
#define MaxSize 100

int Visited[100]={0};

typedef struct GNode
{
	int Nv;
	int Ne;
	int G[100][100];
	int Data[100];
} MGraph;

typedef struct ENode
{
	int V1,V2;
	int Weight;
} Edge;

typedef struct QNode
{
	int* data;
	int front,rear;
	int Maxsize;
} Queue;

Queue* CreateQueue(int Maxsize)
{
	Queue* Q=new Queue;
	Q->data=new int;
	Q->front=Q->rear=0;
	Q->Maxsize=Maxsize;
	return Q; 
}

bool IsFull(Queue* Q)
{
	return ((Q->rear+1)%Q->Maxsize==Q->front);
}

bool AddQ(Queue* Q,int X)
{
	if (IsFull(Q))
	{
		return false; 
	}
	else
	{
		Q->rear=(Q->rear+1)%Q->Maxsize;
		Q->data[Q->rear]=X;
		return true;
	}
}

bool IsEmpty(Queue* Q)
{
	return (Q->front==Q->rear);
}

int DeleteQ(Queue* Q)
{
	if (IsEmpty(Q))
	{
		return ERROR;
	}
	else
	{
		Q->front=(Q->front+1)%Q->Maxsize;
		return Q->data[Q->front];
	}
}

MGraph* CreateGraph(int VertexNum)
{
	int V,W;
	MGraph* Graph;
	
	Graph=new MGraph;
	Graph->Nv=VertexNum;
	Graph->Ne=0;
	
	for (V=0;V<Graph->Nv;V++)
	{
		for (W=0;W<Graph->Nv;W++)
		{
			Graph->G[V][W]=Infinity;
		}
	}
	
	return Graph;
}

void InsertEdge(MGraph* Graph,Edge* E)
{
	Graph->G[E->V1-Graph->Data[0]][E->V2-Graph->Data[0]]=E->Weight;
	Graph->G[E->V2-Graph->Data[0]][E->V1-Graph->Data[0]]=E->Weight; 
}

MGraph* BuildGraph(MGraph* Graph)
{
	Edge* E;
	int V;
	int Nv,Ne,i;
	
	cin>>Nv>>Ne;
	Graph=CreateGraph(Nv);
	Graph->Ne=Ne;
	
	for (V=0;V<Nv;V++)
	{
		cin>>Graph->Data[V];
	}
	
	if (Graph->Ne!=0)
	{
		E=new Edge;
		for (i=0;i<Graph->Ne;i++)
		{
			cin>>E->V1>>E->V2>>E->Weight;
			InsertEdge(Graph,E);
		}
	}
	
	return Graph;
}

bool IsEdge(MGraph* Graph,int V,int W)
{
	return Graph->G[V][W]<Infinity?true:false;
}

void Visit(int V)
{
	cout<<V<<" ";
}

void BFS(MGraph* Graph,int S)
{
	Queue* Q;
	int V,W;
	
	Q=CreateQueue(MaxSize);
	Visit(S);
	Visited[S]=1;
	AddQ(Q,S);
	
	while(!IsEmpty(Q))
	{
		V=DeleteQ(Q);
		for (W=0;W<Graph->Nv;W++)
		{
			if (Visited[W]==0&&IsEdge(Graph,V,W))
			{
				Visit(W);
				Visited[W]=1;
				AddQ(Q,W);
			}
		}
	}
}

int main()
{
	MGraph* Graph;
	int S=0;
	
	Graph=BuildGraph(Graph);
	BFS(Graph,S);
}
