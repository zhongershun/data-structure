#include<iostream>
#include<queue>

using namespace std;

#define maxcolrow 100


// 初始位置入列
// 同时标记初始位置已经走过
// while(列队不为空)
// {
//     取出列顶为cur
//     if(cur为终点位置)
//     {
//         return;
//     }
//     继续进行下一步讨论
//     for循环完成4个方向下一步
//     {
//         if(下一步可以走)
//         {
//             我们将下一步放入列队中
//             注意这里要将4个方向都考虑玩然后全部放入列队中
//             同时这里需要把next的来源即现在的cur记下
//             可以写作backpath[next.row][next.col]=cur;
//             这样操作那么我们在后面找路径时可以用递归的方法来找到
//         }
//         next放入列队中时我们就可以开始while循环的作用
//     }

// }

struct Pos
{
    int row;
    int col;
};

class MazeBFS
{
private:
    int colrow;
    queue<Pos> mazequeue;
    Pos pstart;
    Pos pend;
    int matrix[maxcolrow][maxcolrow];
    int vistedPath[maxcolrow][maxcolrow];
    Pos backpath[maxcolrow][maxcolrow];

public:
    MazeBFS();
    bool cango(Pos next,Pos cur);
    void PrintBFS();
    void PrintPath();
    void PrintMaze(int m,int n);
    void initMaze(int m,int n);
};



MazeBFS::MazeBFS()
{
    pstart.row=1;
    pstart.col=1;
}

void MazeBFS::initMaze(int m,int n)
{
    for (int i = 0; i < n+2; i++)
    {
        matrix[0][i]=9;
        matrix[m+1][i]=9;
    }
    for (int i = 0; i < m+2; i++)
    {
        matrix[i][0]=9;
        matrix[i][n+1]=9;
    }
    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            cin>>matrix[i][j];
            vistedPath[i][j]=0;
        }
        
    }
    pend.row=m;
    pend.col=n;
}

void MazeBFS::PrintMaze(int m,int n)
{
    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void MazeBFS::PrintBFS()
{
    Pos cur;
    cur.col=pstart.col;
    cur.row=pstart.row;
    mazequeue.push(cur);
    vistedPath[cur.row][cur.col]=1;
    while (!mazequeue.empty())
    {
        cur=mazequeue.front();
        if (cur.col==pend.col&&cur.row==pend.row)
        {
            // PrintMaze();
            cout<<"1";
            return ;
        }
        int a[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        Pos next;
        for (int i = 0; i < 4; i++)
        {
            next.col=cur.col+a[i][1];
            next.row=cur.row+a[i][0];
            if (cango(next,cur))//下一步可以走
            {   
                vistedPath[next.row][next.col]=1;//将下一步的位置标记
                mazequeue.push(next);
                backpath[next.row][next.col]=cur;
            }
        }
        mazequeue.pop();
    }   
    cout<<"0";
}

bool MazeBFS::cango(Pos next,Pos cur)
{
    return matrix[cur.row][cur.col]!=matrix[next.row][next.col]&&matrix[next.row][next.col]!=9&&vistedPath[next.row][next.col]==0;
}



int main()
{
    int m,n;
    cin>>m>>n;
    MazeBFS maze;
    maze.initMaze(m,n);
    maze.PrintBFS();
    // cout<<"*********"<<endl;
    // maze.PrintMaze(m,n);
    // cout<<"*********"<<endl;
    return 0;
}