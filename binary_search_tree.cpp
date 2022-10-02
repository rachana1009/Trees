#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define SPACE 10
class TreeNode
{
public:
    // data members
    int value;
    TreeNode *left;
    TreeNode *right;

    // Member Functions
    TreeNode()
    {
        value = 0;
        left = NULL;
        right = NULL;
    }

    TreeNode(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    // data Members
    TreeNode *root;

    // Member Functions

    BST()
    {
        root = NULL;
    }

    bool isTreeEmpty();
    void insertNode(TreeNode *nnode);
    void printPreorder(TreeNode *r);
    void printInorder(TreeNode *r);
    void printPostorder(TreeNode *r);
    void print2D(TreeNode *r, int space);
    void printLevelorder(TreeNode *r);
    int height(TreeNode*r);
    TreeNode *search(int val);
    TreeNode *minValueNode(TreeNode *node);
    TreeNode *deleteNode(TreeNode *r, int v);
};

bool BST::isTreeEmpty()
{
    if (root == NULL)
        return true;
    else
        return false;
}

void BST::insertNode(TreeNode *nnode)
{
    if (root == NULL)
    {
        root = nnode;
        cout<<"Vaue inserted as root node\n";
    }
    else
    {
        TreeNode *temp = new TreeNode;
        temp = root;
        while (temp != NULL)
        {
            if (nnode->value == temp->value)
            {
                cout << "Duplicate values not allowed.\n";
                break;
            }
            else if ((nnode->value < temp->value) && (temp->left == NULL))
            {
                temp->left = nnode;
                cout << "Value inserted at left\n";
                break;
            }
            else if (nnode->value < temp->value)
                temp = temp->left;
            else if ((nnode->value > temp->value) && (temp->right == NULL))
            {
                temp->right = nnode;
                cout << "Value inserted at right\n";
                break;
            }
            else
                temp = temp->right;
        }
    }
}

void BST::print2D(TreeNode *r, int space)
{
    if (r == NULL)
        return;
    space += SPACE;
    print2D(r->right, space);
    cout << endl;
    for (int i = SPACE; i < space; i++)
        cout << " ";
    cout << r->value << "\n";
    print2D(r->left, space);
}

void BST::printPreorder(TreeNode* r)
{
    if(r==NULL)
    return;
    cout<<r->value<<" ";
    printPreorder(r->left);
    printPreorder(r->right);
}

void BST::printInorder(TreeNode* r)
{
    if(r==NULL)
    return;
    printInorder(r->left);
    cout<<r->value<<" ";
    printInorder(r->right);
}

void BST::printPostorder(TreeNode* r)
{
    if(r==NULL)
    return;
    printPostorder(r->left);
    printPostorder(r->right);
    cout<<r->value<<" ";
}

TreeNode* BST::search(int val)
{
    if(root==NULL)
    return root;
    else
    {
        TreeNode* temp=root;
        while(temp!=NULL)
        {
            if(val==temp->value)
            return temp;
            else if(val<temp->value)
            temp=temp->left;
            else
            temp=temp->right;
        }

    }
    return NULL;
}

int BST:: height(TreeNode* r)
{
    if(r==NULL)
    return -1;
    else
    {
        int lheight=height(r->left);
        int rheight=height(r->right);
        if(lheight>rheight)
        return (lheight+1);
        else
        return (rheight+1);
    }
}

void printGivenLevel(TreeNode*r, int level)
{
    if(r==NULL)
    return;
    else if(level==0)
    cout<<r->value<<" ";
    else
    {
        printGivenLevel(r->left,level-1);
        printGivenLevel(r->right,level-1);
    }
}

void BST::printLevelorder(TreeNode* r)
{
    int h=height(r);
    for (int i=0;i<=h;i++)
    printGivenLevel(r,i);
}

TreeNode * BST::minValueNode(TreeNode *node)
{
    TreeNode* current=node;
    while(current->left!=NULL)
    current=current->left;
    return current;
}
TreeNode * BST::deleteNode(TreeNode *r, int v)
{
    if(r==NULL)
    return r;
    else if(v<r->value)
    r->left=deleteNode(r->left,v);
    else if(v>r->value)
    r->right=deleteNode(r->right,v);
    else
    {
        TreeNode*temp=new TreeNode();
        if(r->left==NULL)
        {
            temp=r->right;
            delete r;
            return temp;
        }
        else if(r->right==NULL)
        {
            temp=r->left;
            delete r;
            return temp;
        }
        else
        {
            temp=minValueNode(r->right);
            r->value=temp->value;
            r->right=deleteNode(r->right,temp->value);
        }
        return r;
    }
}

int main()
{
    BST obj;
    int option, val;

    do
    {
        cout << "\n  MENU" << endl;
        cout << "1. Is Tree Empty\n2. Insertion \n3. Print Preorder \n4. Print Inorder\n5. Print Postorder\n6. Print 2D\n7. Print Level Order\n8. Searching\n9. Minimum value node\n10. Delete Node\n11. Height of tree\n0. Exit";
        cout << "\nEnter your option:";
        cin >> option;
        TreeNode *nnode = new TreeNode;
        switch (option)
        {
        case 0:
            exit(0);
            break;
        // case 1:
        // bool ans=isTreeEmpty();
        // if(ans==1)
        // cout<<"Tree is empty\n";
        // else
        // cout<<"Tree is not empty"<<endl;
        // break;
        case 2:

            cout << "Enter value:";
            cin >> val;
            nnode->value = val;
            obj.insertNode(nnode);
        case 3:
            // void printPreorder(TreeNode * r);
            obj.printPreorder(obj.root);
            break;
        case 4:
            obj.printInorder(obj.root);
            break;
        case 5:
            obj.printPostorder(obj.root);
            break;
        case 6:
            // void print2D(TreeNode*r, int space);
            obj.print2D(obj.root,5);
            break;
        case 7:
            obj.printLevelorder(obj.root);
            break;
        case 8:
            cout<<"Enter the value you want to search:";
            cin>>val;
            nnode=obj.search(val);
            if(nnode!=NULL)
            cout<<val<<" is present in the tree.\n";
            else
            cout<<val<<" is not present in the tree.\n";
            break;
        case 9:
            obj.minValueNode(obj.root);
            break;
        case 10:
            cout<<"Enter the value you want to delete:";
            cin>>val;
            nnode=obj.search(val);
            if(nnode!=NULL)
            obj.deleteNode(obj.root,val);
            else
            cout<<"Value not present in the tree."<<endl;
            break;
        case 11:
            cout<<"Height: "<<obj.height(obj.root)<<endl;
            break;
        default:
            cout << "Incorrect Input!" << endl;
            exit(0);
        }

    } while (option != 0);
}
