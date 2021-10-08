#include "Binary_node.cpp"
#include "Binary_node.h"
#include<iostream>
#include<string>
using namespace std;

template <class Entry>
class Binary_tree {
public:
	Binary_tree();
	bool empty() const;
	void preorder();//前序历遍
	void inorder();//中序历遍
	void postorder();//后序历遍
	void Build_pre(string &str);
	void Build_post(string &str);
	int size() const;
	int height();
	void insert(Entry &new_node);
protected:
// Add auxiliary function prototypes here.
	void recursive_preorder(Binary_node<Entry> *sub_root);
	void recursive_inorder(Binary_node<Entry> *sub_root);
	void recursive_postorder(Binary_node<Entry> *sub_root);
	void build_preorder(Binary_node<Entry>* &sub_root,string &str,int &index);
	void build_postorder(Binary_node<Entry>* &sub_root,string &str,int &index);
	void dfs_height(Binary_node<Entry> *sub_root,int pre_deep);
	Binary_node<Entry> *root;  //二叉树的根节点
	int count;
	int heights[100];
	int maxheight;
};

template<class Entry>
Binary_tree<Entry>::Binary_tree()
{
    root=NULL;
	count=0;
	maxheight=0;
}

template<class Entry>
int Binary_tree<Entry>::size() const
{
	return count;
}

template<class Entry>
int Binary_tree<Entry>::height()
{
	dfs_height(root,0);
	return maxheight;
}

template<class Entry>
void Binary_tree<Entry>::dfs_height(Binary_node<Entry> *sub_root,int pre_deep)
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

template<class Entry>
bool Binary_tree<Entry>::empty() const
{
	return root==NULL;
}

template<class Entry>
void Binary_tree<Entry>::preorder()
{
	recursive_preorder(root);
}

template<class Entry>
void Binary_tree<Entry>::recursive_preorder(Binary_node<Entry>* sub_root)
{
	if (sub_root==NULL)
	{
		return;
	}
	cout<<sub_root->data<<" ";
	recursive_preorder(sub_root->left);
	recursive_preorder(sub_root->right);
}


template<class Entry>
void Binary_tree<Entry>::inorder()
{
	recursive_inorder(root);
}

template<class Entry>
void Binary_tree<Entry>::recursive_inorder(Binary_node<Entry>* sub_root)
{
	if (sub_root==NULL)
	{
		return;
	}
	recursive_inorder(sub_root->left);
	cout<<sub_root->data<<" ";
	recursive_inorder(sub_root->right);
}

template<class Entry>
void Binary_tree<Entry>::postorder()
{
	recursive_postorder(root);
}

template<class Entry>
void Binary_tree<Entry>::recursive_postorder(Binary_node<Entry>* sub_root)
{
	if (sub_root==NULL)
	{
		return;
	}
	recursive_postorder(sub_root->left);
	cout<<sub_root->data<<" ";
	recursive_postorder(sub_root->right);
}

template<class Entry>
void Binary_tree<Entry>::Build_pre(string &str)
{
	int index=0;
	build_preorder(root,str,index);
}

template<class Entry>
void Binary_tree<Entry>::build_preorder(Binary_node<Entry>* &sub_root,string &str,int &index)
{
    if (index<str.length())
	{
		if (str[index]=='#')
		{
			sub_root=NULL;
			return;
		}
		else
		{
			sub_root=new Binary_node<Entry>;
            sub_root->data=str[index];
			count++;
			build_preorder(sub_root->left,str,++index);
			build_preorder(sub_root->right,str,++index);
		}
	}
}

template<class Entry>
void Binary_tree<Entry>::Build_post(string &str)
{
	int index=str.length()-1;
	build_postorder(root,str,index);
}

template<class Entry>
void Binary_tree<Entry>::build_postorder(Binary_node<Entry>* &sub_root,string &str,int &index)
{
    if (index>=0)
	{
		if (str[index]=='#')
		{
			sub_root=NULL;
			return;
		}
		else
		{
			sub_root=new Binary_node<Entry>;
            sub_root->data=str[index];
			count++;
			build_postorder(sub_root->right,str,--index);
			build_postorder(sub_root->left,str,--index);
		}
	}
}



int main()
{
	Binary_tree<char>tree;
	string str;
	cin>>str;
	tree.Build_post(str);
	int h=tree.height();
	cout<<h<<endl;
}