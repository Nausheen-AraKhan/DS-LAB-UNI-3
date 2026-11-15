#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
Node* createCircularLL(int n)
{
    Node* first=NULL;
    Node* cur;
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            cur=new Node;
            first=cur;
        }else
        {
            cur->next=new Node;
            cur=cur->next;
        }
        cout<<"Enter data:"<<endl;
        cin>>cur->data;
    }
    cur->next=first; 
    return first;
}
int main()
{
    int n;
    cout<<"Enter Number of nodes:"<<endl;
    cin>>n;
    Node* first=createCircularLL(n);
    Node* cur=first;
    cout<<"The circular linked list is:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<cur->data<<"->";
        cur=cur->next;
    }
    cout<<cur->data<<endl;
    return 0;
}
