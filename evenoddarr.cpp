#include<iostream>
using namespace std;
int main()
{
    int n, k=0;
    cout<<"Enter no. of elements:"<<endl;
    cin>>n;
    int arr[n], b[n];
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
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2==0)
        {
            b[k]=arr[i];
            k++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2!=0)
        {
            b[k]=arr[i];
            k++;
        }
    }
    cout<<"\nAfter segregating even and odd elements:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}
