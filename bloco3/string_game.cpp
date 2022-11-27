/*
 * Victor Rodrigues da Silva  NUSP: 12566140
 *
 * find the final word in a string game where one player wants greater letters and the other lower
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int total_cases;
    cin >> total_cases;
    getchar();
    for (int i = 0; i < total_cases; i++)
    {
        char in;
        in = getchar();
        int counter = 0;
        while (in != '\n')
        {
            if (counter % 2 == 0)
            {
                if (in != 'a')
                    cout << 'a';
                else
                    cout << 'b';
            }
            else
            {
                if (in != 'z')
                    cout << 'z';
                else
                    cout << 'y';
            }
            in = getchar();
            counter++;
        }
        cout << '\n';
    }

    return 0;
}