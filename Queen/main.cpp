#include<iostream>
#include "Queen.h"
#include "Queen.cpp"
using namespace std;

int main()
{
    Queen Q;
    Q.initboard();
    Q.DFS(0);
    cout<<Q.result<<endl;
}