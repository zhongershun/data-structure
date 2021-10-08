#include<iostream>
#include<stack>
using namespace std;

#define maxarray 100
int n;

struct an
{
    int index;
    int num;
};

class sumk
{
private:
    int sum;
    an a[maxarray];
    int a_visited[maxarray];
    stack<an> An;
public:
    sumk();
    void init_a(int n);//输入数组的值
    void sum_k(int i);//函数DFS寻找解

};

sumk::sumk()
{

}


void sumk::init_a(int n)
{
    for (int i = 0; i < n; i++)
    {
        cin>>a[i].num;
        a[i].index=i;
        a_visited[i]=0;
    }
}


void sumk::sum_k(int k)
{
    int maxindex=-1;
    An.push(a[0]);
    int sum=a[0].num;
    do
    {
        an cur=An.top(); 
        if (cur.index==n)
        {
            break;
        }
        if (sum==k)
        {
            if (cur.index>=maxindex)
            {
                maxindex=cur.index;    
            }  
            An.pop();
            sum-=a[cur.index].num;
            if (An.empty()&&cur.index<n-1)
            {
            An.push(a[cur.index+1]);
            sum+=a[cur.index+1].num;
            }
            continue;
        }
        int next;
        bool canadd=false;
        for (int j = cur.index+1; j < n; j++)
        {
            if (sum+a[j].num<=k&&a_visited[cur.index]<j)
            {
                canadd=true;
                next=j;
                sum+=a[next].num;
                a_visited[cur.index]=j;
                An.push(a[next]);
                break;
            }
        }
        if (!canadd)
        {
            An.pop();
            sum-=a[cur.index].num;
        }
        if (An.empty()&&cur.index<n-1)
        {
            An.push(a[cur.index+1]);
            sum+=a[cur.index+1].num;
        }
    } while (!An.empty());
    cout<<maxindex;
}

int main()
{
    int k;
    sumk a;
    cin>>n;
    a.init_a(n);
    cin>>k;
    a.sum_k(k);
}



