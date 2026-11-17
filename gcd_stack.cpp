#include<iostream>
using namespace std;
int s1[100],s2[100];
int top1=-1,top2=-1;
void push1(int x)
{
    top1++;
    s1[top1]=x;
}
void push2(int x)
{
    top2++;
    s2[top2]=x;
}
int pop1()
{
    int x=s1[top1];
    top1--;
    return x;
}
int pop2()
{
    int x=s2[top2];
    top2--;
    return x;
}
int gcd(int m,int n)
{
    push1(m);
    push2(n);
    while(top1!=-1)
    {
        m=pop1();
        n=pop2();
        if(m%n!=0)
        {
            push1(n);
            push2(m%n);
        }
    }
    return n;
}
int main()
{
    int m,n;
    cout<<"Enter two numbers:"<<endl;
    cin>>m>>n;
    if(m<=0 || n<=0)
    {
        cout<<"Enter Positive numbers!"<<endl;
    }
    else{
        cout<<"GCD= "<<gcd(m,n);
    }
    return 0;
}
