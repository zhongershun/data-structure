#include<iostream>
#include"MyQueue.h"
using namespace std;

template<class Queue_entry>
MyQueue<Queue_entry>::MyQueue()
{
   count=0;
   rear=-1;
   front=0;
}

template<class Queue_entry>
bool MyQueue<Queue_entry>::empty()const
{
   return count==0;
}

template<class Queue_entry>
bool MyQueue<Queue_entry>::full()const
{
    return count==maxentry;
}

template<class Queue_entry>
int MyQueue<Queue_entry>::size()const
{
    return count;
}

template<class Queue_entry>
void MyQueue<Queue_entry>::clear()
{
    count=0;
    front=0;
    rear=-1;
}

template<class Queue_entry>
Error_code MyQueue<Queue_entry>::append(const Queue_entry &item)
{
    if (full()) 
    {
        cout<<"The queue is full";
        return overflow;
    }
    else
    {
        count++;
        rear++; 
        entry[rear] = item;
        return success;
    }
}

template<class Queue_entry>
Error_code MyQueue<Queue_entry>::serve(Queue_entry &item)
{
    if (empty())
    {
        cout<<"The Queue is empty";
        return underflow;
    }
    else
    {
        item=entry[front];
        return success;
    }
}

template<class Queue_entry>
Error_code MyQueue<Queue_entry>::retrieve()
{
    if (empty())
    {
        cout<<"The Queue is empty";
        return underflow;
    }
    else
    {
        front++;
        count--;
        return success;
    }
}
