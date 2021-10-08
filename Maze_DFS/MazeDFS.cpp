#include<iostream>
#include "MazeDFS.h"

using namespace std;

MazeDFS::MazeDFS()
{

}

void MazeDFS::initMaze(int *amatrix,int acolrow)
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

bool MazeDFS::cango(Pos cur)
{
    return (matrix[cur.row][cur.col]==0);
}

void MazeDFS::PrintDFS()
{
    mazestack.push(pstart);
    matrix[pstart.row][pstart.col]=5;
    Pos cur,next;
    while (!mazestack.empty())
    {
        cur=mazestack.top();
        if (cur.col==pend.col&&cur.row==pend.row)
        {
            PrintMaze();
            return;
        }
        int a[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        bool cannext=false;
        for (int i = 0; i < 4; i++)
        {
            next.row=cur.row+a[i][0];
            next.col=cur.col+a[i][1];
            if (cango(next))
            {
                matrix[next.row][next.col]=5;
                cannext=true;
                mazestack.push(next);
                break;
            }
        }
        if (!cannext)
        {
            mazestack.pop();
        }
    }    
}

void MazeDFS::PrintMaze()
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

void MazeDFS::PrintPath()
{
    Pos item;
    item=mazestack.top();
    mazestack.pop();
    cout<<"("<<item.row<<","<<item.col<<")";
    while (!mazestack.empty())
    {
        item=mazestack.top();
        mazestack.pop();
        cout<<"->"<<"("<<item.row<<","<<item.col<<")";
    }
    cout<<"\n";
    
}