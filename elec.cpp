#include<iostream>
using namespace std;
int main()
{
    int n, k=0;
    cout<<"Enter no. of candidates:"<<endl;
    cin>>n;
    int arr[n],b[n], c[n]={0};
    cout<<"Enter votes:"<<endl;
    for(int i=0; i<n;i++)
    {
        cin>>arr[i];
    }
    int big=arr[0],pos=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>big)
        {
            big=arr[i];
            pos=i;
        }
    }
    cout<<"\nThe candidate no. "<<pos+1<<" has won."<<endl;
    return 0;
}
