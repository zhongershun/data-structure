#include<iostream>
#include<string>
using namespace std;

enum Error_code{success,fail};

// 构建一个结点
template<class entry>
struct Bino_node
{
    entry data;
    Bino_node *left;
    Bino_node *right;
    Bino_node();
    Bino_node(const entry &x);
};

template<class entry>
Bino_node<entry>::Bino_node()
{
    left=NULL;
    right=NULL;
}

template<class entry>
Bino_node<entry>::Bino_node(const entry &x)
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
    Error_code search(entry key);
    Error_code search_p(entry key);
    Error_code remove_node(Bino_node<entry>* &aroot);
    Bino_node<entry>* search_for_node(Bino_node<entry>* &aroot,entry key);
    void search_path(Bino_node<entry>* aroot,entry key);
//    void preorder();
    void inorder(Bino_node<entry>* aroot);
    void postorder(Bino_node<entry>* aroot);
//    void build_inorder();
//    void build_preorder();
    void build_postorder(Bino_node<entry>* &aroot,string &str,int &index);
};

template<class entry>
Bino_tree<entry>::Bino_tree()
{
    root=NULL;
    count=0;
}

template<class entry>
void Bino_tree<entry>::build_postorder(Bino_node<entry>* &aroot,string &str,int &index)
{
    if (index>=0)
    {
        if (str[index]=='#')
        {
            aroot=NULL;
        }
        else
        {
            aroot=new Bino_node<entry>;
            aroot->data=str[index];
            build_postorder(aroot->right,str,--index);
            build_postorder(aroot->left,str,--index);
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

template<class entry>
Error_code Bino_tree<entry>::search(entry key)
{
    Error_code result=success;
	Bino_node<entry> *found=search_for_node(root,key);
	if (found==NULL) result=fail;
	return result;
}

template<class entry>
Bino_node<entry>* Bino_tree<entry>::search_for_node(Bino_node<entry>* &aroot,entry key)
{
    if (aroot==NULL||aroot->data==key)
    {
        remove_node(aroot);
        return aroot;
    }
    else if (aroot->data<key)
    {
        return search_for_node(aroot->right,key);    
    }
    else
    {
        return search_for_node(aroot->left,key);
    }
}

template<class entry>
Error_code Bino_tree<entry>::search_p(entry key)
{
    search_path(root,key);
    return success;
}

template<class entry>
void Bino_tree<entry>::search_path(Bino_node<entry>* aroot,entry key)
{
    if (aroot->data==key)
    {
        cout<<aroot->data;
    }
    else if (aroot->data<key)
    {
        cout<<aroot->data<<" ";
        search_path(aroot->right,key);
    }
    else
    {
        cout<<aroot->data<<" ";
        search_path(aroot->left,key);
    }
}

template<class entry>
Error_code Bino_tree<entry>::remove_node(Bino_node<entry>* &aroot)
{
    if (aroot==NULL)
    {
        return fail;
    }
    Bino_node<entry>* to_delete=new Bino_node<entry>;
    to_delete=aroot;
    if (aroot->left==NULL&&aroot->right==NULL)
    {
        aroot=NULL;
    }
    else if (aroot->left==NULL)
    {
        aroot=aroot->right;
    }
    else if (aroot->right==NULL)
    {
        aroot=aroot->left;
    }
    else
    {
        to_delete=aroot->left;
        Bino_node<entry> *parent=aroot;
        while (to_delete->right!=NULL)
        {
            parent=to_delete;
            to_delete=to_delete->right;
        }
        aroot->data=to_delete->data;
        if (parent==aroot)
        {
            aroot->left=to_delete->left;
        }
        else
        {
            parent->right=to_delete->left;
        }
    }
    delete to_delete;
    return success;
}

template<class entry>
void Bino_tree<entry>::postorder(Bino_node<entry>* aroot)
{
    if (aroot==NULL)
    {
        return;
    }
    postorder(aroot->left);
    postorder(aroot->right);
    cout<<aroot->data<<" ";
}

int main()
{
    string str;
    char key;
    char tod;
    cin>>str;
    cin>>key>>tod;
    int index=str.length();
    Bino_node<char> *node=NULL;
    Bino_tree<char> tree;
    tree.build_postorder(node,str,--index);//build之后root和node都指向了第一个节点
    tree.search_p(key);
    tree.search(tod);
    cout<<endl;
    tree.inorder(node);
}