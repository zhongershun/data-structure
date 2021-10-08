// What is a queue?
// Stores a set of elements in a particular order
// Stack principle: FIRST  IN  FIRST  OUT


//DEFINITION A queue of element is a finte sequence, together with the flow operation:
// 1. Create an empty queue 创建队列
// 2. Determine whether a queue is empty 判断队列是否为空
// 3. Add a new item to the queue 入队
// 4. Remove the item that was added earliest 出队
// 5. Retrieve the item that was added earliest 访问队首元素

#include<iostream>
using namespace std;
enum Error_code{underflow,overflow,success};
//同样定义一个枚举变量使得类中函数的返回值统一？
const int maxqueue=10;
//定义列队的大小
template<class Queue_entry>

class MyQueue
{
    public:
        MyQueue();
        //确定我的列队
        bool empty() const;
        //判断我的列队是否为空
        Error_code serve();
        //出队操作
        Error_code append(const Queue_entry &item);
        //入队操作
        Error_code retrieve(Queue_entry &item)const;
        //访问队首元素
        bool full() const;
        //判断列队是否满了
        int size() const;
        //判断列队的大小
        void clear();
        //清空列表
        Error_code serve_and_retrieve(Queue_entry &item);
        //同时完成出队和访问队首元素的值

    private:
        int count;
        int front,rear;
        Queue_entry entry[maxqueue];
};
template<class Queue_entry>
MyQueue<Queue_entry>::MyQueue()
{
   count=0;
   rear=-1;
   front=0;
   //确定count初始为0，并且确定此时队首对尾的位置
   //注意这里front位置是0，rear位置的-1代表对尾
}
template<class Queue_entry>
bool MyQueue<Queue_entry>::empty() const
{
   return count==0;
   //为空则返回True，不为空则返回False
}
template<class Queue_entry>
Error_code MyQueue<Queue_entry>::append(const Queue_entry &item)
{
   if (rear>=maxqueue-1) return overflow;
   //如果队尾已经到maxqueue-1处则说明已经满了不能添加，返回overflow
   count++;
   rear++; 
   entry[rear] = item;
   return success;
}
template<class Queue_entry>
Error_code MyQueue<Queue_entry>::serve()
{
   if (count <= 0) return underflow;
   //如果队首已经到0处则说明已经空不能出队，返回underflow
   count--;
   front++;
   return success;
}
template<class Queue_entry>
Error_code MyQueue <Queue_entry>::retrieve(Queue_entry &item) const
{
   if (count <= 0) return underflow;
   //如果列队空了，我们没有item的值了，那么我们就返回underflow
   item = entry[front];
   //如果没空，那么item的值自然就为现在front对应位置上的值
   return success;
}
template<class Queue_entry>
int MyQueue<Queue_entry>::size() const
{
   return count;
}
template<class Queue_entry>
bool MyQueue<Queue_entry>::full() const
{
   return(rear==maxqueue-1);
}
template<class Queue_entry>
void MyQueue<Queue_entry>::clear()
{
   count = 0;
   rear = -1 ;
   front = 0;
}
template<class Queue_entry>
Error_code MyQueue<Queue_entry>::serve_and_retrieve(Queue_entry &item)
{
	if (count <= 0) return underflow;
        item = entry[front];
        count--;
	    front++;
	return success;
}

int main()
{
    int n;
    double item;
    MyQueue<double> numbers;
    cout << " Type in an integer n followed by n decimal numbers." << endl
        << " The numbers will be printed in original order." << endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
       cin>>item;
       numbers.append(item);
    }
    cout<<endl;
    while (!numbers.empty())
    {
       numbers.serve_and_retrieve(item); 
       cout<<item<<" ";
    }
    cout<<endl;
}
