#include<iostream>
using namespace std;

// 整体的思路:子树与父节点比较每次将最大的数向上传递，最后使得最大的数位于树顶，最后再把最后位置上的数与子节点上最大的数交换得到最大的数就去到了最后一位

struct point
{
    int x;
    int y;
};

// 比较，如果A大则返回True
bool compare(point A,point B)
{
    if (A.x>B.x)
    {    
        return true;
    }
    else if (A.x<B.x)
    {    
        return false;
    }
    else
    {
        if (A.y>B.y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool ifleaf(int cur,int length)
{
    if (cur<=length/2-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void swap(point &A,point &B)
{
    point temp;
    temp=A;
    A=B;
    B=temp;
}

void subheapbuild(point A[],int length,int cur,int child)
{
    while(cur>=child)
    {
    int rchild=cur*2+2;
    int lchild=cur*2+1;
    if (rchild<length)
    {
        if (compare(A[rchild],A[cur]))
        {
            swap(A[cur],A[rchild]);
            // if (ifleaf(rchild,length))
            // {
            //     subheapbuild(A,length,rchild,cur);
            // }
        }
    }
    if (compare(A[lchild],A[cur]))
    {
        swap(A[cur],A[lchild]);
        // if (ifleaf(lchild,length))
        // {
        //     subheapbuild(A,length,lchild,cur);
        // }
    }
    cur--;
    }
}

void heapbuild(point A[],int length,int cur)
{
    while(cur>=0)
    {
    int rchild=cur*2+2;
    int lchild=cur*2+1;
    if (rchild<length)
    {
        if (compare(A[rchild],A[cur]))
        {
            swap(A[cur],A[rchild]);
            // if (ifleaf(rchild,length))
            // {
            //     subheapbuild(A,length,rchild,cur);
            // }
        }
    }
    if (compare(A[lchild],A[cur]))
    {
        swap(A[cur],A[lchild]);
        // if (ifleaf(lchild,length))
        // {
        //     subheapbuild(A,length,lchild,cur);
        // }
    }
    cur--;
    }
}

void heapsort(point A[],int length,int cur)
{
    while(length>1)
    {
    cur=length/2-1;
    heapbuild(A,length,cur);
    swap(A[0],A[length-1]);
    length--;
    }
}
int main()
{
    point A[100];
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>A[i].x>>A[i].y;
    }
    int cur;
    heapsort(A,n,cur);
    for (int i = 0; i < n; i++)
    {
        cout<<"("<<A[i].x<<","<<A[i].y<<")"<<endl;
    }
    return 0;
}