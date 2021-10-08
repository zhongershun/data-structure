#include<iostream>
using namespace std;

/*
对于桶的定义
存入单词
计入单词的数量
*/
struct bucket
{
    char (*s)[3];//每个单词是3个字母
    int count;
};

// void copy_str(char s1[],char s2[])
// {
//     for (int i = 0; i < 3; i++)
//     {
//         s1[i]=s2[i];
//     }
// }

void Radix_sort(int n,char (*str)[3],int d)
{
    if (d==3||n==1)
    {
        return;
    }
    bucket buck[26];//定义26个桶;
    for (int i = 0; i < 26; i++)//把26个桶清空
    {
        buck[i].count=0;
        buck[i].s=new char[n][3];//每个桶最大放入n个单词
    }
    for (int i = 0; i < n; i++)
    {
        char radix=str[i][d];//查看此时的基数
        int ind=radix-'a';//基数对应的桶的号数
        // copy_str(buck[ind].s[buck[ind].count],str[i]);
        for (int j = 0; j < 3; j++)
        {
            buck[ind].s[buck[ind].count][j]=str[i][j];
        }
        buck[ind].count++;
        // buck[ind].s[buck[ind].count++]=str[i];//将单词放入对应桶对应单词序数的位置
    }//至此第一位的顺序已经确定，接下来需要对每个桶中的单词再进行高位排序
    for (int i = 0; i < 26; i++)
    {
        if(buck[i].count!=0)
        {
            Radix_sort(buck[i].count,buck[i].s,d+1);//递归作用每一个桶继续分
        }
    }
    // 开始把桶和在一起
    // char (*new_str)[3];
    // new_str=new char[n][3];
    int index_str=0;
    for (int i = 0; i < 26; i++)
    {
        int temp_count=buck[i].count;
        while (buck[i].count)
        {
            // copy_str(str[index_str++],buck[i].s[(temp_count-(buck[i].count--))]);
            for (int j = 0; j < 3; j++)
            {
                str[index_str][j]=buck[i].s[(temp_count-(buck[i].count))][j];
            }
            buck[i].count--;
            index_str++;
        }
            delete (buck[i].s);
    }
    // 至此new_str有序
    // 把他赋值给str就行
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         str[i][j]=new_str[i][j];
    //     }
    // }
    // delete new_str;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout<<str[i][j];
    //     }
    //     cout<<" ";
    // }
    // cout<<endl;
}

int main()
{
    char (*str)[3];
    int n;
    cin>>n;
    getchar();
    str=new char[n][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            str[i][j]=getchar();
        }
        getchar();
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout<<str[i][j];
    //     }
    //     cout<<" ";
    // }
    // cout<<endl;
    Radix_sort(n,str,0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<str[i][j];
        }    
        if (i==n-1)
        {
            cout<<endl;
        }
        else
        {
            cout<<" ";
        }
    }
    delete []str;
}