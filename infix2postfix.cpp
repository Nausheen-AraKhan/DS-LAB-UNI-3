#include<iostream>
using namespace std;
class Stack
{
    char arr[100];
    int top;
    public:
    Stack()
    {
        top=-1;
    }
    void push(char x)
    {
        arr[++top]=x;
    }
    char pop()
    {
        return arr[top--];
    }
    char peek()
    {
        return arr[top];
    }
    int isEmpty()
    {
        return top==-1;
    }
};
int precedence(char x)
{
    if(x=='*'||x=='/')
    {
        return 2;
    }
    else if(x=='+'||x=='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void infix2postfix(char infix[],char postfix[])
{
    Stack s;
    int i=0,j=0;
    s.push('(');
    strcat(infix,")");
    while(infix[i]!='\0')
    {
        char x=infix[i];
        if(x==' ')
        {
            i++;
        }
        else if(isdigit(x))
        {
            while(isdigit(infix[i]))
            {
                postfix[j++]=infix[i++];
            }
            postfix[j++]=' ';
        }
        else if(x=='(')
        {
            s.push(x);
            i++;
        }
        else if(x==')')
        {
            while(s.peek()!='(')
            {
                postfix[j++]=s.pop();
                postfix[j++]=' ';
            }
            s.pop();
            i++;
        }
        else if(x=='+'||x=='-'||x=='*'||x=='/')
        {
            while(precedence(s.peek())>=precedence(x))
            {
                postfix[j++]=s.pop();
                postfix[j++]=' ';
            }
            s.push(x);
            i++;
        }
        else
        {
            cout<<"Invalid character in infix expression"<<endl;
            return;
        }
    }
    postfix[j]='\0';
}
int main()
{
    char infix[100],postfix[100];
    cout<<"Enter infix expression: ";
    cin.getline(infix,100);
    infix2postfix(infix,postfix);
    cout<<"Postfix expression: "<<postfix<<endl;
    return 0;
}
