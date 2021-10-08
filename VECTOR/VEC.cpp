// vector
// 动态数组
// 头文件
// #include<vector> 
// using namespace std;
// 定义和初始
// vector<T> v;
// Vector<int> v/ vector<node> v

// 操作
// v.empty(); //判断v是否为空
// v.size();
// v.push_back();
// v.pop_back()
// v[i]

// 迭代器(iterator)
// 用作储存vector中元素位置,作用相当于指针
// 定义: vector<T>::iteartor iter 
// = v.begin();           //iter指向v第一个元素
// = v.end();              //iter指向v最后一个元素的下一个元素
//        *iter                         //iter指向的元素的值,可对其进行赋值
//        iter++                      //iter指向v下一个元素

// 常用法: 
// for(vector<T>::iterator iter=v.begin();iter != v.end(); ++iter){}

// insert(iterator， type_define)
// 在iterator位置插入一个元素，后面元素依次后移
// vector<int> v ; v.insert(v.begin(), 5);
// erase(iterator)
// 移除iterator位置元素，后面元素依次前移




// #include<algorithm>
// Using namespace std;
// sort(start,end,排序方法)
// #include <iostream>     // std::cout  
// #include <algorithm>    // std::sort  
// #include <vector>       // std::vector   
// 		using namespace std;
// bool myfunction (int i,int j) { return (i<j); }  
// int main () {  
//   int myints[] = {32,71,12,45,26,80,53,33};  
//   std::vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33    
//  
//  // using default comparison (operator <):  
//   std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33   
//  
//  // using function as comp  
//   std::sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)    
//   
// // print out content:  
// for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)  
//     std::cout << ' ' << *it;  
//  
//  std::cout << '\n';  
//   return 0;  



#include<iostream>
using namespace std;

class Key {
	int key;
public:
	Key (int x = 0);
	int the_key( ) const;
};

bool operator == (const Key &x, const Key &y);

Key::Key(int x){
	key=x;
}

int Key::the_key() const{
	return key;
}

bool operator == (const Key &x, const Key &y)
{
	return x.the_key( ) == y.the_key( );
}

class Record{
public:
	operator Key( ); // Record to Key 的隐式转换 .
	Record(int x=0, int y=0);
private:
	int key;
	int other;
};

Record::Record(int x, int y){
	key=x;
	other=y;
}

Record::operator Key( ){
	Key tmp(key);
    return tmp;
}

int main(){
	Key target(5);
	Record myrecord(5,9);
	if (target==myrecord)  cout<<"yes"<<endl;
	else cout<<"no"<<endl;

}

// 调用operator Key( )构造临时Key tmp,采用void operator == (const Key &x, const Key &y)操作符比较。
