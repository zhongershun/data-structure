#include<iostream>
#include<string>
using namespace std;

/*
对于桶的定义
存入单词
计入单词的数量
*/
struct bucket
{
    string *s;
    int count;
};

void Radix_sorts(int n,string *str,int d)
{
    if (n==1||d==3)
    {
        return;
    }
    bucket buck[26];
    for (int i = 0; i < 26; i++)
    {
        buck[i].count=0;
        buck[i].s=new string[n];
    }
    for (int i = 0; i < n; i++)
    {
        char radix=str[i][d];
        int index=radix-'a';
        buck[index].s[buck[index].count++]=str[i];
    }
    for (int i = 0; i < 26; i++)
    {
        if (buck[i].count!=0)
        {
            Radix_sorts(buck[i].count,buck[i].s,d+1);
        }
    }
    for (int i = 0,a = 0 ; i < 26, a < n; i++)
    {
        if (buck[i].count!=0)
        {
            int temp_count=buck[i].count;
            int k=0;
            while (k<temp_count)
            {
                str[a++]=buck[i].s[k++];
            }
            // free(buck[i].s);//释放指针
        }
        delete []buck[i].s;//释放指针
    }
    //delete []buck;
}

int main()
{
    string *str;
    int n;
    cin>>n;
    str=new string[n];
    for (int i = 0; i < n; i++)
    {
        cin>>str[i];
    }
    Radix_sorts(n,str,0);
    char end1='\n';
    char end2=' ';
    char end;
    for (int i = 0; i < n; i++)
    {
        cout<<str[i];
        end=(i==n-1?end1:end2);
        cout<<end;
    }
    delete []str;
    return 0;
}