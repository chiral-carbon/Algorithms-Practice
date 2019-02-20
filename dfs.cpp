#include<bits/stdc++.h>
using namespace std;
class graph
{
    int n, time;
    int color[], pred[], d[], f[];
    list<int> *adj;
    void DFS_visit(int u)
    {
        color[u]=1;
        time++;
        d[u]=time;
        list<int>::iterator i;
        for (i=adj[u].begin();i!=adj[u].end();i++)
        {
            if(color[v]==0)
            {
                pred[v]=u;
                DFS_visit(v);
            }
        }
        color[u]=2;
        f[u]=time+1;
    }
public:
    graph(int n)
    {
        this->n=n;
        time=0;
        adj=new list<int>[n];
    }
    void edge(int u, int v)
    {
        adj[u].push_back(v);
    }
    void DFS(int u)
    {
        list<int>::iterator i;
        for (i=adj[u].begin();i!=adj[u].end();i++)
        {
            color[u]=0;
            pred[u]=0;
        }
        time = 0;
        for (i=adj[u].begin();i!=adj[u].end();i++)
        {
            if(color[u]==0)
                DFS_visit(u);
        }
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
