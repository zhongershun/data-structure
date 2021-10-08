#include<iostream>
using namespace std;

int nums[100];
int target;

void erfen(int bot,int top,int mid)
{
    mid=(bot+top)/2;
    if (nums[mid]==target){
        cout<<mid;
        return;
    }
    else if (bot==top){
        cout<<"-1";
        return;
    }
    else if (nums[mid]<target){
        bot=mid+1;
    }
    else if (nums[mid]>target){
        top=mid-1;
    }
    erfen(bot,top,mid);
    return;
}

int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    cin>>target;
    int top=n;
    int bot=0;
    int mid;
    erfen(bot,top,mid);
}