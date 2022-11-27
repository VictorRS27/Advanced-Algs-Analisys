#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef vector<ull> vl;

#define TAM 260010

void kmpPreProcessamento(int *b, string pat)
{
    int tamp = pat.length();
    int i = 0, j = -1;
    b[0] = -1;

    while (i < tamp)
    {

        while (j >= 0 && pat[i] != pat[j])
        {
            j = b[j];
        }

        i++;
        j++;
        b[i] = j;
    }
}

void kmp(int *b, vector<int> &occurrences, string text, string pat)
{
    int tamt = text.size();
    int tamp = pat.size();
    int i = 0, j = 0;
    while (i < tamt)
    {
        while (j >= 0 && text[i] != pat[j])
        {
            j = b[j];
        }
        i++;
        j++;
        if (j == tamp)
        {
            occurrences.push_back(i - j + 1);
            j = b[j];
        }
    }
}

int main(int argc, char const *argv[])
{
    int b[100001];
    vector<int> occurences;

    string text;
    string patt;

    int trys;
    cin >> trys;
    for (int i = 0; i < trys; i++)
    {
        cin >> text;
        cin >> patt;

        kmpPreProcessamento(b, patt);

        kmp(b, occurences, text, patt);

        if (occurences.size() > 0)
        {
            cout << occurences.size() << "\n";
            cout << occurences[0];
            for (int j = 1; j < (int)occurences.size(); j++)
            {
                cout << " " << occurences[j];
            }
        }
        else
        {
            cout << "Not Found";
        }
        occurences.clear();
        cout << "\n\n";
    }

    return 0;
}