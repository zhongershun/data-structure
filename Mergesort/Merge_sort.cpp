#include<iostream>
using namespace std;

int temp[100];
void Merge_sort(int start,int end,int *a)
{
    if (start==end)
    {
        return;
    }
    int mid=(start+end)/2;
    Merge_sort(start,mid,a);
    Merge_sort(mid+1,end,a);
    int length1=mid-start+1;
    int length2=end-(mid+1)+1;
    int i=start,j=mid+1,k=start;
    while (i<start+length1&&j<mid+1+length2)
    {
        if (a[i]<a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[j++];
        }
    }
    if (i==start+length1)
    {
        while (j<mid+1+length2)
        {
            temp[k++]=a[j++];
        }
    }
    else if(j==mid+1+length2)
    {
        while (i<start+length1)
        {
            temp[k++]=a[i++];
        }
    }
    for (i = start; i <= end; i++, k++)
    {
        a[i]=temp[i];
    }
}

int main()
{
    int n;
    cin>>n;
    int a[100];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    Merge_sort(0,n-1,a);
    for (int i = 0; i < n; i++)
    {
        a[i]=temp[i];
    }
    cout<<a[0];
    for (int i = 1; i < n; i++)
    {
        cout<<" "<<a[i];
    }
    return 0;
}