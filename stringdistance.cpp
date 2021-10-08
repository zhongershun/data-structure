#include<iostream>
#include<string>
using namespace std;
#define maxlength 30 //可比较的最长字符串的长度为30
#define min(x,y) x<y?x:y

int stringdistance(string A,string B);

int main()
{
    string A,B;
    cin>>A>>B;
    int distance=stringdistance(A,B);
    cout<<distance<<endl;
}

int stringdistance(string A,string B)
{
    int count[maxlength][maxlength];
    int length1=A.length();
    int length2=B.length();
    for (int i = 0; i < length2+1; i++)
    {
       count[i][0]=i; 
    }
    for (int i = 0; i < length1+1; i++)
    {
        count[0][i]=i;
    }
    for (int i = 1; i < length2+1; i++)
    {
        for (int j = 1; j < length1+1; j++)
        {
            if (A[j]==B[i])
            {
                count[i][j]=count[i-1][j-1];
            }
            else
            {
                int minop=min(count[i-1][j],count[i][j-1]);
                minop=min(minop,count[i-1][j-1]);
                count[i][j]=minop+1;
            }
        }
    }
    for (int i = 0; i < length2+1; i++)
    {
        for (int j = 0; j < length1+1; j++)
        {
            cout<<count[i][j]<<" ";
        }
        cout<<endl;
    }
    return count[length2][length1];
}