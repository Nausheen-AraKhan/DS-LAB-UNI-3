#include<iostream>
using namespace std;
int s[100];
int top=-1;
void push(int n)
{
    top++;
    s[top]=n;
}
int pop()
{
    int x=s[top];
    top--;
    return x;
}
int factorial(int n)
{
    int fact=1;
    while(n>1)
    {
        push(n);
        n--;
    }
    while(top!=-1)
    {
        fact*=pop();
    }
    return fact;
}
int main()
{
    int n,ans;
    cout<<"Enter a number:"<<endl;
    cin>>n;
    if(n<0)
    {
        cout<<"Factorial not defined!"<<endl;
    }
    else{
        ans=factorial(n);
        cout<<"Factorial= "<<ans<<endl;
    }
    return 0;
}
