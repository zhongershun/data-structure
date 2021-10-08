#include<iostream>
using namespace std;

struct list
{
    int num;
    struct list *next;
};

struct list *add_node(int n)
{
    struct list *head,*tail,*p;
    head=tail=NULL;
    while (n)
    {
        p=new struct list[sizeof(list)];
        cin>>p->num;
        p->next=NULL;
        if (head==NULL)
        {
            head=p;
        }
        else
        {
            tail->next=p;
        }
        tail=p;
        n--;
    }
    return head;
}//实现节点的加入

struct list *hebin(struct list *l1,struct list *l2)
{
    struct list *head,*tail,*p;
    head=tail=NULL;
    while (l1!=NULL&&l2!=NULL)
    {
        p=new struct list[sizeof(list)];
        if (l1->num>=l2->num)
        {
            p->num=l2->num;
             l2=l2->next;
        }
        else
        {
            p->num=l1->num;
            l1=l1->next;
        }
        p->next=NULL;
        if (head==NULL)
        {
            head=p;
        }
        else
        {
            tail->next=p;
        }
        tail=p;
    }
    if (l1==NULL)
    {
        tail->next=l2;
    }
    if (l2==NULL)
    {
        tail->next=l1;
    }
    return head;
}

void print_list(struct list *l)
{
    cout<<l->num;
    l=l->next;
    while (l!=NULL)
    {
        cout<<" "<<l->num;
        l=l->next;
    }
}


int main()
{
    int m;
    cin>>m;
    list *l1,*l2,*l;
    l1=add_node(m);
    int n;
    cin>>n;
    l2=add_node(n);
    l=hebin(l1,l2);
    print_list(l);
}