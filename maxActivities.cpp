#include<iostream>
using namespace std;
void maxActivities(int s[], int f[], int n)
{
    int i, j;
    cout<<"Selected activities are:"<<endl;
    i = 0;
    cout<<i<<endl;
    for (j=1;j<n;j++)
    {
        if (s[j]>=f[i])
        {
            cout<<j<<endl;
            i=j;
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the no. of activities:"<<endl;
    cin>>n;
    int s[n];
    int f[n];
    cout<<"Enter the starting time of each activity:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Activity: "<<i+1<<": ";
        cin>>s[i];
    }
    cout<<"Enter the finishing time of each activity"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Activity: "<<i+1<<": ";
        cin>>f[i];
    }

    maxActivities(s, f, n);
    return 0;
}
