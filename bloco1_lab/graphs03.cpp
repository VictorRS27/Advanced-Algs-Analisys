/*
 * Victor Rodrigues da Silva  NUSP: 12566140
 *
 * separate a graph in two parts not connected
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // Adjacency list representation of friendships
vector<int> team;        // Team assignment for each pupil
bool isPossible = true;  // Variable to track if a valid solution is possible

// Function to perform DFS and assign teams
void dfs(int pupil, int currentTeam) {
    team[pupil] = currentTeam; // Assign current pupil to the current team

    // Traverse all the friends of the current pupil
    for (int friendPupil : adj[pupil]) {
        // If the friend is not assigned to any team, assign the opposite team
        if (team[friendPupil] == 0)
            dfs(friendPupil, 3 - currentTeam);
        // If the friend is assigned to the same team, it's impossible to form teams
        else if (team[friendPupil] == currentTeam)
            isPossible = false;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);  // Adjacency list for pupils (1-indexed)
    team.resize(n + 1); // Team assignment for pupils (1-indexed)

    // Read friendships and build adjacency list
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Perform DFS to assign teams
    for (int i = 1; i <= n; i++) {
        if (team[i] == 0)
            dfs(i, 1);
    }

    // If a valid solution is not possible, print "IMPOSSIBLE"
    if (!isPossible) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        // Print the team assignment for each pupil
        for (int i = 1; i <= n; i++) {
            cout << team[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
