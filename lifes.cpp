#include<iostream>
using namespace std;
class life
{
private:
    int x,y;
    int k;
    int mats[10][10];
    int tem_mat[10][10];
    int Neighor(int i,int j);
public:
    void mat();
    void update();
    void print();
};
void life::mat()
{
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            mats[i][j]=0;
            tem_mat[i][j]=0;
        }
    }
    cin>>k;
    cin>>x>>y;
    while (x!=-1,y!=-1)
    {
        mats[x][y]=1;
        tem_mat[x][y]=1;
        cin>>x>>y;
    }
}
int life::Neighor(int x,int y)
{
    int num=0;
    for (int i=x-1;i<=x+1;i++)
    {
        for (int j=y-1;j<=y+1;j++)
        {
            num+=mats[i][j];
        }
    }
    num-=mats[x][y];
    return num;
}
void life::update()
{
    while(k--)
    {
        for (int i=1;i<7;i++)
        {
            for (int j=0;j<7;j++)
            {
                int num=Neighor(i,j);
                if (mats[i][j]==1)
                {
                    if (num==2||num==3)
                    {
                        tem_mat[i][j]=1;
                    }
                    else
                    {
                        tem_mat[i][j]=0;
                    } 
                }
                else
                {
                    if (num==3)
                    {
                        tem_mat[i][j]=1;
                    }
                    else
                    {
                        tem_mat[i][j]=0;
                    }
                }
            }
        }
        for (int i=0;i<7;i++)
        {
            for (int j=0;j<7;j++)
            {
                mats[i][j]=tem_mat[i][j];
            }
        }
    }
}
void life::print()
{
    for (int i=1;i<7;i++)
    {
        for (int j=1;j<6;j++)
        {
            cout<<mats[i][j]<<" ";
        }
        cout<<mats[i][6]<<"\n";
    }
    
}
int main()
{
    life life;
    life.mat();
    life.update();
    life.print();
}
