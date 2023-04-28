/*
 * Victor Rodrigues da Silva  NUSP: 12566140
 *
 * suit the best order of jobs with minimum fine
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Pii;
typedef pair<int, Pii> PPii;

struct Order
{
    bool operator()(PPii const &a, PPii const &b) const
    {
        return (a.second.first * b.second.second) > (b.second.first * a.second.second) || ((a.second.first * b.second.second) == (b.second.first * a.second.second) && a.first > b.first);
    }
};

int main(int argc, char const *argv[])
{
    priority_queue<PPii, vector<PPii>, Order> q;
    int test_cases;
    cin >> test_cases;

    for (int i = 0; i < test_cases; i++)
    {
        cin.ignore();
        int n_jobs;
        cin >> n_jobs;
        for (int j = 0; j < n_jobs; j++)
        {
            int time, fine;
            cin >> time >> fine;
            q.push(make_pair(j, make_pair(time, fine)));
        }

        while (q.size() > 0)
        {
            PPii tmp = q.top();
            q.pop();
            cout << tmp.first + 1 << " ";
        }
        if (!(i == test_cases-1))
            cout << endl << endl;
    }

    return 0;
}
