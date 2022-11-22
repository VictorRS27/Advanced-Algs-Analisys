/*
 * Victor Rofrigues da Silva  NUSP: 12566140
 *
 * shortest path algorithm
 *
 *  */

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define MAX_SIZE 509
typedef vector<pair<int, int>> vecintpair;
#define INF 0x3f3f3f3f

typedef pair<int, int> int_pair;

class Djikstra
{
    int V;
    list<pair<int, int>> *adj;
    vector<vector<long long int>> memo;

public:
    Djikstra(int V);
    void add_edge(int u, int v, int w);
    vector<long long int> shortest_path(int src);
    void memory();
    long long int query(int src, int trg);
};
Djikstra::Djikstra(int V)
{
    this->V = V;
    adj = new list<int_pair>[V];
}

void Djikstra::add_edge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

vector<long long int> Djikstra::shortest_path(int src)
{
    priority_queue<int_pair, vector<int_pair>, greater<int_pair>> pq;
    vector<long long int> dist(V, INF);

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
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

void Djikstra::memory()
{
    for (int i = 0; i < V; i++)
    {
        memo.push_back(shortest_path(i));
    }
}

long long int Djikstra::query(int src, int trg)
{
    return memo[src][trg];
}

int main(int argc, char const *argv[])
{
    int cities, roads, querys;
    cin >> cities >> roads >> querys;
    Djikstra my_Djikstra(cities);

    int city_a, city_b, length;
    for (int i = 0; i < roads; i++)
    {
        cin >> city_a >> city_b >> length;
        my_Djikstra.add_edge(city_a - 1, city_b - 1, length);
    }
    my_Djikstra.memory();
    for (int i = 0; i < querys; i++)
    {
        cin >> city_a >> city_b;
        long long int out;
        if (my_Djikstra.query(city_a - 1, city_b - 1) == INF)
            out = -1;
        else
            out = my_Djikstra.query(city_a - 1, city_b - 1);

        cout << out << "\n";
    }

    return 0;
}
