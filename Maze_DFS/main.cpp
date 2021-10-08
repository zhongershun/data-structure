#include<iostream>
#include "MazeDFS.h"
#include "MazeDFS.cpp"
using namespace std;

int main()
{
    MazeDFS maze;
    int a[5][5]={
        {0,1,1,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0},
        {0,1,0,1,0},
        {0,0,1,0,0}
    };
    maze.initMaze(*a,5);
    cout<<"*********"<<endl;
    maze.PrintDFS();
    cout<<"*********"<<endl;
    maze.PrintPath();
    cout<<"*********"<<endl;
    return 0;
}
