#include<iostream>
using namespace std;

class life
{
    public:
    void init()
    {
        int x,y;
        for (int i=0;i<8;i++)
        {
            for (int j=0;j<8;j++)
            {
                mat[i][j]=0;
            }
        }
        cin>>k;
        cin>>x>>y;
        while(x!=-1&&y!=-1)
        {
            mat[x][y]=1;
            cin>>x>>y;
        }
    }
    void update()
    {
        int tmp_mat[8][8];
        for (int i=0;i<8;i++)
        {
            for (int j=0;j<8;j++)
            {
                tmp_mat[i][j]=0;
            }
        }
        while(k--){
        for (int i=1;i<7;i++)
        {
            for (int j=1;j<7;j++)
            {
                int num=neighbor_count(i,j);
                if(mat[i][j]==1)
                {
                    if(num==2||num==3)
                    {
                        tmp_mat[i][j]=1;
                    }
                    else
                    {
                        tmp_mat[i][j]=0;
                    }
                }
                else
                {
                    if(num==3)
                    {
                        tmp_mat[i][j]=1;
                    }
                    else
                    {
                        tmp_mat[i][j]=0;
                    }
                }
            }
        }
        for (int i=1;i<7;i++)
        {
            for (int j=0;j<7;j++)
            {
                mat[i][j]=tmp_mat[i][j];
            }
        }
        }
    }
    void print()
    {
        for (int i=1;i<7;i++)
        {
            for (int j=1;j<7;j++)
            {
                if (j==6)
                {
                    cout<<mat[i][j]<<endl;
                }
                else
                {
                    cout<<mat[i][j]<<" ";
                }
                 
            }
        }
    }

    private:
    int neighbor_count(int x,int y)
    {
        int num=0;
         for (int i=x-1;i<=x+1;i++)
        {
            for (int j=y-1;j<=y+1;j++)
            {
                num+=mat[i][j];

            }
        }
        num-=mat[x][y];
        return num;
    }
    
    int mat[8][8];
    int k;

    
};
int main()
{
    life life;
    life.init();
    life.update();
    life.print();
}