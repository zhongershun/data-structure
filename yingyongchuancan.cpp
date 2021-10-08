#include<iostream>
using namespace std;
int main()
{
    int a=10;
    int b=20;
    int &c=a;  //&不同于指针中取地址的意思而是说现在c与a是同一个数的名称，那么作用其中一个另一个自然就会改变
    c=b;
    cout<<a<<"\t"<<b<<endl;
}