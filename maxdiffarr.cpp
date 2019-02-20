]#include<iostream>
using namespace std;
int main()
{
    int n, big, small;
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
    big=arr[0];
    small=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>big)
            big=arr[i];
        if(arr[i]<small)
            small=arr[i];
    }
    cout<<"\nThe maximum difference in the array elements: "<<big-small<<endl;
    return 0;
}
