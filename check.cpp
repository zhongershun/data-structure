#include<iostream>
using namespace std;

int pos[8][8];
bool check(int row,int i)
{
    int direction[3][2]={{-1,0},{0,-1},{-1,-1}};
    if (i==0&&row==0)
    {
        return true;
    }
    if (i==0&&row!=0)
    {
        int x=row,y=i;
        do
        {
            x+=direction[0][0];
            y+=direction[0][1];
            if (pos[x][y]!=0)
            {
                return false;
            }
        } while (x>0);
    }
    else if (i!=0&&row==0)
    {
        int x=row,y=i;
        do
        {
            x+=direction[1][0];
            y+=direction[1][1];
            if (pos[x][y]!=0)
            {
                return false;
            }
        } while (x>0&&y>0);
    }
    else if (i!=0&&row!=0)
    {
        
        for (int j = 0; j < 3; j++)
        {
            int x=row,y=i;
            do
            {
                x+=direction[j][0];
                y+=direction[j][1];
                if (pos[x][y]!=0)
                {
                    return false;
                }
            } while (x>0&&y>0);
        }
    }
    return true;
}

int main()
{
    int i,row;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            pos[i][j]=0;
        }
    }
    pos[0][0]=1;
    cin>>row>>i;
    cout<<check(row,i);
}