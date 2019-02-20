#include <bits/stdc++.h>
using namespace std;
struct MinHeapNode
{
    char data;
    int freq;
    MinHeapNode *left, *right;
    MinHeapNode(char data, int freq)
    {
        left=right=NULL;
        this->data=data;
        this->freq=freq;
    }
};
struct compare
{
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};
void disp(struct MinHeapNode* root, string str)
{
    if(!root)
        return;

    if(root->data!='$')
        cout<<root->data<<": "<<str<<"\n";

    disp(root->left, str + "0");
    disp(root->right, str + "1");
}
void huffmanEnc(char data[], int freq[], int n)
{
    struct MinHeapNode *left, *right, *top;
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for(int i=0; i<n; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    while(minHeap.size()!=1) {

        left=minHeap.top();
        minHeap.pop();

        right=minHeap.top();
        minHeap.pop();

        top=new MinHeapNode('$', left->freq + right->freq);

        top->left=left;
        top->right=right;

        minHeap.push(top);
    }
    disp(minHeap.top(), "");
}
int main()
{
    int n;
    cout<<"Enter the number of characters:"<<endl;
    cin>>n;
    char arr[n];
    int freq[n];
    cout<<"Enter the characters with their frequencies:"<<endl;
    for(int i=0;i<n;i++)
    {
       cin>>arr[i];
       cin>>freq[i];
    }
    huffmanEnc(arr, freq, n);
    return 0;
}
