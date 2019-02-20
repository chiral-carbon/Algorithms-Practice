#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no. of elements:"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter array elements:"<<endl;
    for(int i=0; i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"The array you entered:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    for(int i=0;i<n/2;i++)
    {
        int temp=arr[i];
        arr[i]=arr[n-1-i];
        arr[n-1-i]=temp;
    }
    cout<<"\nThe reversed array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
