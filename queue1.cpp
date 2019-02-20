#include<iostream>
using namespace std;
int f=-1, r=-1;
int q[10];
int emptyq()
{
    if((f==-1 && r==-1)||(f>r))
        return 1;
    else return 0;
}
void insertq()
{
    if(r==9)
        cout<<"Queue overflow"<<endl;
    else if(emptyq()==1)
    {
        f=r=-1;
        cout<<"Enter element:";
        cin>>q[++r];
        f++;
    }
    else
    {
        cout<<"Enter element:";
        cin>>q[++r];
    }
}
void deleteq()
{
    if(emptyq()==1)
    {
        cout<<"Queue underflow"<<endl;
    }
    else
    {
        cout<<"The deleted element is "<<q[f++];
    }
}
void disp()
{
    if(emptyq()==1)
        cout<<"Queue is empty"<<endl;
    else{
    cout<<"->";
    for(int i=f;i<=r;i++)
    {
        cout<<q[i]<<"->";
    }
    }
}
int main()
{
    int ch;
    while(1)
    {
    cout<<"\n1. Insert\n2. Delete\n3. Display"<<endl;
    cout<<"Enter choice:"<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1: insertq();break;
        case 2: deleteq();
                break;
        case 3: disp();
                break;
        default:cout<<"Invalid option"<<endl;
    }
    }
    return 0;
}
