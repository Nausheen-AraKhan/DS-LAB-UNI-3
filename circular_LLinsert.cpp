
#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
};

node *first=NULL;

node* createCLL(int n)
{
    node *cur;

    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            cur=new node;
            first=cur;
        }
        else
        {
            cur->next=new node;
            cur=cur->next;
        }

        cout<<"Enter data:";
        cin>>cur->data;
    }

    cur->next=first;

    return first;
}

int sizeCLL(node *first)
{
    int count=1;
    node *cur=first;

    if(first==NULL)
        return 0;

    while(cur->next!=first)
    {
        count++;
        cur=cur->next;
    }

    return count;
}

void insertCLL(int x,int index)
{
    node *temp=new node;
    temp->data=x;

    if(first==NULL)
    {
        temp->next=temp;
        first=temp;
        return;
    }

    if(index<0 || index>sizeCLL(first))
    {
        cout<<"Invalid Index!"<<endl;
        delete temp;
        return;
    }

    if(index==0)
    {
        node *cur=first;

        while(cur->next!=first)
        {
            cur=cur->next;
        }

        temp->next=first;
        cur->next=temp;
        first=temp;
        return;
    }

    node *cur=first;

    for(int i=1;i<index;i++)
    {
        cur=cur->next;
    }

    temp->next=cur->next;
    cur->next=temp;
}

void displayCLL()
{
    if(first==NULL)
        return;

    node *cur=first;

    do
    {
        cout<<cur->data<<"->";
        cur=cur->next;
    }
    while(cur!=first);

    cout<<"(back to first)";
}

int main()
{
    int n;

    cout<<"Enter number of nodes:";
    cin>>n;

    if(n<=0)
        return 0;

    createCLL(n);

    cout<<"\nThe circular linked list:\n";
    displayCLL();

    insertCLL(90,3);
    insertCLL(45,6);

    cout<<"\n\nAfter insertion:\n";
    displayCLL();
    return 0;
}
