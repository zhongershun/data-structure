#include<bits/stdc++.h>
using namespace std;

const int maxn=11;

int n,m,x,u,v;
int d[maxn];

vector<int> g[maxn];// 不同的点的邻接点不同，记录多个点的邻接点
queue<int> topsort_list;

void dfs(int u)
{
    cout<<u<<" ";
    for (int i = 0; i < int(g[u].size()); i++)
    {
        int v=g[u][i];
    dfs(v);
    }
}

vector<int> topsort()
{
    queue<int> q;
    vector<int> topsort_res;// 与g不相同这里topsort_res只用于记录一串数即可
    int now_d[maxn];
    for (int i = 1; i <= n; i++)
    {
        now_d[i]=d[i];// 记录所有点的度数
        if (d[i]==0)// 找到度数为0的点
        {
            q.push(i);
            topsort_res.push_back(i);
        }
    }
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int i = 0; i < int(g[u].size()); i++)
        {
            int v=g[u][i];
            now_d[v]--;
            if(now_d[v]==0)
            {
                q.push(v);
                topsort_res.push_back(v);
            }
        }
    }
    return topsort_res;
}

bool check_topsort(queue<int> &topsort_list)
{
    bool is_topsort=true;
    while(!topsort_list.empty())
    {
        int u=topsort_list.front();
        topsort_list.pop();
        if (d[u])
        {
            is_topsort=false;
        }
        for (int i = 0; i < int(g[u].size()); i++)
        {
            int v=g[u][i];
            d[v]--;
        }
    }
    return is_topsort;
}

int main()
{
    cin>>n>>m;
    for (int i = 1; i <= m; i++)
    {
        cin>>u>>v;
        d[v]++;
        // 因为是有向的图，表示u->v,所以v的度数加一
        g[u].push_back(v);
    }
    cout<<"start from 2 dfs:";
    dfs(2);
    cout<<endl;
    vector<int> topsort_res=topsort();
    cout<<"torsort is:";
    for (int i = 0; i < int(topsort_res.size()); i++)
    {
        cout<<topsort_res[i]<<" ";
    }
}