/*
 * Victor Rodrigues da Silva  NUSP: 12566140
 *
 * MST eh foda
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

struct DSU
{

    vector<int> e;

    DSU(int N) : e(N, -1) {}

    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool connected(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -e[get(x)]; }

    bool unite(int x, int y)
    {

        x = get(x), y = get(y);

        if (x == y)
        {
            return false;
        }

        if (e[x] > e[y])
        {
            swap(x, y);
        }

        e[x] += e[y];

        e[y] = x;

        return true;
    }
};

template <class T>
T kruskal(int N, vector<pair<T, pair<int, int>>> edges)
{

    sort(edges.begin(), edges.end());

    T ans = 0;

    DSU D(N + 1); // edges that unite are in MST

    for (pair<T, pair<int, int>> &e : edges)
    {

        if (D.unite(e.second.first, e.second.second))
        {
            ans += e.first;
        }
    }

    // -1 if the graph is not connected, otherwise the sum of the edge lengths

    return (D.size(1) == N ? ans : -1);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<long long, pair<int, int>>> edges;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }

    long long ans = kruskal(n, edges);

    if (ans >= 0)
    {
        cout << ans;
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
}
