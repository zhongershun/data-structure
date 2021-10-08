#include<iostream>
using namespace std;
template<class T>
T Abs(T n)
{
    return n<0?-n:n;
}
int main()
{
    cout<<Abs<int>(-5)<<endl;
    cout<<Abs<double>(-5.1)<<endl;
}