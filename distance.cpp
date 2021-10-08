#include<iostream>
#include<math.h>
using namespace std;

struct points
{
    int x;
    int y;
    float dis;
};

int main()
{
    struct points *p;
    int N;
    cin>>N;
    p=new points[N];
    for (int i = 0; i < N; i++)
    {
        cin>>p[i].x>>p[i].y;
        p[i].dis=pow(p[i].x,2)+pow(p[i].y,2);
    }
    for (int i = 0; i < N-1; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            if (p[i].dis>=p[j].dis)
            {
                struct points temp;
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    int k;
    cin>>k;
    cout<<p[k-1].x<<" "<<p[k-1].y;
    
}