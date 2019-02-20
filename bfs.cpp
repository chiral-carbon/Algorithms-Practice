#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int n;
    list<int> *adj;
public:
    Graph(int n)
    {
        this->n = n;
        adj = new list<int>[n];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void BFS(int s)
    {
        bool visited[n];
        for(int i=0;i<n;i++)
            visited[i] = false;

        list<int> queue;

        visited[s]=true;
        queue.push_back(s);

        list<int>::iterator i;

        while(!queue.empty())
        {
            s=queue.front();
            cout<<s<<" ";
            queue.pop_front();

            for (i=adj[s].begin();i!=adj[s].end();i++)
            {
                if (!visited[*i])
                {
                    visited[*i]=true;
                    queue.push_back(*i);
                }
            }
        }
    }
};
int main()
{
    int n, e, u, v, x=1, s;
    cout<<"Enter the number of vertices:"<<endl;
    cin>>n;
    Graph g(n);

    cout<<"Enter the number of edges:"<<endl;
    cin>>e;
    for(int i=0;i<e;i++)
    {
        cout<<"Enter edge pair "<<x++<<": ";
        cin>>u>>v;
        g.addEdge(u, v);
    }

    cout<<"Enter the source vertex:"<<endl;
    cin>>s;

    cout << "Following is Breadth First Traversal starting from vertex "<<s<<": "<<endl;
    g.BFS(s);
    return 0;
}
