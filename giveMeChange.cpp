#include<iostream>
using namespace std;
int compute(int v[], int n, int x)
{
    int s,t;
    int a[x+1][n];
    for (int i=0;i<n;i++)
        a[0][i]=1;
    for(int i=1;i<=x;i++)
    {
        for (int j=0;j<n;j++)
        {
            s=(i-v[j]>=0)?a[i-v[j]][j]:0;
            t=(j>=1)?a[i][j-1]:0;

            a[i][j]=s+t;
        }
    }
    return a[x][n-1];
}
int main()
{
    cout<<"Enter the no. of different types of coins:"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the values of the types:"<<endl;
    int v[n];
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<"Enter the target value: "<<endl;
    int x;
    cin>>x;
    int res=compute(v, n, x);
    cout<<"The number of combinations: "<<res<<endl;
    return 0;
}
