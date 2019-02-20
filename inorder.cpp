#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data)
{
     struct Node* node = (struct Node*)malloc(sizeof(struct Node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;
     return(node);
}


void inorder(struct Node* node)
{
     if (node == NULL)
          return;
     inorder(node->left);
     cout<<node->data<<endl;
     inorder(node->right);
}
int main()
{
     struct Node *root=newNode(1);
     root->left=newNode(7);
     root->right=newNode(6);
     root->left->left=newNode(4);
     root->left->right=newNode(5);
     root->right->left=newNode(3);
     root->right->right=newNode(2);

     cout<<"Inorder traversal:"<<endl;
     inorder(root);
     return 0;
}
