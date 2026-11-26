#include<iostream>
using namespace std;
int a[100];
int n;
void build(int i)
{
    if(i==0)
    {
        cout<<"Enter root node: ";
    }
    else if(i%2==1)
    {
        cout<<"Enter left child of "<<a[(i-1)/2]<<":";
    }
    else
    {
        cout<<"Enter the right child of "<<a[(i-1)/2]<<":";
    }
    cin>>a[i];
    char ans;
    cout<<"Does "<<a[i]<<" have left child (Y/y)? ";
    cin>>ans;
    if((ans=='Y' || ans=='y') && (2*i+1<n))
    {
        build(2*i+1);
    }
    cout<<"Does "<<a[i]<<" have right child (Y/y)?";
    cin>>ans;
    if((ans=='Y' || ans=='y') && (2*i+2<n))
    {
        build(2*i+2);
    }
}
void preorder(int i)
{
    if(a[i]!='\0')
    {
        cout<<a[i]<<" ";
    }
    if(2*i+1<n && a[2*i+1]!='\0')
    {
        preorder(2*i+1);
    }
    if(2*i+2<n && a[2*i+2]!='\0')
    {
        preorder(2*i+2);
    }
}
int main()
{
    int h;
    cout<<"Enter height of binary tree: "<<endl;
    cin>>h;
    n=pow(2,h)-1;
    for(int i=0;i<n;i++)
    {
        a[i]='\0';
    }
    build(0);
    cout<<"\nPreordr Traversal: ";
    preorder(0);
    return 0;
}
