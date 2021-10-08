#include<iostream>
using namespace std;


class A
{
    public:
    A(){
        X=Y=0;
        cout<<"Default"<<endl;
    }
    A(int xx,int yy)
    {
        X=xx;
        Y=yy;
        cout<<"constructor"<<endl;
    }
    ~A(){
        cout<<X<<"  "<<Y<<endl;
        cout<<"Destructor"<<endl;
    }
    private:
    int X;
    int Y;
};

int main()
{
    A a;
    A *p1=new A(1,2);
    delete p1;
    return 0;
}