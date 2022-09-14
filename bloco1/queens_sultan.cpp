/*
 * Victor Rofrigues da Silva  NUSP: 12566140
 *
 * Backtraking based in queens problem
 *  */
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

#define TAB_SIZE 8

using namespace std;

// guarda a linha que cada rainha ocupa na coluna de 0-7
int linhas[TAB_SIZE];
long int count = 0;
int values[TAB_SIZE][TAB_SIZE];
int great_score = 0;

void imprimeTab(int *linhas)
{
    for (int i = 0; i < TAB_SIZE; ++i)
        printf("%i ", linhas[i]);
    printf("\n");
}

bool valido(int lin, int col)
{
    // verifica se a rainha a ser colocada nao conflita com as que ja existem
    for (int rp = 0; rp < col; rp++)
        if (linhas[rp] == lin || (abs(linhas[rp] - lin) == abs(rp - col)))
            return false;
    return true;
}

void backtracking(int c, int sum)
{
    //cout << c << " " << sum << "/n";
    if (c == TAB_SIZE)
    { // passei por todas as colunas..
        count++;
        if (sum > great_score)
            great_score = sum;
        // imprimeTab(linhas);
    }
    else
    {
        // para todas as linhas
        for (int lin = 0; lin < TAB_SIZE; lin++)
        {
            if (valido(lin, c))
            {
                linhas[c] = lin;
                backtracking(c + 1, sum + values[lin][c]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int boards;
    cin >> boards;
    for (int k = 0; k < boards; k++)
    {
        memset(linhas, 0, sizeof linhas);
        for (int i = 0; i < TAB_SIZE; i++)
        {
            for (int j = 0; j < TAB_SIZE; j++)
            {
                cin >> values[i][j];
            }
        }
        //cout << "li\n";
        backtracking(0, 0);
        printf("%5d\n", great_score);
        great_score = 0;
    }
    return 0;
}