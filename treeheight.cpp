#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
int maxDepth(struct node* node)
{
   if (node==NULL)
       return 0;
   else
   {
       int lDepth = maxDepth(node->left);
       int rDepth = maxDepth(node->right);
       if (lDepth > rDepth)
           return(lDepth+1);
       else return(rDepth+1);
   }
}
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

int main()
{
    struct node *root = newNode(100);

    root->left = newNode(200);
    root->right = newNode(300);
    root->left->left = newNode(400);
    root->left->right = newNode(500);
    root->right->left = newNode(600);
    root->right->right = newNode(700);
    root->left->left->left = newNode(800);
    root->left->left->right = newNode(900);

    cout<<"Height of tree = "<<maxDepth(root);
    return 0;
}
