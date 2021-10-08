// What is a stack?
// Stores a set of elements in a particular order
// Stack principle: LAST  IN  FIRST  OUT 


// DEFINITION A stack of elements is a finite sequence, together with the following operations:
// 1. Create the stack, leaving it empty. （创建）
// 2. Test whether the stack is Empty.
// 3. Push a new entry onto the top of the stack, provided the stack is not full. （插入）
// 4. Pop the entry off the top of the stack, provided the stack is not empty. （删除）
// 5. Retrieve the Top entry from the stack, provided the stack is not empty. （查询）

#include<iostream>
using namespace std;
enum Error_code{underflow,overflow,success};
//定义一个枚举变量让类里面的函数返回值统一？
const int maxstack=10;
//定义栈的大小
template<class Stack_entry>

class MyStack
{
    public:
        MyStack();
        //初始化我的栈,构造函数就是用来确定一些成员变量的，不能加void外部main函数中毕业不断调用
        bool empty() const;//判断我的栈是否是空的
        Error_code push(const Stack_entry &item);
        //为什么这里要是引用传参,如果不是为了节省空间可以值传参吗？
        Error_code pop();
        //弹出我们的一个栈里的值
        Error_code top(Stack_entry &item) const;
        //这里要在函数中找到应该弹出的值

    private:
        int count;
        Stack_entry entry[maxstack];
};

template<class Stack_entry>
MyStack<Stack_entry>::MyStack()
{
    count=0;
    //这里不用对我们的数组进行初始化吗？还是已经默认初始化全为0了？
}
template<class Stack_entry>
bool MyStack<Stack_entry>::empty() const
{
    bool outcome=true;
    if (count>0)
    {
        outcome=false;
    }
    return outcome;
}
template<class Stack_entry>
Error_code MyStack<Stack_entry>::push(const Stack_entry &item)
{
    Error_code outcome=success;
    if (count>=maxstack)
    //如果栈满了，就不添加并返回overflow
    //返回的overflow并不会在main函数中显现出来
    {
        outcome=overflow;
    }
    else
    //没满那么就加入item
    {
        entry[count++]=item;
    }
    return outcome;
}
template<class Stack_entry>
Error_code MyStack<Stack_entry>::pop()
{
    Error_code outcome=success;
    if (count==0)
    //如果栈已经空了，那就返回underflow
    {
        outcome=underflow;
    }
    else
    //如果栈还没用空，那就返回success并把count数量减小
    {
        count--;
    }
    return outcome;
}
template<class Stack_entry>
Error_code MyStack<Stack_entry>::top(Stack_entry &item) const
{
    Error_code outcome=success;
    if (count==0)
    //如果栈空了，我们没有item的值了，那么我们就返回underflow
    {
        outcome==underflow;
    }
    else
    //如果没空，那么item的值自然就为现在count-1对应位置上的值
    {
        item=entry[count-1];
    }
    return outcome;
}

int main()
{
    MyStack<int> number;
    int n;
    int item;
    cout<<"Type in an integer n followed by n decimal numbers."<<endl
        <<"The numbers will be printed in reverse order."<<endl;
    cin>>n;
    for (int i=0;i<n;i++) 
    {
        cin>>item;
        number.push(item);
    }
    while (!number.empty())
    {
        number.top(item);
        cout<<item<<"\t";
        number.pop();
        //top和pop能合在一起吗？
        //和列队中的一样
    }
    cout<<endl;
}