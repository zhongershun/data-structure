#include<bits/stdc++.h>
using namespace std;

int numVeterx;
int numEdge;

// 定义邻接点
struct AdjV
{
    int v;// 邻接点的下表
    int weight;// 临界点的权重
    AdjV* next;
};

// 定义表头
struct AdjList
{
    // 头的下标
    int v;
    // 指向节点
    AdjV* firstVetex;
    
};


struct Edge
{
    int a;
    int b;
    int weight;
};

void swap(Edge* edge1,Edge* edge2)
{
    Edge temp=*edge1;
    *edge1=*edge2;
    *edge2=temp;    
}
int visited[100]={0};
int src[100]={0};
// 定义一张图
struct Graph
{
    int numVertex;
    int numEdge;
    // 指向表头节点
    AdjList *G[100];
    Edge edge[3];
};

void addnode(Graph* graph,int start,int end,int w)
{
    AdjV *newEdge1,*p1;
        newEdge1 = new AdjV;
        p1=new AdjV;
        newEdge1->v=end;
        newEdge1->weight=w;
        newEdge1->next=NULL;
        // 判断头节点是否有过赋值
        if (!visited[start])
        {
            graph->G[start]=new AdjList;
            graph->G[start]->v=start;
            graph->G[start]->firstVetex=NULL;
            visited[start]=1;
            src[start]=start;
        }
        p1=graph->G[start]->firstVetex;
        while (p1!=NULL)
        {
            p1=p1->next;
        }
        p1=newEdge1;
        graph->G[start]->firstVetex=p1;
}

void creatGraph(Graph* &graph)
{
    // 定义输入的节点数量和边的数量
    cin>>numVeterx>>numEdge;
    graph->numVertex=numVeterx;
    graph->numEdge=numEdge;
    for (int i = 0; i < numEdge; i++)
    {
        int start,end,w;
        cin>>start;
        cin>>end;
        cin>>w;
        addnode(graph,start,end,w);
        addnode(graph,end,start,w);
        graph->edge[i].weight=w;
        graph->edge[i].a=start;
        graph->edge[i].b=end;
    }
    for (int i = 0; i < numEdge-1; i++)
    {
        for (int j = i+1; j < numEdge; j++)
        {
            if ((graph->edge[i].weight)>(graph->edge[j].weight))
            {
                swap(&graph->edge[i],&graph->edge[j]);
            }
        }
    }    
}

int fingSource(int a)
{
        a=src[a];
   
    return a;
}

int mintree(Graph *graph)
{
    int path;
    for (int i = 0; i < numEdge; i++)
    {
        if (fingSource(graph->edge[i].a)==fingSource(graph->edge[i].b))
        {
            continue;
        }
        src[fingSource(graph->edge[i].b)]=fingSource(graph->edge[i].a);
        path+=graph->edge[i].weight;
        // if (src[graph->edge[i].a]==src[graph->edge[i].b])
        // {
        //     continue;
        // }
        // if (src[graph->edge[i].a]<src[graph->edge[i].b])
        // {
        //     src[graph->edge[i].b]=src[graph->edge[i].a];
        //     for (int j = 0; j < i; j++)
        //     {
        //         if (graph->edge[j].a==graph->edge[i].b||graph->edge[j].b==graph->edge[i].a)
        //         {
        //             src[graph->edge[j].a]=src[graph->edge[i].a];
        //             src[graph->edge[j].b]=src[graph->edge[i].a];
        //         }
        //     }
        // }
        // path+=graph->edge[i].weight;
        // for (int j = 1; j < numVeterx; j++)
        // {
        //     bool ok=true;
        //     if (src[0]!=src[j])
        //     {
        //         ok=false;
        //     }
        //     if (ok)
        //     {
        //         break;
        //     }
        // }
    }
    return path;    
}

int main()
{
    Graph *graph;
    graph=new Graph;
    creatGraph(graph);
    int path=mintree(graph);
    cout<<path<<endl;
}