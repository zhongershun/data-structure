#include<bits/stdc++.h>
using namespace std;

const int maxn=11;

int n,m,x,u,v;
int visted[maxn]={0};
int d[maxn]={0};
int color[maxn]={0};
int c=0;
vector<int> g[maxn];// 不同的点的邻接点不同，记录多个点的邻接点
queue<int> bfs_list;

void bfs()
{
    for (int i = 0; i < n; i++)
    {
        if (d[i]==0)
        {
            bfs_list.push(i);
            color[i]=c;
            visted[i]=1;
        }
    }
    while (!bfs_list.empty())
    {
        int k=bfs_list.front();
        bfs_list.pop();
        for (int j = 0; j < int(g[k].size()); j++)
        {
            int temp=g[k][j];
            if (visted[temp]!=1)
            {
                color[temp]=color[k]+1;
                bfs_list.push(temp);
                visted[temp]=1;
            }
        }        
    }
}

int main()
{
    int num;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>num;
        for (int j = 0; j < num; j++)
        {
            cin>>u;
            d[u]++;
            g[i].push_back(u); 
        }
        // 因为是有向的图，表示u->v,所以v的度数加一
    }
    bfs();
    bool can=true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < int(g[i].size()); j++)
        {
            if (color[i]==color[j])
            {
                can=false;
                break;
            }
        }
    }
    if (can)
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
}