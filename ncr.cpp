#include<iostream>
using namespace std;
int rec(int n)
{
    if(n==0||n==1)
        return 1;
    else
        return n*rec(n-1);
}
int main()
{
    int n, r;
    cout<<"Enter n and r:"<<endl;
    cin>>n>>r;
    cout<<"nCr = "<<rec(n)/(rec(n-r)*rec(r))<<endl;
    return 0;
}
