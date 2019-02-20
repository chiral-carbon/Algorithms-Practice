
#include<iostream>
using namespace std;
int para(int n)
{
    int term, ans=0;
    if(n==1)
        return 1;
    else{
        for(int i=1;i<n;i++)
        {
            term=para(i)*para(n-i);
            ans=ans+term;
        }
    return ans;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of matrices: "<<endl;
    cin>>n;
    cout<<"The no. of ways to parenthesize "<<n<<" matrices: "<<para(n)<<endl;
    return 0;
}
