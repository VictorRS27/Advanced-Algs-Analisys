/*
 * Victor Rofrigues da Silva  NUSP: 12566140
 *
 * Backtraking based in queens problem
 * 
 * Optimized but c++ offensive.
 *  */
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int word_size = 0;
int n, m;
char **board;
int ways[4][2] = {-1, 0,
                  1, 0,
                  0, -1,
                  0, 1};
bool valid_check(pair<int, int> new_local)
{
    if (new_local.first < n && new_local.first >= 0 && new_local.second < m && new_local.second >= 0)
        return true;
    return false;
}

bool backtracking(char *word, pair<int, int> location, int counter)
{
    if (counter >= word_size)
    {
        return true;
    }
    if (board[location.first][location.second] == word[counter])
    {
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> new_local = make_pair(location.first + ways[i][0], location.second + ways[i][1]);
            if (valid_check(new_local) && backtracking(word, new_local, counter + 1))
                return true;
        }
        return false;
    }
    else
    {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    while (cin >> n)
    {
        cin >> m;
        board = (char **)malloc(n * sizeof(char *));
        for (int i = 0; i < n; i++)
            board[i] = (char *)malloc(m * sizeof(char));

        vector<pair<char, pair<int, int>>> first_letter;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%c", &board[i][j]);
                pair<char, pair<int, int>> letter_map = make_pair(board[i][j], make_pair(i,j));
                first_letter.push_back(letter_map);
            }
        }
        cin >> word_size;
        char word[word_size];
        cin >> word;

        sort(first_letter.begin(), first_letter.end());

        printf("%s\n", word);
        exit(0);

        pair<vector<pair<char, pair<int, int>>>::iterator, vector<pair<char, pair<int, int>>>::iterator> bounds = equal_range(first_letter.begin(), first_letter.end(), word[0]);

        bool found = false;
        vector<pair<char, pair<int, int>>>::iterator k;
        for (k = bounds.first; k < bounds.second; k++)
        {
            found = backtracking(word, k.base()->second, 0);
            if (found)
                break;
        }
        if (found)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }

        for (int i = 0; i < n; i++)
        {
            free(board[i]);
        }
        free(board);
    }
    return 0;
}
