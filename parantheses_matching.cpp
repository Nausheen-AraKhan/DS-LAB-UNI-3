#include<iostream>
using namespace std;
class Stack
{
    int s[100];
    int top;
    public:
    Stack()
    {
        top=-1;
    }
    void push(char x)
    {
        top++;
        s[top]=x;
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        top--;
    }
    bool isEmpty()
    {
        if(top==-1)
        {
            return true;
        }
        return false;
    }
    bool isBalanced(char exp[])
    {
        for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
        {
            push(exp[i]);
        }
        else if(exp[i]==')')
        {
            if(isEmpty())
            {
                return false;
            }
            pop();
        }
    }
    return isEmpty();
}
};
int main()
{
   Stack s;
   char exp[100];
    cout<<"Enter the expression: ";
    cin>>exp;
    if(s.isBalanced(exp))
    {
        cout<<"The expression is balanced"<<endl;
    }
    else
    {
        cout<<"The expression is not balanced"<<endl;
    }
    return 0;
}
