#include<iostream>
using namespace std;
int main()
{
    int a[15]={0};
    int k,i,f=0;
    cout<<"Enter array elements:"<<endl;
    for(i=0;i<15;i++)
        cin>>a[i];
    cout<<"Enter no. to be searched"<<endl;
    cin>>k;
    for(i=0;i<15;i++)
    {
        if(a[i]==k)
           {f=1;break;}
    }
    if(f==1)
    cout<<"Number found at "<<i+1<<"th position"<<endl;
    else cout<<"Number not found"<<endl;
    return 0;
}
