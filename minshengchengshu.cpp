#include<iostream>
using namespace std;
#define Infinity 65535
#define ERROR -1

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

int FindMin(MGraph* Graph,int dist[])
{
	int MinV,V;
	int MinDist=Infinity;
	
	for (V=0;V<Graph->Nv;V++)
	{
		if (dist[V]!=0&&dist[V]<MinDist)
		{
			MinDist=dist[V];
			MinV=V;
		}
	}
	
	if (MinDist<Infinity)
	{
		return MinV;
	}
	else
	{
		return ERROR;
	}
}

void Sort(int a[],int b[],int c[],int k,MGraph* Graph)
{
	int i,j,t;
	for (i=1;i<k;i++)
	{
		for (j=0;j<k-i;j++)
		{
			if (a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				t=b[j];
				b[j]=b[j+1];
				b[j+1]=t;
				t=c[j];
				c[j]=c[j+1];
				c[j+1]=t;
			}
		}
	}
	
	for (i=0;i<k;i++)
	{
		if (b[i]<=c[i])
		{
			cout<<b[i]+Graph->Data[0]<<" "<<c[i]+Graph->Data[0]<<" "<<a[i]<<endl;
		}
		else
		{
			cout<<c[i]+Graph->Data[0]<<" "<<b[i]+Graph->Data[0]<<" "<<a[i]<<endl;
		}
	}
}

int Prim(MGraph* Graph,MGraph* MST)
{
	int k=0;
	int a[100],b[100],c[100];
	int dist[100],TotalWeight;
	int parent[100],V,W;
	int VCount;
	Edge* E;
	
	for (V=0;V<Graph->Nv;V++)
	{
		dist[V]=Graph->G[0][V];
		parent[V]=0;
	}
	TotalWeight=0;
	VCount=0;
	
	MST=CreateGraph(Graph->Nv);
	E=new Edge;
	
	dist[0]=0;
	VCount++;
	parent[0]=-1;
	
	while(1)
	{
		V=FindMin(Graph,dist);
		if (V==ERROR)
		{
			break;
		}
		E->V1=parent[V];
		E->V2=V;
		E->Weight=dist[V];
		InsertEdge(MST,E);
		TotalWeight+=dist[V];
		dist[V]=0;
		VCount++;
		
		a[k]=E->Weight;
		b[k]=E->V1;
		c[k]=E->V2;
		k++;
		
		for (W=0;W<Graph->Nv;W++)
		{
			if (dist[W]!=0&&Graph->G[V][W]<Infinity)
			{
				if (Graph->G[V][W]<dist[W])
				{
					dist[W]=Graph->G[V][W];
					parent[W]=V;
				}
			}
		} 
	}
	
	if (VCount<Graph->Nv)
	{
		TotalWeight=ERROR; 
	}
	
	Sort(a,b,c,k,Graph);
	
	return TotalWeight;
}

int main()
{
	MGraph* Graph;
	MGraph* MST;
	int Total;
	
	Graph=BuildGraph(Graph);
	Total=Prim(Graph,MST);
 
	cout<<Total;
	
	return 0;
} 
