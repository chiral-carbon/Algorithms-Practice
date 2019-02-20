#include<iostream>
using namespace std;
int main()
{
    int n, k=0;
    cout<<"Enter no. of votes cast:"<<endl;
    cin>>n;
    int arr[n],b[n], c[n]={0};
    cout<<"Enter the votes:"<<endl;
    for(int i=0; i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"The votes you entered:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    while(k<n)
    {
        for(int i=1;i<n;i++)
        {
            if(arr[i]==arr[k])
            {
                c[k]++;
                b[k]=arr[k];
            }
        }
        k++;
    }
    /*for(int i=0;i<n;i++)
    {
        cout<<c[i]<<" ";
    }*/
    int big=c[0], pos=0;
    for(int i=1;i<n;i++)
    {
        if(c[i]>big)
        {
            big=c[i];
            pos=i;
        }
    }
    cout<<"\nThe candidate no. "<<b[pos]<<" has won."<<endl;
    return 0;
}
