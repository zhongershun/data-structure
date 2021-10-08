#include<iostream>
#include<string>
using namespace std;
typedef struct Binary_node{//数据成员：
    char data;
    struct Binary_node *left;
    struct Binary_node *right;
//constructors:
    Binary_node();
    Binary_node(const char &x);
}Binary_node;
//初始化二叉树
Binary_node::Binary_node()
{
    left=nullptr;
    right=nullptr;
}
Binary_node::Binary_node(const char &x)
{
    data=x;
    left = nullptr;
    right = nullptr;
}
class Binary_tree{
public:
    bool empty( ) const;
    void preorder(void (*visit)(char &));
    void inorder(Binary_node *Root);
    void postorder(void (*visit)(char &));
    int size( ) const;
    int height( ) const;
    void insert(char &);
    Binary_node * Root;
    Binary_node * Tree_Build(Binary_node * (&Root),string input,int &index);
    Binary_node * path_find(Binary_node *Root,char target);
    void recursive_inorder(Binary_node *Root);
    Binary_node * node_deletion(Binary_node *&Root , char target);
    Binary_node * min_path(Binary_node *Root);
protected:
    void recursive_preorder(Binary_node *sub_root, void (*visit)(char &));
    
    void recursive_postorder(Binary_node *sub_root, void (*visit)(char &));
    int count;
};
Binary_node * Binary_tree::min_path(Binary_node *Root)
{
    if (!Root)
    {
        return nullptr;
    }
    else if (!Root->left)
    {
        return Root;
    }
    else
    {
        return min_path(Root -> left);
    }
}
Binary_node * Binary_tree::Tree_Build(Binary_node * (&Root),string input,int &index)
{
    //从后序遍历建立二叉树
    if (index>=0)
    {
        if (input[index]=='#')
        {
            Root = nullptr;
        }
        else
        {
            Root = new Binary_node;
            Root -> data = input[index];
            Tree_Build(Root->right, input, --index);
            Tree_Build(Root->left, input, --index);
        }
    }
    return Root;
}
void Binary_tree::inorder(Binary_node *Root)
{
    recursive_inorder(Root);
}
void Binary_tree::recursive_inorder(Binary_node *Root)
{
    if (Root!=nullptr)
    {
        recursive_inorder(Root->left);
        cout << Root -> data << " ";
        recursive_inorder(Root->right);
    }
}
Binary_node* Binary_tree::path_find(Binary_node *Root,char target)
{
    if (Root != nullptr)
    {
        if (Root ->data == target)
        {
            cout << Root -> data<< endl;
            return Root;
        }
        else
        {
            cout << Root -> data << " ";
            if (target < Root -> data)
            {
                return path_find(Root->left,target);
            }
            else
            {
                return path_find(Root->right,target);
            }
        }
    }
    return nullptr;
}
Binary_node *Binary_tree::node_deletion(Binary_node *&Root , char target)
{
    Binary_node *temp;
    if (Root)
    {
        if (Root -> data > target)
        {
            node_deletion(Root->left,target);
        }
        else if (Root -> data < target)
        {
            node_deletion(Root->right,target);
        }
        else
        {
            if (Root->left&&Root->right)
            {
                temp = min_path(Root -> right);
                Root -> data =temp -> data;
                Root -> right = node_deletion (Root -> right, Root -> data);
            }
            else
            {
                temp = Root;
                if (!Root->left)
                {
                    Root=Root->right;
                }
                else
                {
                    Root=Root->left;
                }
                delete temp;
            }
        }
    }
    return Root;
}
int main(void)
{
    Binary_tree Binary_tree;
    Binary_node *Root;
    Root=nullptr;
    string input;
    cin >> input;
    char a,b;
    cin >> a >> b;
    int index=0;
    while (input[index]){
        index++;
    }
    index--;
    Root = Binary_tree.Tree_Build(Root,input,index);
    Binary_tree.path_find(Root,a);
    Root = Binary_tree.node_deletion(Root,b);
    Binary_tree.recursive_inorder(Root);
    cout << endl;
    return 0;
}
