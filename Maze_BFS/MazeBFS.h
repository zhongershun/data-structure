#ifndef MAZEBFS_H
#define MAZEBFS_H

#include<iostream>
#include<queue>

using namespace std;

#define maxcolrow 20


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
    // int vistedPath[maxcolrow][maxcolrow];
    Pos backpath[maxcolrow][maxcolrow];

public:
    MazeBFS();
    bool cango(Pos cur);
    void PrintBFS();
    void PrintPath();
    void PrintMaze();
    void initMaze(int *amatrix,int acolrow);
};


#endif