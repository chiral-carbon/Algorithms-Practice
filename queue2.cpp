#include <iostream>
using namespace std;
struct node{
    int data;
    struct node*next;
};
int f=-1;
int r=-1;
struct node*head=NULL;
struct node*link=(int*)(malloc(sizeof(node)));
void insertq(int k)
{
    if(head==NULL)
    {
        head->data=k;
        head->next=NULL;
    }
    else{
        struct node *temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
        }

    }
}
