#include<iostream>
using namespace std;
int q[100];
int front=-1,rear=-1;
bool isEmpty()
{
    return (front==-1);
}
int size()
{
    if(isEmpty())
    {
        return 0;
    }
    return rear-front+1;
}
void insert(int x)
{
    if(rear==99)
    {
        cout<<"Queue Overflow!"<<endl;
    }
    else if(rear==-1)
    {
        rear=0;
        front=0;
    }
    else{
        rear++;
    }
    q[rear]=x;
    cout<<x<<" Inserted!"<<endl;
}
void del()
{
    if(isEmpty())
    {
        cout<<"Queue Underflow!"<<endl;
    }
    if(front==rear)
    {
        rear=-1;
        front=rear;
    }
    else{
        front++;
    }
}
void display()
{
    if(isEmpty())
    {
        cout<<"Queue is empty!"<<endl;
    }
    else
    {
        cout<<"Queue Elements:"<<endl;
        for(int i=front;i<=rear;i++)
        {
            cout<<q[i]<<" ";
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
