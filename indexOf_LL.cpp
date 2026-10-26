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
    int index_of(int x)
    {
        int index=0;
        Node* cur=first;
        while(cur!=NULL && cur->data!=x)
        {
            cur=cur->link;
            index++;
        }
        if(cur==NULL)
        {
            return -1;
        }
        else
        {
            return index;
        }
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
   cout<<"The linked list is:"<<endl;
    l.display();
    cout<<"Index of 30 is:"<<l.index_of(30)<<endl;
    cout<<"Index of 100 is:"<<l.index_of(100)<<endl;
    return 0;
}
