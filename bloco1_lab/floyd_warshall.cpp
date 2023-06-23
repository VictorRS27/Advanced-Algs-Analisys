/*
 * Victor Rodrigues da Silva  NUSP: 12566140
 *
 * shortest path algorithm
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

vector<vector<long long>> floydWarshall(int n, vector<vector<long long>>& adj) {
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));

    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && adj[i][j] != INF) {
                dist[i][j] = adj[i][j];
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    return dist;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<long long>> adj(n + 1, vector<long long>(n + 1, INF));

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b], (long long)c);
        adj[b][a] = min(adj[b][a], (long long)c);
    }

    vector<vector<long long>> dist = floydWarshall(n, adj);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        if (dist[a][b] != INF)
            cout << dist[a][b] << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}
