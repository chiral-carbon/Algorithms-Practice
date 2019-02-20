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
    cout<<endl;
}
void delNode(struct Node** head)
{
    struct Node* temp=*head;
    *head=temp->next;
    free(temp);
}
int main()
{
    struct Node* head= NULL;
    int n;
    cout<<"Enter the number of nodes:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cout<<"Enter the "<<i+1<<"th element:"<<endl;
        cin>>x;
        push(&head,x);
    }
    disp(head);
    delNode(&head);
    disp(head);
    return 0;
}
