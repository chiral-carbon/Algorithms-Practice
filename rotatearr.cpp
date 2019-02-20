#include<iostream>
using namespace std;
int main()
{
    int n, d;
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
    cout<<"\nEnter no. of elements to rotate:"<<endl;
    cin>>d;
    int temp=arr[d-1];
    for(int i=d-1;i>0;i--)
    {
        arr[i]=arr[i-1];

    }
    arr[0]=temp;
    cout<<"After rotating "<<d<<" elements:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
