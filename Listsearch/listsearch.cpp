#include<iostream>
#include<string>
int test(int a);  
using namespace  std;

void main()    
{  
    cout<<“函数地址：”<<test<<endl;//显示函数入口地址  
    int (*fp)(int a);  //定义了一个指向函数的指针fp
    fp=test;//将函数test的地址赋给函数指针fp  
    cout<<fp(5)<<endl;//输出fp(5),这是标准c++的写法,          cout<<(*fp)(10)<<endl;//(*fp)(10)这是兼容c语言的标准写法,

//两种写法的功能相同,但注意区分,避免写的程序产生移植性问题!    
}  
  
int test(int a)  
{  
    return a;  
}


enum Error_code{underflow, overflow, range_error_new, success};
// enum Error_code{underflow, overflow, range_error_new, success, fail, not_present};
// underflow:  链表为空之后仍旧删除
// overflow: 数组满了之后插入
// range_error_new:  插入位置有误
// Success： 操作成功
// not_present: 未找到目标

const int max_list = 30;
template <class List_entry>
class List {
public:
// methods of the List ADT
	List( );
	int size( ) const;
	bool full( ) const;
	bool empty( ) const;
	void clear( );
	void traverse(void (*visit)(List_entry &));//遍历整个List //注意函数指针的使用
	Error_code retrieve(int position, List_entry &x) const;
	Error_code replace(int position, const List_entry &x);
	Error_code remove(int position, List_entry &x);
	Error_code insert(int position, const List_entry &x);
protected:
// data members for a contiguous list implementation
	int count;
	List_entry entry[max_list];
};

Error_code sequential_search(const List<Record> &the_list,
const Key &target, int &position)
/* Post: If an entry in the list has key equal to target , then return success and the
output parameter position locates such an entry within the list.
Otherwise return not_present and position becomes invalid. */
{
int s = the_list.size( );
for (position = 0; position < s; position++) {
    Record data;
    the_list.retrieve(position, data);
    if (target == data) return success;
}
return not_present;
}

template <class List_entry>
void List<List_entry> :: traverse(void (*visit)(List_entry &))
/* Post: The action specified by function(*visit) has been performed on every entry of theList , beginning at position 0 and doing each in turn. */
{
	for (int i = 0; i < count; i++)
           (*visit)(entry[i]);
}

template <class List_entry>
void update(List_entry &x){
	x*=2;	
}

template <class List_entry>
void print(List_entry &x){
	cout<<x<<endl;	
}
