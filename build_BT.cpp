#include<iostream>
using namespace std;
int a[100],n;
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
int main()
{
    int h;
    cout<<"Enter heigth of binary tree:"<<endl;
    cin>>h;
    n=pow(2,h)-1;
    build(0);
    for(int i=0;i<n;i++)
    {
        cout<<"Index "<<i<<":"<<a[i]<<endl;
    }
    return 0;
}
