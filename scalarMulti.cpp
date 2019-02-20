#include<iostream>
#include<cmath>
using namespace std;
void matChainParen(int *S, int i, int j, int n)
{
    if(i==j)
    {
        cout<<" A"<<i<<" ";
        return;
    }
    else{
        cout<<"(";
        matChainParen(S, i, *((S+i*n)+j), n);
        matChainParen(S, *((S+i*n)+j), j, n);
        cout<<")";
    }
    cout<<endl;
}
int matChainMulti(int r[], int n)
{
    int M[n][n], S[n][n];
    for(int i=0;i<n;i++)
    {
        M[i][i]=0;
    }
    for(int d=2;d<n;d++)
    {
        for(int i=1;i<=n-d;i++)
        {
            int j=i+d-1;
            M[i][j]=20000000;
            for(int k=i;k<j;k++)
            {
                int temp=M[i][k]+M[k+1][j]+(r[i-1]*r[k]*r[j]);
                if(temp<M[i][j])
                {
                   M[i][j]=temp;
                   S[i][j]=k;
                }
            }
        }
    }
    return M[1][n];
    matChainParen((int*)S, 1, n, n);
}
int main()
{
    int x;
    cout<<"Enter the number of matrices: "<<endl;
    cin>>x;
    int r[x];
    cout<<"Enter the sequence of matrix orders:"<<endl;
    for(int i=0;i<=x;i++)
    {
        cin>>r[i];
    }
    cout<<"The number of matrix multipications: "<<matChainMulti(r,x);
}
