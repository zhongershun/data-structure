#include"MyQueue.h"
#include"MyQueue.cpp"
#include<iostream>
using namespace std;

int main()
{
    MyQueue<int> Q;
    int n;
    cin>>n;
    int item;
    for (int i = 0; i < n; i++)
    {
        cin>>item;
        Q.append(item);
    }
    for (int i = 0; i < n; i++)
    {
        Q.serve(item);
        cout<<item<<"\t";
        Q.retrieve();
    }
    return 0;
}