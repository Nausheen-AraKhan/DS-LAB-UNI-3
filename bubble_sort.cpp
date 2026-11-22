#include<iostream>
using namespace std;
void bubble_sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
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
    bubble_sort(arr,n);
    cout<<"After bubble sort:"<<endl;
    for(int j=0;j<n;j++)
    {
        cout<<arr[j]<<" ";
    }
    return 0;}
