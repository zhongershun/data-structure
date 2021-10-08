#include<iostream>
#include<string>
using namespace std;

void suibian(int* &a)
{
    int* b;
    b=a;
    cout<<*b;
    (*b)--;
    cout<<*a;
}

int main()
{
    string s;
    cin>>s;
    cout<<s;
}