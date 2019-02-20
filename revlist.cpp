#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
void push(struct Node** head, int x)
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
void swaplink(int *a, int* b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void revlink(struct Node* head)
{
    struct Node* p=head;
    while(p!=NULL && p->next!=NULL)
    {
        swaplink(&p->data,&p->next->data);
        p=p->next->next;
    }

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
        cout<<"Enter element no. "<<i+1<<":"<<endl;
        cin>>x;
        push(&head,x);
    }
    disp(head);
    revlink(head);
    disp(head);
    return 0;
}
