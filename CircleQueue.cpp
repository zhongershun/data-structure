#include<iostream>
using namespace std;

#define maxqueue 8

enum Error_code{underflow,overflow,success};
template<class Queue_entry>
class CircleQueue
{
private:
    int count;
    int front,rear;
    Queue_entry entry[maxqueue];
public:
    CircleQueue();
    bool empty()const;
    Error_code append(const Queue_entry item);
    Error_code sreve_and_retrieve(Queue_entry &item);
    bool full()const;
};

template<class Queue_entry>
CircleQueue<Queue_entry>::CircleQueue()
{
    count=0;
    front=0;
    rear=maxqueue-1;
}

template<class Queue_entry>
bool CircleQueue<Queue_entry>::empty()const
{
    return count==0;   
}

template<class Queue_entry>
bool CircleQueue<Queue_entry>::full()const
{
    return count>=maxqueue;   
}

template<class Queue_entry>
Error_code CircleQueue<Queue_entry>::append(const Queue_entry item)
{
    if (count>=maxqueue)
    {
        cout<<"This queue is overflow!"<<endl;
        return overflow;
    }
    else
    {
        count++;
        rear=((rear+1)==maxqueue)?0:(rear+1);
        //这里我们也能用一个取余操作
        //即rear=(rear+1)%maxqueue
        entry[rear]=item;
        return success;
    }
}

template<class Queue_entry>
Error_code CircleQueue<Queue_entry>::sreve_and_retrieve(Queue_entry &item)
{
    if (count<=0)
    {
        return underflow;
    }
    else
    {
        item=entry[front];
        count--;
        front=((front+1)==maxqueue)?0:(front+1);
        //与上面的操作相同我们同样可以进行一个取余操作
        //即front=(front+1)%maxqueue;
        return success;
    }
}


int main()
{
    int n;
    CircleQueue<int>CircleQueue;
    cin>>n;
    int item;
    for (int i=0;i<n;i++)
    {
        cin>>item;
        CircleQueue.append(item);
    }
    // if (CircleQueue.full())
    // {
    //     cout<<"This queue is overflow!"<<endl;
    // }
    //好像应该是不能直接判断它是不是满的时候来确定是否输出这句话
    //如果它多了或是满的时候都会输出这一句
    CircleQueue.sreve_and_retrieve(item);
    cout<<item;
    while (!CircleQueue.empty())
    {
        CircleQueue.sreve_and_retrieve(item);
        cout<<" "<<item;
    }
    cout<<endl;
    return 0;
}
