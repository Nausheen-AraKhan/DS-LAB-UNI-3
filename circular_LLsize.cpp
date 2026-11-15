#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
int size(Node* first)
{
    int count=1;
    Node* cur=first;
    if(first==NULL)
    {
        return 0;
    }
    while(cur->next!=first)
    {
        count++;
        cur=cur->next;
    }
    return count;
}
int main()
{
    int n;
    cout<<"Enter number of nodes:"<<endl;
    cin>>n;
    Node* first=NULL;
    Node* cur;
    for(int i=1;i<=n;i++)
    {
        Node* temp=new Node();
        cout<<"Enter data:"<<endl;
        cin>>temp->data;
        if(first==NULL)
        {
            first=temp;
            cur=first;
        }
        else
        {
            cur->next=temp;
            cur=cur->next;
        }
    }
    cur->next=first; 
    cout<<"The size of circular linked list is:"<<size(first)<<endl;
    return 0;
}
