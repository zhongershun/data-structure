#include<iostream>
// #include<stack>
using namespace std;

#define maxarea 20
int R;
int C;

struct Pos
{
    int row;
    int col;
};

class ski_DFS
{
private:
    int step;
    int martix[maxarea][maxarea];
    // stack<Pos> path;
    Pos start;
public:
    int maxstep;
    ski_DFS();
    bool cango(Pos cur,Pos next);
    void init();
    void findpath(Pos cur);
    void allarea();
};

ski_DFS::ski_DFS()
{
    step=0;
    maxstep=0;
}

void ski_DFS::init()
{
    for (int i = 0; i <=R+1; i++)
    {
        martix[i][0]=1000;
        martix[i][C+1]=1000;
    }
    for (int i = 0; i <=C+1; i++)
    {
        martix[0][i]=1000;
        martix[R+1][i]=1000;
    }
    for (int i = 1; i < R+1; i++)
    {
        for (int j = 1; j < C+1; j++)
        {
            cin>>martix[i][j];
        }
    }
    // start.row=1;
    // start.col=1;
    // path.push(start);
}

// 从某个点开始，我们递归找到了所有的可以走的路，并且找到了此时最长的路
void ski_DFS::findpath(Pos cur)
{
    // cur=path.top();
    step++;
    if (step==R*C)
    {
        maxstep=step;
        // goto out;
    }
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    Pos next;
    for (int i = 0; i < 4; i++)
    {
        next.row=cur.row+dir[i][0];
        next.col=cur.col+dir[i][1];
        if (cango(cur,next))
        {
            // path.push(next);
            findpath(next);
        }
    }
    if (step>=maxstep)
    {
        maxstep=step;
    }
    step--;
    // path.pop();
}

// 历遍整个区域找每个点的路径，寻找最长路线
void ski_DFS::allarea()
{
    for (int i = 1; i < R+1; i++)
    {
        for (int j = 1; j < C+1; j++)
        {
            Pos pstart;
            pstart.col=j;
            pstart.row=i;
            findpath(pstart);
        }
    }
}

bool ski_DFS::cango(Pos cur,Pos next)
{
    return martix[next.row][next.col]<martix[cur.row][cur.col];
}

int main()
{
    ski_DFS s;
    cin>>R>>C;
    s.init();
    s.allarea();
    cout<<s.maxstep;
}