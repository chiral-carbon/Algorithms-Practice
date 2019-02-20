#include<iostream>
using namespace std;
int fmax(int a, int b)
{
    return ((a>=b)?a:b);
}
int knapsack(int W, int n, int wt[], int val[])
{
    int ks[n+1][W+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0||j==0)
                ks[i][j]=0;
            else if(wt[i-1]<=j)
                ks[i][j]=fmax(val[i-1]+ks[i-1][j-wt[i-1]],ks[i-1][j]);
            else ks[i][j]=ks[i-1][j];
        }
    }
    return ks[n][W];
}
int main()
{
    int W, n;
    cout<<"Enter the max capacity of the knapsack: "<<endl;
    cin>>W;
    cout<<"Enter the total no. of items: "<<endl;
    cin>>n;
    int wt[n], val[n];
    cout<<"Enter the weight of each item:"<<endl;
    for(int i=0;i<n;i++)
        cin>>wt[i];
    cout<<"Enter the value of each item:"<<endl;
    for(int i=0;i<n;i++)
        cin>>val[i];
    cout<<"The maximum value of items in the knapsack of max capacity "<<W<<": "<<knapsack(W,n,wt,val);
    return 0;
}
