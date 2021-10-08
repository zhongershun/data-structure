#include<iostream>
using namespace std;

const int maxqueue=10;
enum Error_code{underflow,overflow,success};
template<class Queue_entry>
class loopqueue
{
private:
    int front;
    int rear;
    int count;
    Queue_entry entry[maxqueue];
public:
    loopqueue();
    Error_code append(const Queue_entry &item);
    Error_code retrievemax(Queue_entry &item,const int k);
    bool empty(int k) const;
};

template<class Queue_entry>
loopqueue<Queue_entry>::loopqueue()
{
    count=0;
    rear=-1;
    front=0;
}

template<class Queue_entry>
bool loopqueue<Queue_entry>::empty(int k) const
{
    return count<k;
}

template<class Queue_entry>
Error_code loopqueue<Queue_entry>::append(const Queue_entry &item)
{
    if (rear>=maxqueue-1)
    {
        return overflow;
    }
    else
    {
        count++;
        rear++;
        entry[rear]=item;
        return success;
    }
}

template<class Queue_entry>
Error_code loopqueue<Queue_entry>::retrievemax(Queue_entry &item,const int k)
{
    if (count<k)
    {
        return underflow;
    }
    else
    {
        Queue_entry temp=entry[front];
        for (int i=front+1;i<front+k;i++)
        {
            if (entry[i]>=temp)
            {
                temp=entry[i];
            }
        }
        item=temp;
        count--;
        front++;
        return success;
    }
}

//这里我用item的类型为int型作例子
int main()
{
    int n,k;
    int item;
    loopqueue<int> loopqueue;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>item;
        loopqueue.append(item);
    }
    cout<<endl;
    cin>>k;
    while (!loopqueue.empty(k))
    {
        loopqueue.retrievemax(item,k);
        cout<<item<<" ";
    }
    cout<<endl;    
}