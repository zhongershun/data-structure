#ifndef _MYQUEUE_H_
#define _MYQUEUE_H_

#define maxentry 100

enum Error_code{underflow,overflow,success};

template<class Queue_entry>
class MyQueue
{
    private:
        int count;
        int front,rear;
        Queue_entry entry[maxentry];

    public:
        MyQueue();
        bool empty()const;
        bool full()const;
        int size()const;
        void clear();
        Error_code append(const Queue_entry &item);
        Error_code serve(Queue_entry &item);
        Error_code retrieve();
    
};

#endif