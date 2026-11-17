#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* Rlink;
    Node* Llink;
};
Node *first=NULL;
void create(int n)
{
    Node *cur,*prev;
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            first=new Node;
            cur=first;
            cur->Llink=NULL;
        }
        else
        {
            prev=cur;
            cur->Rlink=new Node;
            cur=cur->Rlink;
            cur->Llink=prev;
        }
        cout<<"Enter data: ";
        cin>>cur->data;
    }
    cur->Rlink=first;
    first->Llink=cur;
}
void display()
{
    if(first==NULL)
    {
        return;
    }
    Node *temp=first;
    do{
        cout<<temp->data<<" ";
        temp=temp->Rlink;
    }while(temp!=first);
}
int main()
{
    int n;
    cout<<"Enter number of nodes"<<endl;
    cin>>n;
    if(n<=0)
    {
        cout<<"Invalid number of nodes!"<<endl;
        return 0;
    }
    create(n);
    cout<<"Doubly Circular Linked List: "<<endl;
    display();
    return 0;
}
