#include<bits/stdc++.h>
using namespace std;
class graph
{
    int n;
    list<int> *adj;
    void DFS_visit(int u, bool visited[])
    {
        visited[u]=true;
        cout<<u<<" ";
        list<int>::iterator i;
        for (i=adj[u].begin();i!=adj[u].end();i++)
           if(visited[*i]==false)

        DFS_visit(*i, visited);
    }
public:
    graph(int n)
    {
        this->n=n;
        adj=new list<int>[n];
    }
    void edge(int u, int v)
    {
        adj[u].push_back(v);
    }
    void DFS(int u)
    {
        bool visited[n];
        for(int i=0;i<n;i++)
            visited[i]=false;

        DFS_visit(u, visited);
    }
};
int main()
{
    int n, e, u, v, x=1, s;
    cout<<"Enter the number of vertices:"<<endl;
    cin>>n;
    graph gph(n);

    cout<<"Enter the number of edges:"<<endl;
    cin>>e;
    for(int i=0;i<e;i++)
    {
        cout<<"Enter edge pair "<<x++<<": ";
        cin>>u>>v;
        gph.edge(u, v);
    }

    cout<<"Enter the source vertex:"<<endl;
    cin>>s;

    cout << "The Depth First Traversal from vertex "<<s<<": "<<endl;
    gph.DFS(s);
    return 0;
}
