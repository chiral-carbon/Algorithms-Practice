#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
void push(struct Node** head,int x)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->next=*head;
    *head=newNode;
}
void disp(struct Node* head)
{
    while(head!= NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
void nswap(struct Node**head,int a,int b)
{
    if(a==b)
    {
        return;
    }
    struct Node* pres1=NULL;
    struct Node* curr1=*head;
    struct Node* pres2=NULL;
    struct Node* curr2=*head;
    while(curr1 && curr1->data!=a)
    {
        pres1=curr1;
        curr1=curr1->next;
    }
    while(curr2 && curr2->data!=b)
    {
        pres2=curr2;
        curr2=curr2->next;
    }
    if(curr1==NULL||curr2==NULL)
    {
        return;
    }
    if(pres1!= NULL)
    {
        pres1->next=curr2;
    }
    else
    {
        *head=curr2;
    }
    if(pres2!= NULL)
    {
        pres2->next=curr1;
    }
    else
    {
        *head=curr1;
    }
    struct Node* temp=curr1->next;
    curr1->next=curr2->next;
    curr2->next=temp;
}
int main()
{
    struct Node* head= NULL;
    int n;
    cout<<"Enter the number of nodes:"<<endl;
    cin>>n;
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        push(&head,x);
    }
    disp(head);
    cout<<endl;
    int a, b;
    cout<<"Enter the values to be swapped: "<<endl;
    cin>>a>>b;
    nswap(&head,a,b);
    disp(head);
    return 0;
}
