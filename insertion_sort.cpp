#include<iostream>
using namespace std;
void insertion_sort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" "<<endl;
    }
}
int main()
{
    int n,arr[50];
    cout<<"How many elements?"<<endl;
    cin>>n;
    cout<<"Enter elements:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    insertion_sort(arr,n);
    cout<<"After Sorting:"<<endl;
    display(arr,n);
    return 0;
}
