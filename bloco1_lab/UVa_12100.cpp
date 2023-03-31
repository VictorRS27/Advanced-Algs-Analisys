/* 
 * Victor Rodrigues da Silva
 * 
 * UVa 12100
 * 
 * implementar uma fila de prioridade burra que
 * funciona tipo um bubble sort
 */


#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main(int argc, char const *argv[])
{
    int test_cases, n, myjobpos;
    cin >> test_cases;
    for (int j = 0; j < test_cases; j++)
    {
        queue<pii> q;
        vector<int> how_many_before;
        cin >> n >> myjobpos;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            q.push(make_pair(i, x));
            how_many_before.push_back(x);
        }
        sort(how_many_before.begin(),how_many_before.end());

        int already_printed = 0;
        while (!q.empty())
        {
            int jobpos = q.front().first;
            int prio_iter = q.front().second;
            q.pop();
             
            if (prio_iter == how_many_before.back())
            {
                already_printed++;
                if (jobpos == myjobpos) break;
                how_many_before.pop_back();
            }
            else
            {
                q.push(make_pair(jobpos, prio_iter));
            }
        }
        cout<<already_printed<<"\n";
        
    }
    return 0;
}
