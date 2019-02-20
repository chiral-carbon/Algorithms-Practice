#include<iostream>
using namespace std;
int main()
{
    int n1,n2,i,j,k;
    cout<<"Enter size of two arrays: ";
    cin>>n1>>n2;
    int S[n1], R[n2];
    cout<<"Enter 1st array: ";
    for(i=0;i<n1;i++)
        cin>>S[i];
    cout<<"Enter 2nd array: ";
    for(i=0;i<n2;i++)
        cin>>R[i];
    cout<<"Enter the value of k :";
    cin>>k;
    int c=1;
    cout<<"Value at k is: ";
    for(i=0,j=0;i<n1,j<n2;)
    {
        if(S[i]<R[j])
        {
            if(c==k)
            {
                cout<<S[i];
                break;
            }
            i++;
        }
        else
        {
            if(c==k)
            {
                 cout<<R[j];
                 break;
            }
            j++;
        }
        c++;
    }
    return 0;
}
