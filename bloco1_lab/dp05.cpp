/*
 * Victor Rodrigues da Silva  NUSP: 12566140
 *
 *
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

int MEMO[5000];

int lower_edit_distance(string cur_w1, string &w2, int letter, int edits)
{
    if (MEMO[letter] != 100000000)
    {
        return MEMO[letter];
    }

    if (letter >= (int)w2.size() && letter >= (int)cur_w1.size())
    {
        return edits;
    }

    if (letter >= (int)w2.size() && letter < (int)cur_w1.size())
    {
        MEMO[letter] = edits + (int)cur_w1.size() - (int)w2.size();
        return MEMO[letter];
    }

    if (letter >= (int)cur_w1.size() && letter < (int)w2.size())
    {
        MEMO[letter] = edits + (int)w2.size() - (int)cur_w1.size();
        return MEMO[letter];
    }

    if (cur_w1[letter] == w2[letter])
    {
        int min_edit = lower_edit_distance(cur_w1, w2, letter + 1, edits);
        MEMO[letter] = min_edit;
        return min_edit;
    }

    if (cur_w1[letter] != w2[letter])
    {
        int min_edits = 5000;
        string tmp_str = cur_w1;
        tmp_str[letter] = w2[letter];
        min_edits = min(min_edits, lower_edit_distance(tmp_str, w2, letter + 1, edits + 1));
        tmp_str = cur_w1.substr(0, letter);
        tmp_str = tmp_str + (cur_w1.substr(letter + 1, (int)cur_w1.size() - letter + 1));
        min_edits = min(min_edits, lower_edit_distance(tmp_str, w2, letter, edits + 1));
        min_edits = min(min_edits, lower_edit_distance(cur_w1.substr(0, letter + 1) + w2[letter] + (cur_w1.substr(letter + 1, (int)cur_w1.size() - letter)), w2, letter + 1, edits + 1));
        MEMO[letter] = min_edits;
        return min_edits;
    }

    cout << "erro";
    return -1;
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 5000; i++)
    {
        MEMO[i] = 100000000;
    }
    
    string w1, w2;
    cin >> w1 >> w2;
    cout << lower_edit_distance(w1, w2, 0, 0);
    return 0;
}
