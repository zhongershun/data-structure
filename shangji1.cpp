#include<iostream>
#include<string>
using namespace std;

int strlength;
int maxheight=0;
int heights[100]={};

// 构建一个结点
template<class entry>
struct Bino_node
{
    int data;
    Bino_node *left;
    Bino_node *right;
    Bino_node();
    Bino_node(const int &x);
};

template<class entry>
Bino_node<entry>::Bino_node()
{
    left=NULL;
    right=NULL;
}

template<class entry>
Bino_node<entry>::Bino_node(const int &x)
{
    data=x;
    left=NULL;
    right=NULL;
}

template<class entry>
class Bino_tree
{
private:
    Bino_node<entry> *root;
    int count;
public:
    Bino_tree();
    void inorder(Bino_node<entry>* aroot);
    void postorder(Bino_node<entry>* aroot);
    void build_preorder(Bino_node<entry>* &aroot,string str[],int &index);
};

template<class entry>
Bino_tree<entry>::Bino_tree()
{
    root=NULL;
    count=0;
    maxheight=0;
}

template<class entry>
void Bino_tree<entry>::build_preorder(Bino_node<entry>* &aroot,string str[],int &index)
{
    if (index<strlength)
    {
        if (str[index]=="#")
        {
            aroot=NULL;
            return;
        }
        else
        {
            aroot=new Bino_node<entry>;
            aroot->data=atoi(str[index].c_str());
            build_preorder(aroot->left,str,++index);
            build_preorder(aroot->right,str,++index);
        }
    }
    root=aroot;
}

template<class entry>
void Bino_tree<entry>::inorder(Bino_node<entry>* aroot)
{
    if (aroot==NULL||aroot->data==0)
    {
        return;
    }
    inorder(aroot->left);
    cout<<aroot->data<<" ";
    inorder(aroot->right);
}

// 完成平衡二叉树判断
template<class entry>
int height(Bino_node<entry> *root)
{
    maxheight=0;
    heights[100]={0};
	dfs_height(root,0);
	return maxheight;
}

template<class entry>
void dfs_height(Bino_node<entry> *sub_root,int pre_deep)
{
	if (sub_root==NULL)
	{
		if (pre_deep>maxheight)
		{
			maxheight=pre_deep;
		}
		return;
	}
    heights[sub_root->data]=pre_deep+1;
	dfs_height(sub_root->right,heights[sub_root->data]);
	dfs_height(sub_root->left,heights[sub_root->data]);
}

template<class entry>
bool avl(Bino_node<entry>* node)
{
    bool can=false;
        Bino_node<entry> *nodel=node->left;
        Bino_node<entry> *noder=node->right;
        int hl=height(nodel);
        int hr=height(noder);
        if ((hl-hr)>=-1&&(hl-hr)<=1)
        {
            can=true;
        }
        return can;
}

template<class entry>
void postorder(Bino_node<entry>* aroot,bool &can)
{
    if (aroot==NULL)
    {
        return;
    }
    if (!avl(aroot))
    {
        can=false;
        return;
    }
    postorder(aroot->left,can);
    postorder(aroot->right,can);
    
}

int main()
{
    // string str;
    string str[100];
    cin>>strlength;
    for (int i = 0; i < strlength; i++)
    {
        cin>>str[i];
    }
    int index=0;
    Bino_node<string> *node=NULL;
    Bino_tree<string> tree;
    tree.build_preorder(node,str,index);//build之后root和node都指向了第一个节点
    bool can=true;
    postorder(node,can);
    if (can)
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }

}

