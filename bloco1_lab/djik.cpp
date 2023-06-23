#include <bits/stdc++.h>

using namespace std;

class Graph {
 public:
  vector<vector<pair<int, int>>> adj;

  Graph(int n) {
    adj.resize(n);
  }

  void addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
};

int shortestPath(Graph &g, int src, int dest) {
  int n = g.adj.size();
  vector<int> dist(n, INT_MAX);
  dist[src] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, src});

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    for (auto &e : g.adj[u]) {
      int v = e.first;
      int w = e.second;

      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }

  return dist[dest];
}

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  Graph g(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g.addEdge(u - 1, v - 1, w);
  }

  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << shortestPath(g, u - 1, v - 1) << endl;
  }

  return 0;
}
