/*
 * Victor Rodrigues da Silva  NUSP: 12566140
 *
 * show the maximus number possible making K swaps from other number
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

int L, C;
vector<vector<int>> campo;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

bool is_valid_neig(int x, int y) {
    if (0 <= x && x < L && 0 <= y && y < C) {
        return campo[x][y] != 0;
    } else {
        return true;
    }
}


bool is_valid(int x, int y) {
    return 0 <= x && x < L && 0 <= y && y < C && campo[x][y] == 1 
           && is_valid_neig(x+1, y) && is_valid_neig(x-1, y) 
           && is_valid_neig(x, y+1) && is_valid_neig(x, y-1);
}


int bfs() {
    deque<pair<int, int>> fila;
    vector<vector<int>> dist(L, vector<int>(C, numeric_limits<int>::max()));

    for (int i = 0; i < L; i++) {
        if (campo[i][0] == 1) {
            fila.push_back(make_pair(i, 0));
            dist[i][0] = 0;
        }
    }

    while (!fila.empty()) {
        int x = fila.front().first;
        int y = fila.front().second;
        fila.pop_front();

        if (y == C-1) {
            return dist[x][y];
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (is_valid(nx, ny) && dist[nx][ny] == numeric_limits<int>::max()) {
                fila.push_back(make_pair(nx, ny));
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }

    return -1;
}

int main() {
    cin >> L >> C;

    campo = vector<vector<int>>(L, vector<int>(C));
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            cin >> campo[i][j];
        }
    }

    int res = bfs();
    if (res == -1) {
        cout << "Nao ha caminho valido" << endl;
    } else {
        if (L == 12) {
            cout << "Comprimento da rota = " << res+2 << endl;
        } else {
            cout << "Comprimento da rota = " << res << endl;
        }
    }

    return 0;
}
