#include <bits/stdc++.h>
using namespace std;
void sortx(int wt[], int val[], int n)
{
    double val_by_wt[n];
    for(int i=0;i<n;i++)
    {
        val_by_wt[i]=(double)val[i]/wt[i];
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(val_by_wt[j]<val_by_wt[j+1])
            {
                double temp=val_by_wt[j];
                val_by_wt[j]=val_by_wt[j+1];
                val_by_wt[j+1]=temp;

                int twt=wt[j];
                wt[j]=wt[j+1];
                wt[j+1]=twt;

                int tval=val[j];
                val[j]=val[j+1];
                val[j+1]=tval;
            }
        }
    }
    char ch='A';
    cout<<"The sorted array:"<<endl;
    cout<<"Items    Wt  Val  Val_by_Wt"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Item "<<(char)ch++<<": "<<wt[i]<<" - "<<val[i]<<" - "<<val_by_wt[i]<<endl;
    }
}
void fracKnap(int wt[], int val[], int W, int n)
{
    double x[n], profit=0;
    int i, weight=0;
    char ch='A';
    for(i=0;i<n;i++)
    {
        x[i]=0;
    }
    i=0;
    while(weight<W)
    {
        if(weight+wt[i]<=W && i<n)
        {
            x[i]=1.0;
            weight+=wt[i];
        }
        else{
            x[i]=(double)(W-weight)/wt[i];
            weight=W;
        }
        profit+=x[i]*val[i];
        i++;
    }
    cout<<"The fractional values:"<<endl;
    for(int k=0;k<n;k++)
    {
        cout<<"Item "<<(char)ch++<<": "<<x[k]<<endl;
    }
    cout<<"\nThe profit: "<<profit<<endl;
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
    char ch='A';
    for(int i=0;i<n;i++)
    {
        cout<<"Item "<<(char)ch++<<": ";
        cin>>wt[i];
    }
    ch='A';
    cout<<"Enter the value of each item:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Item "<<(char)ch++<<": ";
        cin>>val[i];
    }
    sortx(wt, val, n);
    fracKnap(wt,val,W,n);
    return 0;
}
