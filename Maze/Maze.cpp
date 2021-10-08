#include "Maze.h"

Maze::Maze()
{
    //ctor

}

Maze::~Maze()
{
    //dtor
}

bool Maze::cango_(Pos &cur){
    return matrix[cur.row][cur.col]!=0? false:true;
}

void Maze::InitMaze(int *p_matrix, int n_colrow){
    for(int z=0;z<=n_colrow+1;z++){
        matrix[0][z]=1;
        matrix[n_colrow+1][z]=1;
        matrix[z][0]=1;
        matrix[z][n_colrow+1]=1;
        // 加装外围墙壁
        // 1 1 1 1 1 1 1
        // 1           1
        // 1           1
        // 1           1
        // 1           1
        // 1           1
        // 1 1 1 1 1 1 1
    }
    for(int z=1;z<=n_colrow;z++){
        for(int zz=1;zz<=n_colrow;zz++){

                // matrix[z][zz]=p_matrix[z-1][zz-1];
            
                matrix[z][zz]=p_matrix[(z-1)*n_colrow+zz-1];
            
                // 填充中间位置的墙壁或空余位置
        }
    }
    pstart.row=1;
    pstart.col=1;
    pend.row=n_colrow;
    pend.col=n_colrow;
    n_colrow_=n_colrow;

}
void Maze::DFS_(Pos cur, int step){
     cur=mazestack_.top();
     if(cur.row==pend.row && cur.col==pend.col){
        // 达到了终点位置
        // 结束函数
        // PrintMaze();
        PrintPath();
        mazestack_.pop();
        cango=false;
        return;
     }
     int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    //  分别定义向右向下，向左和向上的运动
     Pos next;
     cango=false;
     for(int z=0;z<4;z++){

        // z=0时是向下运动;
        // z=1时是向右运动;
        // z=2时是向上运动;
        // z=3时是向左运动;

        next.row=cur.row+dir[z][0];
        next.col=cur.col+dir[z][1];
        // Try next pos
        // 判断是不是可以走
        if(cango_(next)){
            mazestack_.push(next);
            cango=true;
            matrix[next.row][next.col]=step+1;
            // 判断可以走后同时将我们走过的路用step标记
            // 之后就不能再走了
            DFS_(next,step+1);

            //对于可以走的下一步我们进行递归;
            
            matrix[next.row][next.col]=0;
        //    如果我们递归完一条路想要去找另外的路线时需要把我们标记了的next清零
        //    因为其他路线可能会在经过这里
        }
     }
     if (!cango)
     {
         mazestack_.pop();
     }
     cango=false;
}
void Maze::PrintPathDFS(){
    mazestack_.push(pstart);
    matrix[pstart.row][pstart.col]=2;
    // 初始位置记作2
    
    DFS_(pstart,2);
   //开始找路

   // PrintMaze();
}



void Maze::PrintPathStack(){
    mazestack_.push(pstart);
    //把走过的每一步都放到Stack中

    matrix[pstart.row][pstart.col]=5;
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    while(!mazestack_.empty()){
        Pos cur=mazestack_.top();
        // 取出栈顶的位置来讨论
        // 如果是应为没路儿回来的那么刚才走过的位置也被赋值，所以只能换方向走
        if(cur.col==pend.col && cur.row==pend.row){
                PrintMaze();
                PrintPath();
                return;
        }
        Pos next;
        bool canexpand=false;
        for(int z=0;z<4;z++){
            next.row=cur.row+dir[z][0];
            next.col=cur.col+dir[z][1];
            if(cango_(next)){
                canexpand=true;
                matrix[next.row][next.col]=5;
                mazestack_.push(next);
                // 找到某个方向是可以走的，就把走后的位置放入Stack中
                break;
            }
        }
        if(!canexpand){
            // 如果没有方向可以走，就把现在的位置对应的栈顶的值弹出;
            // 回到前一个位置，即弹出后的栈顶对应的位置
            matrix[cur.row][cur.col]=9;
            mazestack_.pop();
        }
    }
}

void Maze::PrintPathBFS(){
    // the direction of movement
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

    //if(matrix[cur.row+1][cur.col])

    //Initilize the auxilary matrix
    for(int z=1;z<=n_colrow_;z++){
        for(int zz=1;zz<=n_colrow_;zz++){
            visitedBFS_[z][zz]=0;
            backPathBFS_[z][zz].row=0;
            backPathBFS_[z][zz].col=0;
        }
    }
    //Push the entranace
    while(!mazequeue_.empty()){
        mazequeue_.pop();
    }
    //begin our algorithm
    mazequeue_.push(pstart);
    // 第一个位置入列
    visitedBFS_[pstart.row][pstart.col]=1;
    // 把走过的位置记下来

    //The framework of BFS
    while(!mazequeue_.empty()){
        Pos cur=mazequeue_.front();
        // 访问现在的位置
        // cout<<cur.row<<","<<cur.col<<endl;
         mazequeue_.pop();
        // 取出现在位置对应的队顶
        if(cur.row==pend.row && cur.col==pend.col){
            // 如果是到终点了，那么就结束
            BackTrackPath(cur);
            // 把对应的路径找出来
            return;
        }
        // 没到终点，那么就把下一步可以扩散到的位置依次入列
        // find the adjacent
        for(int z=0;z<4;z++){
            Pos next;
            next.row=cur.row+dir[z][0];
            next.col=cur.col+dir[z][1];
            if(cango_(next)&&visitedBFS_[next.row][next.col]==0){
                // 下一步可以扩散到的位置需要满足可以走且没走过
                visitedBFS_[next.row][next.col]=1;
                // 记下下一位置的来源是现在的位置
                backPathBFS_[next.row][next.col].row=cur.row;
                backPathBFS_[next.row][next.col].col=cur.col;
                // 将下一个位置入列
                mazequeue_.push(next);
            }
        }
    }
    cout<<" Can not find a path!"<<endl;
}


void Maze::BackTrackPath(Pos cur){
    //Print the BFS track matrix
    /*for(int z=1;z<=n_colrow_;z++){
        for(int zz=1;zz<=n_colrow_;zz++){
            cout<<backPathBFS_[z][zz].row<<","<<backPathBFS_[z][zz].col<<" ";
        }
        cout<<endl;
    }*/
    while(cur.row!=pstart.row || cur.col!=pstart.col){
        cout<<cur.row<<","<<cur.col<<"-->";
        cur=backPathBFS_[cur.row][cur.col];
    }
    cout<<cur.row<<","<<cur.col<<endl;

}

void Maze::PrintMaze(){
    for(int z=1;z<=n_colrow_;z++){
        for(int zz=1;zz<=n_colrow_;zz++)
            cout<<matrix[z][zz]<<" ";
        cout<<endl;
    }
    cout<<"-----------------------------------"<<endl;
}

void Maze::PrintPath()
{

    Pos item;
    tempstack=mazestack_;
    item=tempstack.top();
    tempstack.pop();
    cout<<"("<<item.row<<","<<item.col<<")";
    while (!tempstack.empty())
    {
        item=tempstack.top();
        tempstack.pop();
        cout<<"->"<<"("<<item.row<<","<<item.col<<")";
    }
    cout<<"\n";
    
}