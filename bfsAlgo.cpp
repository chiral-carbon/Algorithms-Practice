#include <bits/stdc++.h>
using namespace std;
class graph
{
    int n;
    list<int> *adj;
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
    void BFS(int s)
    {
        bool visited[n];
        for(int i=0;i<n;i++)
            visited[i]=false;

        list<int> queue;

        visited[s]=true;
        queue.push_back(s);

        list<int>::iterator i;

        while(!queue.empty())
        {
            s=queue.front();
            cout<<s<<" ";
            queue.pop_front();

            for(i=adj[s].begin();i!=adj[s].end();i++)
            {
                if(visited[*i]==false)
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

    cout << "The Breadth First Traversal from vertex "<<s<<": "<<endl;
    gph.BFS(s);
    return 0;
}
