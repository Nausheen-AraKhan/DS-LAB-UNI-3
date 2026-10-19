#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* link;
};
Node* first=NULL;
void insert(int x,int index)
{
    Node *newNode,*prev;
    newNode=new Node;
    newNode->data=x;
    newNode->link=NULL;
    if(index==0)
    {
        newNode->link=first;
        first=newNode;
    }
    else
    {
        prev=first;
        for(int i=1;i<index;i++)
        {
            prev=prev->link;
        }
        newNode->link=prev->link;
        prev->link=newNode;
    }
}
int main()
{
    Node *cur;
    int n,x,index;
    cout<<"Enter number of nodes:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cur=new Node;
        cout<<"Enter data:"<<endl;
        cin>>cur->data;
        cur->link=NULL;
        if(first==NULL)
           first=cur;
        else
        {
            Node *temp=first;
            while(temp->link!=NULL)
            {
                temp=temp->link;
            }
            temp->link=cur;
        }
    }
    cout<<"Enter data to be inserted:"<<endl;
    cin>>x;
    cout<<"Enter index at which data is to be inserted:"<<endl;
    cin>>index;
    if(index<0)
    {
        cout<<"Invalid index"<<endl;
    }
    else
    {
        cur=first;
        int count=0;
        while(cur!=NULL)
        {
            count++;
            cur=cur->link;
        }
        if(index>count)
        {
            cout<<"Invalid index"<<endl;
        }
        else
        {
            insert(x,index);
            cout<<"The linked list after insertion is:"<<endl;
            cur=first;
            while(cur!=NULL)
            {
                cout<<cur->data<<"->";
                cur=cur->link;
            }
            cout<<"NULL"<<endl;
        }
    }
    return 0;
}
