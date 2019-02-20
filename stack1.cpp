#include<iostream>
#include <cstring>
using namespace std;
int top=-1;
string s;
char c[100];
void inserts(string t)
{
    if(top==t.length()-1)
        cout<<"Stack Overflow."<<endl;
    else
    {
        for(int i=0;i<t.length();i++)
            c[++top]=t.at(i);
    }
}
void deletes()
{
    if(top==-1)
        cout<<"Stack underflow."<<endl;
    else
    {
        cout<<"The deleted element is "<<c[top--];
    }
}
void disp()
{
    for(int i=0;i<=top;i++)
        cout<<c[i]<<"<-";
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
        case 1: cout<<"Enter a string:"<<endl;
                cin>>s;
                inserts(s);break;
        case 2: deletes();
                break;
        case 3: disp();
                break;
        default:cout<<"Invalid option"<<endl;
    }
    }
    return 0;
}
