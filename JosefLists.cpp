#include<iostream>
using namespace std;

struct JosefList
{
    int num;
    struct JosefList *next;
    JosefList();
    JosefList(int i,struct JosefList *add);

}List;

JosefList::JosefList()
{
    next=NULL;
}//初始我的链表

JosefList::JosefList(int i,struct JosefList *add)
{
    num=i;
    next=add;
}//申明链表的结构


struct JosefList *add_node(int n,struct JosefList *tail)
{
    struct JosefList *head,*p;
    int i=1;
    head=tail=NULL;
    while (n)
    {
        p=new struct JosefList[sizeof(JosefList)];
        p->num=i;
        if (head==NULL)
        {
            head=p;
            p->next=p;
        }
        else
        {
            tail->next=p;
            p->next=head;
        }
        tail=p;
        n--;
        i++;
    }
    return head;
}//实现节点的加入


int Del_node(int m,struct JosefList *head)
{
    struct JosefList *prv,*cur,*p;
        int temp=0; 
        for(prv=NULL,cur=head;head->next!=head;)
        {
            bool flag=false;
            temp++;//利用temp来表示每个人报的数
            if (temp%m==0)
            {
                flag=true;
                if (cur==head)
                {
                    head=head->next;
                    prv->next=head;
                    p=cur;
                }
                else
                {
                    prv->next=cur->next;
                    p=cur;
                }
            }
            prv=cur;
            cur=cur->next;
            if (flag)
            {
                delete p;
                p=NULL;
            }
            
        }
    return head->num;
}

int main()
{
    int n,m,result;
    cin>>n>>m;
    struct JosefList *head,*tail;
    head=add_node(n,tail);
    result=Del_node(m,head);
    cout<<result<<endl;
    return 0;
}