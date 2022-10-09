/*
 * Victor Rofrigues da Silva  NUSP: 12566140
 *
 * find all the ways to go through a maze
 *
 *  */
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

#define MAX_SIZE 1000000007

int main(int argc, char const *argv[])
{
    int W = 0, H = 0;
    cin >> W;
    cin >> H;
    char board[W][H];
    int dp_board[W][H];
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < H; j++)
        {
            dp_board[i][j] = 0;
        }
    }

    dp_board[0][0] = 1;
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < H; j++)
        {
            cin >> board[i][j];
            if (board[i][j] != '#')
            {
                if (j != 0)
                {
                    dp_board[i][j] = (dp_board[i][j] + dp_board[i][j - 1]) % MAX_SIZE;
                }
                if (i != 0)
                {
                    dp_board[i][j] = (dp_board[i][j] + dp_board[i - 1][j]) % MAX_SIZE;
                }
            }
        }
    }

    printf("%d\n", dp_board[W - 1][H - 1]);

    return 0;
}