#include<iostream>
#include "Queen.h"
using namespace std;


Queen::Queen()
{
    num=board;
    result=0;
}


void Queen::initboard()
{
    for (int i = 0; i < board; i++)
    {
        for (int j = 0; j < board; j++)
        {
            pos[i][j]=0;
        }
    }
}


void Queen::DFS(int row)
{
    for (int i = 0; i < board; i++)
    {
        if(check(row,i))
        {
            // Queenstack.push(i);
            pos[row][i]=8;
            num--;
            if (num==0&&row==board-1)
            {
                result++;
                Printboard();
                cout<<endl;
                pos[row][i]=0;
                // Queenstack.pop();
                num++;
                return;
            }
            else
            {
                DFS(row+1);
                // Queenstack.pop();
                pos[row][i]=0;
                num++;
            }
        }
    }
}


bool Queen::check(int row,int i)
{
    int direction[3][2]={{-1,0},{-1,-1},{-1,1}};
    if (row==0)
    {
        return true;
    }
    if (i==board-1)
    {
        for (int j = 0; j < 2; j++)
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
            } while (x>0);
        }
    }
    else if (i==0)
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
        x=row,y=i;
        do
        {
            x+=direction[2][0];
            y+=direction[2][1];
            if (pos[x][y]!=0)
            {
                return false;
            }
        } while (x>0);

    }
    else
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
            } while (x>0&&y>0&&y<board-1);
        }
    }
    return true;
}


void Queen::Printboard()
{
    for (int i = 0; i < board; i++)
    {
        for (int j = 0; j < board; j++)
        {
            cout<<pos[i][j]<<" ";
        }
        cout<<endl;
    }
}