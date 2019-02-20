#include<iostream>
#include<cstdlib>
using namespace std;
void merges(int arr[], int p, int q, int r)
{
    int n1=q-p+1;
    int n2=r-q;
    int L1[n1], L2[n2];
    for (int i=0;i<n1;i++)
    {
         L1[i]=arr[p+i];
    }
    for(int j=0;j<n2;j++)
    {
        L2[j]=arr[q+1+j];
    }
    int i=0,j=0,k=p;
    while (i<n1&&j<n2)
    {
        if(L1[i]<=L2[j])
        {
            arr[k]=L1[i];
            i++;
        }
        else
        {
            arr[k]=L2[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=L1[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=L2[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int p, int r)
{
    if (p<r)
    {
        int q=p+(r-p)/2;
        mergeSort(arr, p, q);
        mergeSort(arr, q+1, r);
        merges(arr, p, q, r);
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
        cout<<a[i]<<" ";
    }
    mergeSort(a, 0, n-1);
    cout<<"\nThe sorted array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
