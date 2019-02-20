#include<bits/stdc++.h>
using namespace std;
int zeroes(int mid)
{
    int c=0;
    while(mid>0)
    {
        mid/=5;
        c=c+mid;
    }
    return c;
}
void binSearch(int n)
{
    int rmin=0;
    int rmax=1000;
    while(rmin<rmax)
    {
        int mid=(rmin+rmax)/2;
        int count=zeroes(mid);
        if(count<n)
            rmin=mid+1;
        else
            rmax=mid;
    }
    vector<int> v;
    while(zeroes(rmin)==n)
    {
        v.push_back(rmin);
        rmin++;
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}
int main()
{
    int n;
    cout<<"Enter the number of zeroes:"<<endl;
    cin>>n;
    binSearch(n);
    return 0;
}
