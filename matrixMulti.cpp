#include<bits/stdc++.h>
using namespace std;

void matChainParen(int *S, int i, int j, int n)
{
    if(i==j)
    {
        cout<<" A"<<i<<" ";
        return;
    }

    cout<<"(";
    matChainParen(S, i, *((S+i*n)+j), n);
    matChainParen(S, *((S+i*n)+j) + 1, j, n);
    cout << ")";
}


void matChainMulti(int r[], int n)
{

    int M[n][n];
    int S[n][n];
    for (int i=1;i<n;i++)
        M[i][i] = 0;

    for (int d=2;d<n;d++)
    {
        for (int i=1;i<n-d+1;i++)
        {
            int j=i+d-1;
            M[i][j]=INT_MAX;
            for (int k=i;k<=j-1;k++)
            {

                int temp=M[i][k] + M[k+1][j] + (r[i-1]*r[k]*r[j]);
                if (temp<M[i][j])
                {
                    M[i][j]=temp;
                    S[i][j]=k;
                }
            }
        }
    }
    cout << "Optimal Parenthesization: ";
    matChainParen((int *)S, 1, n-1, n);
    cout << "\nOptimal Cost: " << M[1][n-1];
}


int main()
{
    int x;
    cout<<"Enter the number of matrices:"<<endl;
    cin>>x;
    int r[x];
    cout<<"Enter the values of matrix orders:"<<endl;
    for(int i=0;i<=x;i++)
        cin>>r[i];

    matChainMulti(r, x+1);
    return 0;
}
