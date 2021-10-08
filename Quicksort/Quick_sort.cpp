#include<iostream>
using namespace std;

void Quick_sort(int start,int end,int *a)
{
    if (start>=end)
    {
        return;
    }
    int i=start;
    int j=end;
    int key=a[start];
    while (start<end)
    {
        while (key<=a[end]&&end>start)  
        {
            end--;
        }
        if (key>a[end])
        {
            int temp=a[start];
            a[start]=a[end];
            a[end]=temp;
            start++;
        }
        while (key>=a[start]&&end>start)
        {
            start++;
        }
        if (key<a[start])
        {
            int temp=a[end];
            a[end]=a[start];
            a[start]=temp;
            end--;
        }
    }
    Quick_sort(i,start-1,a);
    Quick_sort(start+1,j,a);
}

int main()
{
    int n;
    int a[100];
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    Quick_sort(0,n-1,a);
    cout<<a[0];
    for (int i = 1; i < n; i++)
    {
        cout<<" "<<a[i];
    }
    return 0;
}