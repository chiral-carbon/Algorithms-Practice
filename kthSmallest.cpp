#include<iostream>
using namespace std;
void nswap(int* a, int* b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int npart(int S[], int p, int r)
{
    int x=S[r];
    int i=p;
    for(int j=p;j<r;j++)
    {
        if(S[j]<=x)
        {
            nswap(&S[i], &S[j]);
            i++;
        }
    }
    nswap(&S[i], &S[r]);
    return i;
}
int kSmall(int S[],int p,int r,int k)
{
    if(k>0 && k<= r-p+1)
    {
        int pos=npart(S,p,r);
        if (pos-p==k-1)
            return S[pos];
        if (pos-p>k-1)
        {
            return kSmall(S, p, pos-1, k);
        }
        else
            return kSmall(S, pos+1, r, k-pos+p-1);
    }
}
int main()
{
    int n, k;
    cout<<"Enter the number of elements:"<<endl;
    cin>>n;
    int S[n];
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>S[i];
    }
    cout<<"Enter the index k:"<<endl;
    cin>>k;
    cout<<"The kth smallest element = "<<kSmall(S,0,n-1,k)<<endl;
    return 0;
}
