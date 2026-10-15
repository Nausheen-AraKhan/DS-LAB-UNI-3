#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* link;
};
Node* create(int n)
{
    Node *first=NULL;
    Node *cur;
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            cur= new Node;
            first=cur;
        }
        else
        {
            cur->link=new Node;
            cur=cur->link;
        }
        cout<<"Enter data:"<<endl;
        cin>>cur->data;
    }
    cur->link=NULL;
    return first;
}
int main()
{
    int n;
    cout<<"Enter number of nodes:"<<endl;
    cin>>n;
    Node* first=create(n);
    Node* cur=first;
    cout<<"The linked list is:"<<endl;
    while(cur!=NULL)
    {
        cout<<cur->data<<"->";
        cur=cur->link;
    }
    cout<<"NULL"<<endl;
    return 0;
}
