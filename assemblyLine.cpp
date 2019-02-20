#include<iostream>
using namespace std;

int fmin(int a, int b)
{
    return a<b?a:b;
}
int assemblyLine(int a[][], int t[][], int nj, int *e, int *x)
{
    int T1[nj], T2[nj], i;

    T1[0]=e[0]+a[0][0];
    T2[0]=e[1]+a[1][0];

    for (i=1;i<nj;i++)
    {
        T1[i]=min(T1[i-1]+a[0][i], T2[i-1]+t[1][i]+a[0][i]);
        T2[i]=min(T2[i-1]+a[1][i], T1[i-1]+t[0][i]+a[1][i]);
    }
    return min(T1[nj-1] + x[0], T2[nj-1] + x[1]);
}

int main()
{
    int nj;
    cout<<"Enter the no. of stations:"<<endl;
    cin>>nj;
    int a[2][nj], t[2][nj], e[2];
    cout<<"Enter the time taken and cost of transfer at each station:"<<endl;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<nj;j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    cout<<"Enter the entry and exit times of each line:"<<endl;
    for(int i=0; i<2;i++)
    {
        cin>>e[i];
        cin>>x[i];
    }

    cout<<assemblyLine(a, t, nj, e, x)<<endl;
    return 0;
}
