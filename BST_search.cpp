#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
};
Node *create(int x)
{
    Node *temp=new Node;
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
Node *insert(Node *root,int x)
{
    if(root==NULL)
        return create(x);
    if(x<root->data)
        root->left=insert(root->left,x);
    else if(x>root->data)
        root->right=insert(root->right,x);
    return root;
}
Node *search(Node *root,int x)
{
    Node *r=root;
    bool flag=false;
    while(r!=NULL && flag==false)
    {
        if(x==r->data)
        {
            flag=true;
        }
        else if(x<r->data)
        {
            r=r->left;
        }
        else if(x>r->data)
        {
            r=r->right;
        }
    }
    if(flag==true)
    {
        cout<<x<<" has been found at node "<<r;
        return r;
    }
    else
    {
        cout<<x<<" does not exist. Search Failed!";
        return NULL;
    }
}
int main()
{
    Node *root=NULL;
    int n,x,key;
    cout<<"Enter number of nodes:"<<endl;
    cin>>n;
    cout<<"Enter BST elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        root=insert(root,x);
    }
    cout<<"\nEnter element to search:\n";
    cin>>key;
    Node *result=search(root,key);
    return 0;
}
