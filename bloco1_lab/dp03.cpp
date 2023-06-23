/*
 * Victor Rodrigues da Silva  NUSP: 12566140
 *
 *
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n;

int find_ways(vector<vector<int>> &pd, vector<vector<int>> &board, int x, int y)
{
    if (x == n - 1 && y == n - 1)
    {
        return 1;
    }
    if (x == n || y == n)
    {
        return 0;
    }
    if (board[x][y] == '*')
    {
        return 0;
    }

    if (pd[x][y] != -1)
    {
        return pd[x][y];
    }

    int ways_r = 0, ways_d = 0;
    ways_r = find_ways(pd, board, x, y + 1);
    ways_d = find_ways(pd, board, x + 1, y);
    pd[x][y] = (ways_r + ways_d) % MOD;
    return pd[x][y];
}

int main(int argc, char const *argv[])
{
    cin >> n;
    vector<vector<int>> board, pd;
    vector<int> board_line, pd_line;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char reader;
            cin >> reader;
            board_line.push_back((int)reader);
            pd_line.push_back(-1);
        }
        board.push_back(board_line);
        board_line.clear();
        pd.push_back(pd_line);
        pd_line.clear();
    }
    cout << find_ways(pd, board, 0, 0) << endl;
}