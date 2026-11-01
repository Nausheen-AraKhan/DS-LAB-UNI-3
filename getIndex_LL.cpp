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
    int size()
    {
        return count;
    }
    int get(int index)
    {
        if(index<0 || index>=size())
        {
            cout<<"Invalid index"<<endl;
            return -1;
        }
        Node* cur=first;
        for(int i=0;i<index;i++)
        {
            cur=cur->link;
        }
        return cur->data;
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
    cout<<"Value at index 2 is:"<<l.get(2)<<endl;
    cout<<"Value at index 5 is:"<<l.get(5)<<endl;
    cout<<"Value at index 7 is:"<<l.get(7)<<endl;
    return 0;
}
