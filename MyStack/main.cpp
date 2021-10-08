#include "MyStack.h"
#include"MyStack.cpp"
#include<iostream>
using namespace std;
int main()
{
    MyStack<int> S;
    int n;
    int item;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>item;
        S.push(item);
    }
    for (int i = 0; i < n; i++)
    {
        S.top(item);
        cout<<item<<"\t";
        S.pop();
    }
}