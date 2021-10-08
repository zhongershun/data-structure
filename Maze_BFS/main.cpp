#include<iostream>
#include "MazeBFS.h"
#include "MazeBFS.cpp"
using namespace std;

int main()
{
    MazeBFS maze;
    int a[5][5]={
        {0,1,1,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0},
        {0,1,0,1,0},
        {0,0,1,0,0}
    };
    maze.initMaze(*a,5);
    cout<<"*********"<<endl;
    maze.PrintBFS();
    cout<<"*********"<<endl;
    maze.PrintPath();
    cout<<"*********"<<endl;
    return 0;
}