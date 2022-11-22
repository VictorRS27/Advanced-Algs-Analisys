/*
 * Victor Rofrigues da Silva  NUSP: 12566140
 *
 * negative cycles
 *
 *  */

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define MAX_SIZE 509
typedef vector<pair<int, int>> vecintpair;
#define INF 0x3f3f3f3f

typedef pair<int, int> int_pair;

class Pound_Graph
{
    int V;
    list<pair<int, int>> *adj;
    vector<vector<long long int>> memo;

public:
    Pound_Graph(int V);
    void add_edge(int u, int v, int w);
    void add_edge_directed(int u, int v, int w);
    vector<long long int> shortest_path(int src);
    void memory();
    long long int query(int src, int trg);
    bool negative_cyles();
};
Pound_Graph::Pound_Graph(int V)
{
    this->V = V;
    adj = new list<int_pair>[V];
}

void Pound_Graph::add_edge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Pound_Graph::add_edge_directed(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
}

/* vector<long long int> Pound_Graph::shortest_path(int src)
{
    priority_queue<int_pair, vector<int_pair>, greater<int_pair>> pq;
    vector<long long int> dist(V, INF);
    bool visited[V] = {false};

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        list<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if (!visited[v] && dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
                visited[v] = true;
            }
        }
    }

    return dist;
}*/

vector<long long int> Pound_Graph::shortest_path(int src)
{
    //priority_queue<int_pair, vector<int_pair>, greater<int_pair>> pq;
    vector<long long int> dist(V, INF);
    dist[src] = 0;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            list<pair<int, int>>::iterator k;
            for (k = adj[j].begin(); k != adj[j].end(); k++)
            {
                int v = (*k).first;
                int weight = (*k).second;
                if (dist[j] != INF && dist[j] + weight < dist[v])
                dist[v] = dist[j] + weight;
            }
        }
    }

    return dist;
}

bool Pound_Graph::negative_cyles()
{
    vector<long long int> dist = shortest_path(1);
    for (int i = 0; i < V; i++)
    {
        list<pair<int, int>>::iterator j;
        for (j = adj[i].begin(); j != adj[i].end(); ++j)
        {
            int v = (*j).first;
            int weight = (*j).second;
            if (dist[i] != INF && dist[i] + weight < dist[v])
            {
                return 1;
            }
        }
    }
    return 0;
}

void Pound_Graph::memory()
{
    for (int i = 0; i < V; i++)
    {
        memo.push_back(shortest_path(i));
    }
}

long long int Pound_Graph::query(int src, int trg)
{
    return memo[src][trg];
}

int main(int argc, char const *argv[])
{
    int vertexes, edges;
    cin >> vertexes >> edges;
    Pound_Graph my_Pound_Graph(vertexes);

    int vert_a, vert_b, pound;
    for (int i = 0; i < edges; i++)
    {
        // cout << "lendo:\n";
        cin >> vert_a;
        cin >> vert_b;
        scanf("%d", &pound);
        // cout << vert_a << vert_b << pound << '\n';
        my_Pound_Graph.add_edge_directed(vert_a - 1, vert_b - 1, pound);
        // cout << "terminei de gravar!\n";
    }
    // cout << "chamando a func";
    if (my_Pound_Graph.negative_cyles())
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
