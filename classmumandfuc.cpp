#include<iostream>
using namespace std;
class classmumandfuc
{
private:
    int n;
public:
    classmumandfuc();
    // 与其类具有相同名称的成员函数一定是构造函数//
    void Printn();
};
classmumandfuc::classmumandfuc()
{
    n=10;
}
void classmumandfuc::Printn()
{
    cout<<n<<endl;
}
int main()
{
    classmumandfuc classmumandfuc;
    classmumandfuc.Printn();
    return 0;
}