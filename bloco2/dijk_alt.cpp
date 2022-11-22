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

class djik
{
private:
    int djik_origin, djik_target;
    vector<pair<int,vecintpair>> to_visit;
    pair<bool,int> visited[MAX_SIZE];
    int graph_size_x;
    vector<vecintpair> graph;
    void djik_run(int *min_way, int walked);

public:
    djik(int size_x);
    bool set_graph(int x, int y, int value);
    bool set_path(int origin, int target);
    int search();
    bool priority_queue(pair<int,vecintpair> a, pair<int,vecintpair> b));
};

djik::djik(int size_x)
{
    graph_size_x = size_x;
    for (int i = 0; i < graph_size_x; i++)
    {
        vecintpair reader;
        reader.push_back(make_pair(0, i));
        graph.push_back(reader);
    }
}

bool djik::set_graph(int x, int y, int value)
{
    graph[x].push_back(make_pair(value, y));
    sort(graph[x].begin(), graph[x].end());
    graph[y].push_back(make_pair(value, x));
    sort(graph[y].begin(), graph[y].end());
    return 1;
}

bool djik::set_path(int origin, int target)
{
    djik_origin = origin;
    djik_target = target;
    return 1;
}

void djik::djik_run(int *min_ways, int walked)
{
    
}

bool djik::priority_queue( pair<int,vecintpair> a, pair<int,vecintpair> b)
{
    if ()
    {
        /* code */
    }
    
}

int djik::search()
{
    int min_way = 0, walked = 0;
    to_visit.push_back(make_pair(djik_origin,graph[djik_origin]));
    //djik_run(&min_way, 0);

    //to_visit.push_back(graph[origin]);
    visited[djik_origin] = make_pair(true, 0);
    
    while (!to_visit.empty())
    {
        pair<int,vecintpair> cur_vertex = to_visit.back();
        to_visit.pop_back();
        for (int i = 0; i < cur_vertex.second.size(); i++)
        {
            if (!cur_vertex.second[i].first)
            {
                visited[cur_vertex.second[i].second] = make_pair(true, cur_vertex.second[i].first + visited[cur_vertex.first].second);
                to_visit.push_back(make_pair(cur_vertex.second[i].second, graph[cur_vertex.second[i].second]));
                sort(to_visit.begin(), to_visit.end(), priority_queue)
            }
            
        }
        
        
        
    }
    
}

int main(int argc, char const *argv[])
{
    int cities, roads, querys;
    cin >> cities >> roads >> querys;
    djik my_djik(cities);

    int city_a, city_b, length;
    for (int i = 0; i < roads; i++)
    {
        cin >> city_a >> city_b >> length;
        my_djik.set_graph(city_a, city_b, length);
    }
    for (int i = 0; i < querys; i++)
    {
        cin >> city_a >> city_b;
        my_djik.set_path(city_a, city_b);
        cout << my_djik.search();
    }

    return 0;
}
