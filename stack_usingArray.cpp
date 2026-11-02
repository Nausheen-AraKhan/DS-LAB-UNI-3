#include<iostream>
using namespace std;
#define SIZE 7
class Stack
{
   public:
   int top;
    int a[SIZE]; 
    public:
    Stack()
    {
        top=-1;
    }
    int isEmpty()
    {
        if(top==-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int isFull()
    {
        if(top==SIZE-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void push(int x)
    {
        if(isFull())
        {
            cout<<"Stack Overflow"<<endl;
        }
        else
        {
            top++;
            a[top]=x;
            cout<<"Element Pushed!"<<endl;
        }
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"Stack UnderFlow"<<endl;
        }
        else
        {
            cout<<"Element Popped!"<<endl;
            top--;
        }
    }
    void display()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty!"<<endl;
        }
        else
        {
            cout<<"Stack elements are:"<<endl;
            for(int i=top;i>=0;i--)
            {
                cout<<a[i]<<endl;
            }
        }
    }
};
int main()
{
    Stack s;
    int choice, x;
    do
    {
        cout<<"\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter element to push: ";
                cin>>x;
                s.push(x);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.display();
                break;
            case 4:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice! Please try again."<<endl;
        }
    }while(choice!=4);
    return 0;
}
