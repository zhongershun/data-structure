#ifndef QUEEN_H_
#define QUEEN_H_

#include<iostream>
// #include<stack>
using namespace std;

const int board=8;
class Queen
{
private:
    int pos[board][board];
    int num;
    // stack<int> Queenstack;

public:
    int result;
    Queen();
    void initboard();
    bool check(int row,int i);
    void DFS(int row);
    void Printboard();
};

// 对于栈中我们存入每一行存入的列
// 然后对于从第二行开始第二行放入一个可以放置的位置时递归进入第三行，以此类推

#endif