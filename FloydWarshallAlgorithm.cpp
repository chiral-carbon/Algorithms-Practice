#include<iostream>
using namespace std;
#define V 4
#define inf 99999

void disp(int dist[][V])
{
    cout<<"The matrix shows the shortest distances between every pair of vertices:"<<endl;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(dist[i][j] == inf)
                cout<<"Inf	";
            else
                cout<<dist[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void floydWarshall(int graph[][V])
{
    int dist[V][V];

    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            dist[i][j]=graph[i][j];

    for(int k=0;k<V;k++)
    {
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    disp(dist);
}
int main()
{
    int graph[V][V] = { {0,   5,  inf, 10},{inf, 0,   3, inf},{inf, inf, 0,  1},{inf, inf, inf, 0} };
    floydWarshall(graph);
    cout<<"\nInf = Infinite distance"<<endl;
    return 0;
}
