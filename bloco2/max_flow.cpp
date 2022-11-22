/*
 * Victor Rofrigues da Silva  NUSP: 12566140
 *
 * max flow
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

#define MAX 105

int V = 0;
int graph[MAX][MAX] = {0};

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

int ff(int src, int trg)
{ 
    int u;
    int path[V] = {0};

    long long int maxFlow = 0;

    while (bfs(src, trg, path))
    { 

        int gargalo = 100000;
        for (int v = trg; v != src; v = path[v])
        {
            u = path[v];
            gargalo = min(gargalo, graph[u][v]);
        }

        for (int v = trg; v != src; v = path[v])
        {
            u = path[v];
            graph[u][v] -= gargalo; 
            graph[v][u] -= gargalo; 
        }
        maxFlow += gargalo;
    }

    return maxFlow;
}

int main(int argc, char const *argv[])
{
    cin >> V;
    if (V == 0)
        return 0;
    int network_count = 1;
    while (V != 0)
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                graph[i][j] = 0;
            }
            
        }
        
        int src, trg, edges, x, y, heavy;
        cin >> src >> trg >> edges;
        src--;
        trg--;
        for (int i = 0; i < edges; i++)
        {
            cin >> x >> y;
            x--;
            y--;
            cin >> heavy;
            graph[x][y] += heavy;
            graph[y][x] += heavy;
            //cout << graph[x][y];
        }
        cout << "Network " << network_count << "\nThe bandwidth is " << ff(src, trg) << ".";
        cin >> V;
        if (V!=0)
        {
            cout << "\n\n";
        }
        
        network_count++;
    }

    return 0;
}
