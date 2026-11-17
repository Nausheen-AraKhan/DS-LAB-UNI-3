#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
};
Node* front=NULL;
Node* rear=NULL;
bool isEmpty()
{
    return (front==NULL);
}
int size()
{
    Node* temp=front;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
void insert(int x)
{
    Node* newnode=new Node;
    newnode->data=x;
    newnode->next=NULL;
    if(isEmpty())
    {
        rear=newnode;
        front=rear;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
    cout<<x<<" Inserted"<<endl;
}
void del()
{
    if(isEmpty())
    {
        cout<<"Queue underflow!"<<endl;
    }
    else
    {
        Node* temp=front;
        cout<<"Deleted Element: "<<front->data<<endl;
        front=front->next;
        if(front==NULL)
            rear=NULL;
        delete temp;
    }
}
void display()
{
    if(isEmpty())
    {
        cout<<"Queue is Empty!"<<endl;
    }
    else
    {
        Node* temp=front;
        cout<<"Queue Elements:"<<endl;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}
int main()
{
    int choice,x;
    do{
        cout<<"\n1. Insert"<<endl;
        cout<<"2. Delete"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Empty"<<endl;
        cout<<"5. Size"<<endl;
        cout<<"\nEnter Your Choice:"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter element: "<<endl;
                cin>>x;
                insert(x);
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            case 4:
                if(isEmpty())
                {
                    cout<<"\nQueue is Empty!"<<endl;
                }
                else{
                    cout<<"Queue is not empty!"<<endl;
                }
                break;
            case 5:
                cout<<"Queue Size: "<<size()<<endl;
                break;
            default:
                cout<<"Invalid Choice!"<<endl;
        }
    }while(choice!=6);
    return 0;
}
