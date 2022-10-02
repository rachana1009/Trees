#include<bits/stdc++.h>
#include <stdio.h>
using namespace std;

class TreeNode
{
    public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeeNode()
    {
        value=0;
        left=NULL;
        right=NULL;
    }

    TreeNode(int v)
    {
        value=v;
        left=NULL;
        right=NULL;
    }
};

class BST
{
    TreeNode*root=NULL;
    BST()
    {
        root=NULL;
    }

    void insertion(TreeNode* nnode)
    {
        if(root==NULL)
        {
        root=nnode;
        cout<<"Value inserted as root node."<<endl;
        }
        else
        {
            TreeNode*temp=root;
            while(temp!=NULL)
            {
                if((nnode->value<temp->value) && (temp->left==NULL))
                {
                    temp->left=nnode;
                    break;
                }
                else if(nnode->value<temp->value)
                temp=temp->left;
                else if((nnode->value>temp->value)&&(temp->right==NULL))
                {
                    temp->right=nnode;
                    break;
                }
                else
                temp=temp->right;

            }
        }
    }

    void print2D(TreeNode*r, int space)
    {
        if(r==NULL)
        return;
        space+=10;
        print2D(r->right,space);
        cout<<endl;
        for(int i=10;i<space;i++)
        cout<<" ";
        cout<<r->value<<"\n";
        print2D(r->left,space);
    }
};

int main()
{
    BST obj;
    int val;
    TreeNode* nnode=new TreeNode();
    cout<<"Enter the value u want to enter:";
    cin>>val;
    nnode->value=val;
}
