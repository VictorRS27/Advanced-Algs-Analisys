/*
 * Victor Rofrigues da Silva  NUSP: 12566140
 *
 * Backtraking based in queens problem
 *
 * Dumn but working
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
bool valid_check(int row, int column)
{
    if (row < n && row >= 0 && column < m && column >= 0)
        return true;
    return false;
}

bool backtracking(char *word, int row, int column, int counter, int history)
{
    if (counter >= word_size)
    {
        return true;
    }
    if (board[row][column] == word[counter])
    {
        for (int i = 0; i < 4; i++)
        {
            if (i != ((history) / 2)*2 + ((history % 2) - 1) * -1)
            {
                if (valid_check(row + ways[i][0], column + ways[i][1]) && backtracking(word, row + ways[i][0], column + ways[i][1], counter + 1, i))
                    return true;
            }
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
        // printf("\n%d, %d\n", n, m);
        board = (char **)malloc(n * sizeof(char *));
        for (int i = 0; i < n; i++)
            board[i] = (char *)malloc(m * sizeof(char));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf(" %c", &board[i][j]);
            }
        }
        cin >> word_size;
        // printf("%d\n", word_size);
        char word[word_size];
        cin >> word;

        // printf("%s\n", word);

        bool found = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                found = backtracking(word, i, j, 0, 40);
                if (found)
                    break;
            }
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
