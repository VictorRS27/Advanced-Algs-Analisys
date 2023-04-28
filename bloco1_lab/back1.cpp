/*
 * Victor Rodrigues da Silva  NUSP: 12566140
 *
 * show all possible variations of spaces between letters in a string
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string reader;
    while (cin >> reader)
    {
        for (int i = 0; i < pow(2,(int)reader.size()-1); i++)
        {
            cout << reader[0];
            for (int j = 1; j < (int)reader.size(); j++)
            {
                int contra_j = pow(2,(int)reader.size() - j-1);
                if (i & contra_j /* && contra_j <= i */)
                {
                    cout << " ";
                }
                cout << reader[j];
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}
