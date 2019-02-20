#include<iostream>
using namespace std;
int binarySearch(int a[], int x, int p, int r)
{
    if(p==r)
    {
        if(a[p]==x)
            return p;
        else
            return -1;
   }
   else
   {
       int q;
       q=(p+r)/2;
       if(x<=a[q])
            return(binarySearch(a, x, p, q));
       else
            return(binarySearch(a, x, q+1, r));
   }
}
int main()
{
    int n, num, k;
    cout<<"Enter number of elements:"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the elements in ascending order:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the element to be searched:"<<endl;
    cin>>num;
    k=binarySearch(a, num, 0, n-1);
    if(k!=-1)
        cout<<num<<" was found at the "<<k+1<<"th index."<<endl;
    else
        cout<<"Element was not found."<<endl;
    return 0;
}
