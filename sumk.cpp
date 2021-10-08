#include<iostream>
#include<stack>
using namespace std;

#define maxarray 100
int n;

class sumk
{
private:
    int sum;
    int a[maxarray];
    int a_visited[maxarray];
    stack<int> An;
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
        cin>>a[i];
        a_visited[i]=0;
    }
}


void sumk::sum_k(int k)
{
    int i=0;
    An.push(i);
    sum=a[0];
    do
    {
        int cur=An.top();
        if (cur==n)
        {
            break;
        }
        if (sum==k)
        {
            cout<<"Yes";
            return;
        }
        int next;
        bool canadd=false;
        for (int j = cur+1; j < n; j++)
        {
            if (sum+a[j]<=k&&a_visited[cur]<j)
            {
                canadd=true;
                next=j;
                sum+=a[next];
                a_visited[cur]=j;
                An.push(next);
                break;
            }
        }
        if (!canadd)
        {
            An.pop();
            sum-=a[cur];
        }
        if (An.empty()&&cur<n-1)
        {
            An.push(cur+1);
        }
    } while (!An.empty());
    cout<<"No";
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



