#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* link;
    Node(int val)
    {
        data=val;
        link=NULL;
    }
};
class LL
{
    Node* first;
    int count;
    public:
    LL()
    {
        first=NULL;
        count=0;
    }
    void insert(int val)
    {
        Node* newNode=new Node(val);
        if(first==NULL)
        {
            first=newNode;
        }
        else
        {
            Node* temp=first;
            while(temp->link!=NULL)
            {
                temp=temp->link;
            }
            temp->link=newNode;
        }
        count++;
    }
    void del(int index)
    {
        if(count==0)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        if(index<0 || index>=count)
        {
            cout<<"Invalid index"<<endl;
            return; 
        }
        Node* delnode;
        int x;
        if(index==0)
        {
            x=first->data;
            delnode=first;
            first=first->link;
        }
        else
        {
            Node* prev=first;
            for(int i=1;i<index;i++)
            {
                prev=prev->link;
            }
            delnode=prev->link;
            x=delnode->data;
            prev->link=delnode->link;
        }
        delete delnode;
        count--;
    }
    void display()
    {
        Node* temp=first;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->link;
        }
        cout<<"NULL"<<endl;
    }
};
int main()
{
    LL l;
    l.insert(10);
    l.insert(20);
    l.insert(30);
    l.insert(40);
    l.insert(50);
    l.insert(60);
    l.insert(70);
    cout<<"Linked List before deletion:"<<endl;
    l.display();
    l.del(3);
    cout<<"Linked List after deletion:"<<endl;
    l.display();
    return 0;
}
