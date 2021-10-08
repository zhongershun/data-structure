#include<iostream>
#include<string>
using namespace std;
int main()
{
    const int maxn=100;
    int m,c;
    string str[maxn];
    string u,v;
    int d[maxn]={0};
    cin>>m;
    cin>>u>>v;
    str[0]=u;
    str[1]=v;
    c=2;
    for (int i = 1; i < m-1; i++)
    {
        cin>>u>>v;
        bool repu=false;
        bool repv=false; 
        for (int j = 0; j < c; j++)
        {
            if (str[j]== u)
            {
                repu=true;
                break;
            }
        }
        if (!repu)
        {
            c++;
            str[c-1]=u;
        }
        for (int j = 0; j < c; j++)
        {
            if (str[j]==v)
            {
                repv=true;
                d[j]++;
                break;
            }
        }
        if (!repv)
        {
            c++;
            str[c-1]=v;
            d[c-1]++;
        }
    }
    bool can=true;
    int winner;
    for (int i = 0; i<c; i++)
    {
        if (d[i]==0)
        {
            winner++;
        }
        if (winner>1)
        {
            can=false;
            break;
        }
    }
    if (winner>0&&can)
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
    return 0;
}