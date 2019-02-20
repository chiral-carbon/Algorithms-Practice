#include<iostream>
#include<cstdlib>
using namespace std;
int leftchild(int i)
{
    return (2*i);
}
int rightchild(int i)
{
    return (2*i+1);
}
void nswap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void max_heapify(int a[], int m, int i)
{
    int l, r, largest;
    l=leftchild(i);
    r=rightchild(i);
    if(l<m & a[l]>a[i])
        largest=l;
    else
        largest=r;

    if(r<m & a[r]>a[largest])
        largest=r;

    if(largest!=i)
    {
        nswap(&a[i], &a[largest]);
        max_heapify(a,m,largest);
    }
}
void build_maxheap(int a[], int m)
{
    for(int i=m/2-1;i>=0;i--)
    {
        max_heapify(a, m, i);
    }
}
void heapsort(int a[], int m)
{
    build_maxheap(a, m);
    for(int i=m-1;i>=0;i--)
    {
        nswap(&a[0],&a[i]);
        m=m-1;
        max_heapify(a, i, 0);
    }
}
int main()
{
    int n, m;
    cout<<"Enter the number of elements:"<<endl;
    cin>>n;
    cout<<"\nThe array elements will be randomly generated."<<endl;
    int a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=rand();
    }
    cout<<"The array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    m=sizeof(a)/sizeof(a[0]);
    heapsort(a,m);
    cout<<"\nThe sorted array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
