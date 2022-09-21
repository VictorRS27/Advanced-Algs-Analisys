/*
 * Victor Rodrigues da Silva  NUSP: 12566140
 *
 *
 *  */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* int start = 0, ending;
 */
int bin_searh(vector<pair<int, int>> &intervals, int start, int ending, int target)
{
    //printf("[%d, %d]\n", start, ending);
    if (start>ending)
    {
        return -1;
    }
    if (start == ending)
    {
        return start;
    }
    int to_search = (ending + start) / 2;
    /* printf("%d\n", to_search);
    printf("%d < %d\n", intervals[to_search].first, target);
    printf("%d > %d\n", intervals[to_search].second, target); */
    if (intervals[to_search].first < target)
    {
        
        if (intervals[to_search].second >= target)
        {
            return to_search;
        }
        else
        {
            return bin_searh(intervals, to_search+1, ending, target);
        }
    }
    else
    {
        return bin_searh(intervals, start, to_search-1, target);
    }
    
    return -1;
}

int final_stages = 0;

pair<int, int> generate_interval(int repeats, int time)
{
    int old_stage = final_stages;
    final_stages += repeats * time;
    return make_pair(old_stage, final_stages);
}

int main(int argc, char const *argv[])
{
    int musics, marks;
    cin >> musics;
    cin >> marks;
    vector<pair<int, int>> intervals;
    for (int i = 0; i < musics; i++)
    {
        int repeats, time;
        cin >> repeats;
        cin >> time;
        intervals.push_back(generate_interval(repeats, time));
    }
    int mark;
    for (int i = 0; i < marks; i++)
    {
        cin >> mark;
        if (mark == 0)
        {
            mark = 1;
        }else{
            mark = bin_searh(intervals, 0, musics-1, mark);
        }
        if (mark != -1)
        {
            cout << mark+1 << "\n";
        }
    }

    return 0;
}
