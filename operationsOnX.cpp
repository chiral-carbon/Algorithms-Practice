#include <iostream>
using namespace std;
int main()
{
    int x, c=0;
    cout<<"Enter a positive number:"<<endl;
    cin>>x;
    while(x>1)
    {
        if(x%2==0&&x%3==0)
        {
            x/=3;
            c++;
        }
        else if(x%2==0)
        {
            if((x-1)%3==0)
            {
                x-=1;
                c++;
                x/=3;
                c++;
            }
            else
            {
               x/=2;
               c++;
            }
        }
        else if(x%3==0)
        {
            x/=3;
            c++;
        }
        else
        {
            x=x-1;
            c++;
        }
    }
    cout<<"The minimum number of operations: "<<c<<endl;
    return 0;
}
