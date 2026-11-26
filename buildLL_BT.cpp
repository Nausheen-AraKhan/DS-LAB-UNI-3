#include<iostream>
using namespace std;
class Node
{
    public:
    char data;
    Node *left;
    Node *right;
};
Node *createNode()
{
    Node *temp=new Node;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void build(Node *&r,Node *p)
{
    if(r==NULL)
    {
        r=createNode();
        if(p==NULL)
        {
            cout<<"Enter Root Node: ";
        }
        else if(r==p->left)
        {
            cout<<"Enter left child of "<<p->data<<":";
        }
        else
        {
            cout<<"Enter right child of "<<p->data<<":";
        }
    }
    cin>>r->data;
    char ans;
    cout<<"Does "<<r->data<<" have left child (Y/y)?";
    cin>>ans;
    if(ans=='Y'||ans=='y')
    {
        r->left=createNode();
        build(r->left,r);
    }
    cout<<"Does "<<r->data<<" have right child (Y/y)?";
    cin>>ans;
    if(ans=='Y'||ans=='y')
    {
        r->right=createNode();
        build(r->right,r);
    }
}
void preorder(Node *r)
{
    if(r!=NULL)
    {
        cout<<r->data<<" ";
        preorder(r->left);
        preorder(r->right);
    }
}
void inorder(Node *r)
{
    if(r!=NULL)
    {
        inorder(r->left);
        cout<<r->data<<" ";
        inorder(r->left);
    }
}
void postorder(Node *r)
{
    if(r!=NULL)
    {
        postorder(r->left);
        postorder(r->right);
        cout<<r->data<<" ";
    }
}
void levelorder(Node *r)
{
    if(r==NULL)
    {
        return;
    }
    queue<Node*>q;
    q.push(r);
    while(!q.empty())
    {
        Node *temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
    }
}
int main()
{
    Node *root=NULL;
    build(root,NULL);
    cout<<"\nPreorder Traversal: ";
    preorder(root);
    cout<<"\nInorder Traversal: ";
    inorder(root);
    cout<<"\nPostOrder Traversal: ";
    postorder(root);
    cout<<"Level Order Traversal: ";
    levelorder(root);
    return 0;
}
