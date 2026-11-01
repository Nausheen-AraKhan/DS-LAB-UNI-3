#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *link;
};
class LinkedList
{
    Node* first;
    public:
    LinkedList()
    {
        first=NULL;
    }
    void insert(int x,int index)
    {
        Node* temp=new Node;
        temp->data=x;
        if(index==0)
        {
            temp->link=first;
            first=temp;
        }
    }
    int isEmpty()
    {
        return (first==NULL);
    }
    int size()
    {
        int count=0;
        Node* cur=first;
        while(cur!=NULL)
        {
            count++;
            cur=cur->link;
        }
        return count;
    }
    int del(int index)
    {
        Node* cur=first;
        Node* prev=NULL;
        int count=0;
        while(count<index)
        {
            prev=cur;
            cur=cur->link;
            count++;
        }
        int x=cur->data;
        if(prev==NULL)
        {
            first=cur->link;
        }
        else
        {
            prev->link=cur->link;
        }
        delete cur;
        return x;
    }
};
void bucketsort(int a[],int n)
{
    int min=a[0],max=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]<min)
           min=a[i];
        if(a[i]>max)
           max=a[i];
    }
    int x=0;
    if(min<0)
    {
        x=-min;
    }
    for(int i=0;i<n;i++)
    {
        a[i]+=x;
    }
    max+=x;
    LinkedList L[max+1];
    for(int i=0;i<n;i++)
    {
        L[a[i]].insert(a[i],0);
    }
    int i=0;
    for(int j=0;j<=max;j++)
    {
        while(L[j].isEmpty()==0)
        {
            a[i]=L[j].del(L[j].size()-1);
            i++;
        }
    }
    for(int i=0;i<n;i++)
    {
        a[i]-=x;
    }
}
int main()
{
    int a[5]={-5,0,2,-1,3};
    bucketsort(a,5);
    cout<<"Sorted Array is: ";
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
