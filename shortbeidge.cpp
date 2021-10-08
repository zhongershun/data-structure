// 1807问题
// 输入一个字符串
// 输出字符串中含有1->8->0->7
// 这样的顺序的字符串的长度

#include<iostream>
#include<string>
using namespace std;
const int maxCount=100;

int main()
{
    int c1[maxCount];
    int c8[maxCount];
    int c0[maxCount];
    int c7[maxCount];
    int n1=0;
    int n8=0;
    int n7=0;
    int n0=0;
    int temp;
    string str;
    cin>>str;
    for (int i = 0; i < int(str.length()); i++)
    {
        temp=str[i]-'0';
        switch (temp)
        {
        case 1:
            c1[n1++]=i;
            break;
        case 8:
            c8[n8++]=i;
            break;
        case 0:
            c0[n0++]=i;
            break;
        case 7:
            c7[n7++]=i;
            break;
        default:
            break;
        }
    }
    cout<<c7[n7-1]-c1[0]+1<<endl;
       
}