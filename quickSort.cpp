#include<iostream>
#include<cstdlib>
using namespace std;
void nswap(int* a, int* b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int npart(int a[], int p, int r)
{
    int x=a[r];
    int i=p;
    for(int j=p;j<r;j++)
    {
        if(a[j]<=x)
        {
            nswap(&a[i], &a[j]);
            i++;
        }
    }
    nswap(&a[i], &a[r]);
    return i;

}
void quickSort(int a[],int p,int r)
{
    if(p<r)
    {
        int q=npart(a,p,r);
        quickSort(a,p,q-1);
        quickSort(a,q+1,r);
    }
}
int main()
{
    int n;
    cout<<"Enter the number of elements:"<<endl;
    cin>>n;
    cout<<"The array elements will be randomly generated."<<endl;
    int a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=rand();
    }
    cout<<"The array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"  ";
    }
    quickSort(a, 0, n-1);
    cout<<"\nThe sorted array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"  ";
    }
    return 0;
}
