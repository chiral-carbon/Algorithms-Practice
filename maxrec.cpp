#include<iostream>
using namespace std;
int maxrec(int a[], int n)
{
    if(n==1)
        return a[0];
    return max(a[n-1], maxrec(a, n-1));
}
int main()
{
    int n;
    cout<<"Enter the number of elements: "<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the elements: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"The biggest element = "<<maxrec(a, n)<<endl;
    return 0;
}
