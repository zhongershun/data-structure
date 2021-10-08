#include<iostream>
#include<queue>
using namespace std;

#define maxarea 20
int R;
int C;

struct Pos
{
    int row;
    int col;
};

class ski_BFS
{
private:
    int martix[maxarea][maxarea];
    queue<Pos> path;
    Pos start;
    Pos backPathBFS_[maxarea][maxarea];
public:
    Pos pstart;
    int step;
    int maxstep;
    ski_BFS();
    bool cango(Pos cur,Pos next);
    void init();
    void findpath();
    void allarea();
    void findstep(Pos cur);
};

ski_BFS::ski_BFS()
{
    maxstep=0;
}

void ski_BFS::init()
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
}

// 从某个点开始，我们找寻所有的可以走的路，对于其中找到终点的我们回溯它的step
void ski_BFS::findpath()
{
    Pos cur;
    while (!path.empty())
    {
        cur=path.front();
        path.pop();
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        Pos next;
        bool cango_=false;
        for (int i = 0; i < 4; i++)
        {
            next.row=cur.row+dir[i][0];
            next.col=cur.col+dir[i][1];
            if (cango(cur,next))
            {
                backPathBFS_[next.row][next.col].row=cur.row;
                backPathBFS_[next.row][next.col].col=cur.col;
                cango_=true;
                path.push(next);
            }
        }
        if (!cango_)
            {
                findstep(cur);
                if (step>maxstep)
                {
                    maxstep=step;
                }
            }
    }    
}

void ski_BFS::findstep(Pos cur)
{
    step=1;
    while (cur.row!=pstart.row||cur.col!=pstart.col)
    {
        step++;
        cur=backPathBFS_[cur.row][cur.col];
    }
}


// 历遍整个区域找每个点的路径，寻找最长路线
void ski_BFS::allarea()
{
    for (int i = 1; i < R+1; i++)
    {
        for (int j = 1; j < C+1; j++)
        {
            pstart.col=j;
            pstart.row=i;
            path.push(pstart);
            findpath();
        }
    }
}

bool ski_BFS::cango(Pos cur,Pos next)
{
    return martix[next.row][next.col]<martix[cur.row][cur.col];
}

int main()
{
    ski_BFS s;
    cin>>R>>C;
    s.init();
    s.allarea();
    cout<<s.maxstep;
}