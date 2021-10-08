#include<iostream>
#include "MyStack.h"
using namespace std;

template<class Stack_entry>
MyStack<Stack_entry>::MyStack()
{
    count=0;
}

template<class Stack_entry>
bool MyStack<Stack_entry>::empty()const
{
    return count==0;
}

template<class Stack_entry>
bool MyStack<Stack_entry>::full()const
{
    return count==maxentry;
}

template<class Stack_entry>
void MyStack<Stack_entry>::clear()
{
    count=0;
}

template<class Stack_entry>
int MyStack<Stack_entry>::size()
{
    return count;
}

template<class Stack_entry>
Error_code MyStack<Stack_entry>::push(const Stack_entry item)
{
    if (full())
    {
        cout<<"The Stack is full";
        return overflow;
        
    }
    else
    {
        entry[count++]=item;
        return success;
    }
}

template<class Stack_entry>
Error_code MyStack<Stack_entry>::pop()
{
    if (empty())
    {
        cout<<"The Stack is empty";
        return underflow;
        
    }
    else
    {
        count--;
        return success;
    }
}

template<class Stack_entry>
Error_code MyStack<Stack_entry>::top(Stack_entry &item)
{
    if (empty())
    {
        cout<<"The Stack is empty";
        return underflow;
    }
    else
    {
        item=entry[count-1];
        return success;
    }
}