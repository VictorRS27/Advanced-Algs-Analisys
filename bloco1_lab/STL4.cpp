/*
 * Victor Rofrigues da Silva  NUSP: 12566140
 *
 * count voluntiers for projects, discarting double candidates
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, string> Pis;
typedef pair<int, int> Pii;

int main(int argc, char const *argv[])
{
    string reader = "start";
    priority_queue< Pii, vector<Pii>, greater<Pii> > registers;
    map<int,int> regs;
    cin >> reader;
    while (reader[0] != '#')
    {
        int name, frequency;
        cin >> name >> frequency;
        registers.push(make_pair(frequency, name));
        regs[name] = frequency;
        cin >> reader;
    }
    int reads;
    cin >> reads;
    for (int i = 0; i < reads; i++)
    {
        pair<int,int> tmp = registers.top();
        registers.pop();
        printf("%d\n", tmp.second);
        registers.push(make_pair(tmp.first + (regs.find(tmp.second)->second), tmp.second));

    }
    
    
    
    return 0;
}
