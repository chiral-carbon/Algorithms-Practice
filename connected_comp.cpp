#include <iostream>
using namespace std;
int getv(int a[], int i){
    while(a[i]!=i){
        a[i]= a[a[i]];
        i=a[i];
    }
    return i;
}
int components(int n, int e, int E[][2])
{
    int c=n;
    int V[n];

    for(int i=0; i<n; i++){
        V[i]=i;
    }

    for(int i=0; i<e; i++){
        int x=E[i][0];
        int y=E[i][1];

        int xv=getv(V, x);
        int yv=getv(V, y);

        if(xv!=yv){
            c--;
            V[xv]=yv;
        }
    }
    return c;
}
int main()
{
    int n, e, x=1;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    cout<<"\nEnter the number of edges: ";
    cin>>e;
    int E[e][2];
    cout<<"\nEnter the pairs of vertices for edges:"<<endl;
    for(int i=0;i<e;i++)
    {
        cout<<"For edge "<<x++<<":"<<endl;
        cin>>E[i][0]>>E[i][1];
    }
    cout<<"The number of connected components in the graph: "<<components(n,e,E)<<endl;
    return 0;
}
