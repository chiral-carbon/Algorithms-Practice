#include<iostream>
#include <cstring>
using namespace std;
void lcs(char X[], int m, char Y[], int n)
{
    int C[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        C[i][0]=0;
    }
    for(int j=1;j<=n;j++)
    {
        C[0][j]=0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(X[i-1]==Y[j-1])
            {
                C[i][j]=1+C[i-1][j-1];
            }
            else{
                if(C[i-1][j]>=C[i][j-1])
                {
                    C[i][j]=C[i-1][j];
                }
                else{
                    C[i][j]=C[i][j-1];
                }//if
            }//if
        }//for
    }//for
    cout<<"Length of longest common subsequence: "<<C[m][n]<<endl;
    int in=C[m][n];
    char lcs[in+1];
    lcs[in]='\0';
    int i=m, j=n;
    while(i>0&&j>0)
    {
        if(X[i-1]==Y[j-1])
        {
            lcs[in-1]=X[i-1];
            i--;
            j--;
            in--;
        }
        else if(C[i-1][j]>=C[i][j-1])
            i--;
        else j--;
    }
    cout<<"The longest common subsequence: "<<lcs;
}
int main()
{
    int m, n;
    cout<<"Enter length of the first subsequence:"<<endl;
    cin>>m;
    char X[m];
    cout<<"Enter the first subsequence:"<<endl;
    for(int i=0;i<m;i++)
        cin>>X[i];
    cout<<"Enter length of the second subsequence:"<<endl;
    cin>>n;
    char Y[n];
    cout<<"Enter the second subsequence:"<<endl;
    for(int i=0;i<n;i++)
        cin>>Y[i];
    lcs(X,m,Y,n);
    return 0;
}
