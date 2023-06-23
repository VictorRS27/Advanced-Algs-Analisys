/*
 * Victor Rofrigues da Silva  NUSP: 12566140
 *
 * max flow
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

#define MAX 510

int V = 0;
long long int graph[MAX][MAX] = {0};

bool bfs(int src, int trg, int *path)
{
    queue<int> q;

    q.push(src);
    path[src] = -1;

    int visitado[V];
    for (int i = 0; i < V; i++)
    {
        visitado[i] = 0;
        //cout << visitado[i];
    }
    
    visitado[src] = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] > 0 && visitado[v] == 0)
            {
                q.push(v);
                path[v] = u;
                visitado[v] = 1;
            }
        }
    }
    // verifica se tem caminho de src para trg
    return (visitado[trg] == 1);
}

long long int ff(int src, int trg)
{ 
    int u;
    int path[V] = {0};

    long long int maxFlow = 0;

    while (bfs(src, trg, path))
    { 

        long long int gargalo = 1e15 +5;
        for (int v = trg; v != src; v = path[v])
        {
            u = path[v];
            gargalo = min(gargalo, graph[u][v]);
        }

        for (int v = trg; v != src; v = path[v])
        {
            u = path[v];
            graph[u][v] -= gargalo; 
            graph[v][u] += gargalo; 
        }
        maxFlow += gargalo;
    }

    return maxFlow;
}

int main(int argc, char const *argv[])
{
    int conn;
    cin >> V >> conn;
    int x, y;
    long long int diameter;
    for (int i = 0; i < conn; i++)
    {
        cin >> x >> y >> diameter;
        graph[x-1][y-1] += diameter;
    }
    
    cout << ff(0, V-1) << endl;

    return 0;
}
