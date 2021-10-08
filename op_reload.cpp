//运算符重载两种形式
// 定义为它将要操作的类的成员函数
// 定义为类的类友元函数



// 成员运算符函数
// 定义在类中如
//    class X{    //…
//           type operator@(参数表）  {  //…        //...};
// 如果成员运算符函数声明在类中，而定义在类外，其格式为：
//    type  X::operator@(参数表）
//    {//函数体}

#include <iostream>
using namespace std;
class complex{
	double real;
	double imag;
public:
	complex(double r=0,double i=0)
	{
        real=r;  
        imag=i;
    }
	void print();
	complex operator+(complex c)
	{
        complex temp;
	    temp.real=real+c.real;
	    temp.imag=imag+c.imag;
	    return temp;
    }
	complex operator-(complex c)
	{  
        complex temp;
	    temp.real=real-c.real;
	    temp.imag=imag-c.imag;
	    return temp;
    }
    complex operator*(complex c)
    {    
        complex temp;
        temp.real=(real*c.real-imag*c.imag);
        temp.imag=(real*c.imag+c.real*imag);
        return temp;
    }
    complex operator/(complex c); //除法在类外实现
};

complex complex::operator/(complex  c) 
{   complex temp;
	double t;
	t=1/(c.real*c.real+c.imag*c.imag);
	temp.real=(real*c.real+imag*c.imag)*t;
	temp.imag=(imag*c.real-real*c.imag)*t;
	return temp;
} 

void complex::print()
{   cout<<real;
    if(imag>0)   cout<<"+";
    if(imag!=0)   cout<<imag<<"i"<<endl;
}


int main()
{ 
    complex A1(2.3,4.6),A2(3.6,2.8),A3,A4,A5,A6;
    A3=A1+A2;    
    A4=A1-A2;	
    A5=A1*A2;
    A6=A1/A2;   
    A1.print(); 
    A2.print(); 
    A3.print();   
    A4.print();        
    A5.print();  
    A6.print();
    return 0;
}


#include <iostream>
class coord{
	int x,y;
public :
	coord(int i=0,int j=0);
	void print();
	coord operator++(); //重载++
};

coord::coord(int i,int j )
{
    x=i;
    y=j;
}
void coord::print()
{
    cout<<"x= "<<x<<",y="<<y<<endl;
};

coord coord:: operator++()
{		
    ++x;
    ++y;
	return *this;
}

int main()
{
	coord ob(10,20);
	ob.print();
	++ob;  //隐式调用
	ob.print();
	ob.operator++();  //显示调用
	ob.print();
	return 0;
}
