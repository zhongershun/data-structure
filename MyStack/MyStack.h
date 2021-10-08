#ifndef _MYSTACK_H_
#define _MYSTACK_H_

#define maxentry 100

enum Error_code{underflow,overflow,success};

template<class Stack_entry>
class MyStack
{
private:
    int count;
    Stack_entry entry[maxentry];
public:
    MyStack();
    bool empty()const;
    bool full()const;
    void clear();
    int size();
    Error_code push(const Stack_entry item);
    Error_code pop();
    Error_code top(Stack_entry &item);
};

#endif