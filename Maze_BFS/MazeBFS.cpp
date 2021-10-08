#include<iostream>
#include "MazeBFS.h"

using namespace std;

MazeBFS::MazeBFS()
{

}

void MazeBFS::initMaze(int *amatrix,int acolrow)
{
    for (int i = 0; i < acolrow+2; i++)
    {
        matrix[0][i]=1;
        matrix[acolrow+1][i]=1;
        matrix[i][0]=1;
        matrix[i][acolrow+1]=1;
    }
    for (int i = 1; i < acolrow+1; i++)
    {
        for (int j = 1; j < acolrow+1; j++)
        {
            matrix[i][j]=amatrix[(i-1)*acolrow+j-1];
        }
    }
    pstart.col=1;
    pstart.row=1;
    pend.col=5;
    pend.row=5;
    colrow=acolrow;
}

void MazeBFS::PrintMaze()
{
    for (int i = 1; i < colrow+1; i++)
    {
        for (int j = 1; j < colrow+1; j++)
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
    while (!mazequeue.empty())
    {
        cur=mazequeue.front();
        if (cur.col==pend.col&&cur.row==pend.row)
        {
            PrintMaze();
            return ;
        }
        int a[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        Pos next;
        for (int i = 0; i < 4; i++)
        {
            next.col=cur.col+a[i][1];
            next.row=cur.row+a[i][0];
            if (cango(next))//下一步可以走
            {   
                matrix[next.row][next.col]=5;//将下一步的位置标记
                mazequeue.push(next);
                backpath[next.row][next.col]=cur;
            }
        }
        mazequeue.pop();
    }   
}

bool MazeBFS::cango(Pos cur)
{
    return matrix[cur.row][cur.col]==0;
}

void MazeBFS::PrintPath()
{
    Pos cur;
    cout<<"("<<pend.row<<","<<pend.col<<")";
    cur=backpath[pend.row][pend.col];
    while (cur.row!=pstart.row&&cur.col!=pstart.col)
    {
        cout<<"->"<<"("<<cur.row<<","<<cur.col<<")";
        cur=backpath[cur.row][cur.col];
    }
    cout<<endl;
}