#include<iostream>
using namespace std;

#define maxstack 10
enum Error_code{underflow,overflow,success};
template<class SElemType>
class doublestack
{
private:
    typedef struct{
    int top[2],bot[2];
    int m;
    SElemType *V;
    }DblStack;
    DblStack S;
public:
    void clear();
    bool empty(int a)const;
    bool full()const;
    Error_code push(const SElemType item,int a);
    Error_code pop(SElemType &item,int a);
};

template<class SElemType>
void doublestack<SElemType>::clear()
{
    S.m=maxstack;
    S.V=new SElemType [S.m];
    S.top[0]=S.top[0]=-1;
    S.top[1]=S.top[1]=S.m;
}

template<class SElemType>
bool doublestack<SElemType>::empty(int a)const
{
    if (a==1)
    {
        return S.top[a]==S.m;
    }
    else
    {
        return S.top[a]==-1;
    }
    
}

template<class SElemType>
bool doublestack<SElemType>::full()const
{
    return S.top[0]>=S.top[1]-1;
}

template<class SElemType>
Error_code doublestack<SElemType>::push(const SElemType item,int a)
{
    if (full())
    {
        return overflow;
    }
    else
    {
        switch (a)
        {
        case 0:
            S.V[++S.top[0]]=item;
            break;
        case 1:
            S.V[--S.top[1]]=item;
            break;
        }
        return success;
    }
}

template<class SElemType>
Error_code doublestack<SElemType>::pop(SElemType &item,int a)
{
    if(empty(a))
    {
        return underflow;
    }
    else
    {
        switch (a)
        {
        case 0:
            item=S.V[S.top[0]--];
            break;
        
        case 1:
            item=S.V[S.top[1]++];
            break;
        }
        return success;
    }
}

// 为了实现对两个不同的栈的操作,我们在入栈或者出栈的时候需要先输入case 0或1,来确定我操作的栈是栈0或栈1;
int main()
{
    doublestack<int> doublestack;
    doublestack.clear();
    int n;//n是我需要入栈的数的数量
    int a;//a是我操作的栈的序号
    int item;
    cin>>a;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>item;
        doublestack.push(item,a);
    }
    while (!doublestack.empty(a))
    {
        doublestack.pop(item,a);
        cout<<item<<" ";
    }
    cout<<endl;
}