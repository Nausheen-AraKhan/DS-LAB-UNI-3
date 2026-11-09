#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
class LinkedList
{
    Node *head,*tail;
    public:
    LinkedList()
    {
        head=NULL;
        tail=NULL;
    }
    int isEmpty()
    {
        return head==NULL;
    }
    void insert(int x)
    {
        Node *newNode=new Node;
        newNode->data=x;
        newNode->next=NULL;
        if(head==NULL)
        {
            head=tail=newNode;
        }
        else
        {
            tail->next=newNode;
            tail=newNode;
        }
    }
    int del()
    {
        Node *temp;
        int x;
        temp=head;
        x=temp->data;
        head=head->next;
        if(head==NULL)
        {
            tail=NULL;
        }
        delete temp;
        return x;
    }
};
void radixSort(int a[],int n)
{
    int maxnum=a[0];
    int i,j,k;
    int temp,digits=0;
    int place=1;
    for(i=1;i<n;i++)
    {
        if(a[i]>maxnum)
        {
            maxnum=a[i];
        }
    }
    temp=maxnum;
    do
    {
        digits++;
        temp/=10;
    }while(temp>0);
    LinkedList L[10];
    for(k=1;k<=digits;k++)
    {
        for(i=0;i<n;i++)
        {
            j=(a[i]/place)%10;
            L[j].insert(a[i]);
        }
        i=0;
        for(j=0;j<10;j++)
        {
            while(L[j].isEmpty()==0)
            {
                a[i]=L[j].del();
                i++;
            }
        }
        place*=10;
    }
}
int main()
{
    int a[100],n,i;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    radixSort(a,n);
    cout<<"\nSorted elements: ";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
