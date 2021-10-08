#include<iostream>

using namespace std;

const int maxwid=8;
int wid;

class queen
{
private:
    
public:
    int num1,num2;
    int result;
    int board[maxwid][maxwid];
    void init_board();
    void put_queen1(int x);
    void put_queen2(int x);
    void print_board();
    bool can_put1(int x,int y);
    bool can_put2(int x,int y);  
};

void queen::init_board()
{
    cin>>wid;
    num1=0;
    num2=0;
    result=0;
    for (int i = 0; i < wid; i++)
    {
        for (int j = 0; j < wid; j++)
        {
            cin>>board[i][j];
        }
    }
}

bool queen::can_put1(int x,int y)
{
    if (board[x][y]==0)
        return false;
    else
    {
        int row=x,col=y;
        int dir[3][2]={{-1,0}/*向上*/,{-1,1}/*斜左*/,{-1,-1}/*斜右*/};
        if (x==0)
        {
            return true;
        }
        else if (y==0)
        {
            for (int i = 0; i < 2; i++)
            {
                row=x,col=y;
                while (col<=wid-2&&row>0)
                {
                    row+=dir[i][0];
                    col+=dir[i][1];
                    if (board[row][col]==8)
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        else if (y==wid-1)
        {
            for (int i = 0; i < 3; i+=2)
            {
                row=x,col=y;
                while (col>0&&row>0)
                {
                    row+=dir[i][0];
                    col+=dir[i][1];
                    if (board[row][col]==8)
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        else    
        {
            for (int i = 0; i < 3; i++)
            {
                row=x,col=y;
                while (col>0&&col<=wid-2&&row>0)
                {
                    row+=dir[i][0];
                    col+=dir[i][1];
                    if (board[row][col]==8)
                    {
                        return false;
                    }
                }
            }
            return true;
        }
    }
}

bool queen::can_put2(int x,int y)
{
    if (board[x][y]==0||board[x][y]==8)
        return false;
    else
    {
        int row=x,col=y;
        int dir[3][2]={{-1,0}/*向上*/,{-1,1}/*斜左*/,{-1,-1}/*斜右*/};
        if (x==0)
        {
            return true;
        }
        else if (y==0)
        {
            for (int i = 0; i < 2; i++)
            {
                row=x,col=y;
                while (col<=wid-2&&row>0)
                {
                    row+=dir[i][0];
                    col+=dir[i][1];
                    if (board[row][col]==9)
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        else if (y==wid-1)
        {
            for (int i = 0; i < 3; i+=2)
            {
                row=x,col=y;
                while (col>0&&row>0)
                {
                    row+=dir[i][0];
                    col+=dir[i][1];
                    if (board[row][col]==9)
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        else    
        {
            for (int i = 0; i < 3; i++)
            {
                row=x,col=y;
                while (col>0&&col<=wid-2&&row>0)
                {
                    row+=dir[i][0];
                    col+=dir[i][1];
                    if (board[row][col]==9)
                    {
                        return false;
                    }
                }
            }
            return true;
        }
    }
}

void queen::put_queen1(int x)
{
    for (int i = 0; i < wid; i++)
    {
        if (can_put1(x,i))
        {
            board[x][i]=8;
            num1++;
            // print_board();
            if (x==wid-1&&num1==wid)
            {
                put_queen2(0);
                board[x][i]=1;
                num1--;
                return;
            }
            else
            {
                put_queen1(x+1);
                board[x][i]=1;
                num1--;
            }
        }
    }
}

void queen::put_queen2(int x)
{
    for (int i = 0; i < wid; i++)
    {
        if (can_put2(x,i))
        {
            board[x][i]=9;
            num2++;
            // print_board();
            if (x==wid-1&&num2==wid)
            {
                result++;
                board[x][i]=1;
                num2--;
                return;
            }
            else
            {
                put_queen2(x+1);
                board[x][i]=1;
                num2--;
            }
        }
    }
}

// void queen::print_board()
// {
//     for (int i = 0; i < wid; i++)
//     {
//         for (int j = 0; j < wid; j++)
//         {
//             cout<<board[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     cout<<endl;
// }

int main()
{
    queen q;
    q.init_board();
    q.put_queen1(0);
    cout<<q.result<<endl;
}