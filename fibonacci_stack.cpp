#include<iostream>
using namespace std;
int s[100];
int top=-1;
void push(int x)
{
    top++;
    s[top]=x;
}
int pop()
{
    int x=s[top];
    top--;
    return x;
}
int fibonacci(int n)
{
    int fib=0;
    push(n);
    while(top!=-1)
    {
        n=pop();
        if(n>2)
        {
            push(n-1);
            push(n-1);
        }
        else if(n==1 || n==2)
        {
            fib++;
        }
    }
    return fib;
}
int main()
{
    int n;
    cout<<"Enter n:\n";
    cin>>n;
    if(n<1)
    {
        cout<<"Enter a positive number!"<<endl;
    }
    else{
        cout<<"Fibonacci= "<<fibonacci(n)<<endl;
    }
    return 0;
}
