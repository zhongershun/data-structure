#ifndef MAZEDFS_H
#define MAZEDFS_H

#include<iostream>
#include<stack>

using namespace std;

#define maxcolrow 20


// 初始位置入栈
// while(栈没有空)
// {
//     取出栈顶为cur
//     if(判断cur是否到达终点)
//     {
//         函数结束
//     }
//     没有结束就对下一步进行讨论
//     for
//     {
//         cur向下右上左移动
//         if(任意一个方向可以移动)
//         {
//             将这个位置入栈
//             同时循环结束
//             后面会重复while循环
//         }
//         if(四个方向都走不了)
//         {
//             那么这个位置就结束同时让cur出栈
//             后面重复while循环时就会回到上一个位置
//         }
//     }
// }


struct Pos
{
    int row;
    int col;
};

class MazeDFS
{
    public:
        MazeDFS();
        void initMaze(int *amatrix,int colrow);
        void PrintDFS();
        void PrintMaze();
        void PrintPath();
    
    private:
        int colrow;
        int matrix[maxcolrow+2][maxcolrow+2];
        bool cango(Pos cur);
        Pos pstart;
        Pos pend;
        
        stack<Pos> mazestack;
};
#endif