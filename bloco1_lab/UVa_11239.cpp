/*
 * Victor Rofrigues da Silva  NUSP: 12566140
 *
 * count voluntiers for projects, discarting double candidates
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, string> Pis;

int main(int argc, char const *argv[])
{
    set<string> students_cleaner, students_doubled_global, students_dobled_scoped;
    vector<string> tudo;
    string reader;
    do
    {
        getline(cin, reader);
        if (reader == "0")
            break;

        bool tmp = students_dobled_scoped.insert(reader).second;
        if (tmp)
        {
            tudo.push_back(reader);
            if (!students_cleaner.insert(reader).second)
            {
                students_doubled_global.insert(reader);
            }
        }

        if (isupper(reader[0]))
        {
            students_dobled_scoped.clear();
        }

        if (reader[0] == '1')
        {
            set<Pis> result;
            int counter;
            string project;

            for (int i = 0; i < (int)tudo.size(); i++)
            {
                if (isupper(tudo[i][0]))
                {
                    if (i != 0)
                        result.insert(make_pair(-counter, project));

                    counter = 0;
                    project = tudo[i];
                }
                else if (islower(tudo[i][0]))
                {
                    if (students_doubled_global.find(tudo[i]) == students_doubled_global.end())
                    {
                        counter++;
                    }
                }
            }
            result.insert(make_pair(-counter, project));

            for (auto it = result.begin(); it != result.end(); it++)
            {
                //(*it).second.pop_back();
                printf("%s %d\n", (*it).second.substr(0, (*it).second.size()).c_str(), -(*it).first);
            }

            tudo.clear();
            students_cleaner.clear();
            students_doubled_global.clear();
            students_dobled_scoped.clear();
        }
    } while (!(reader == "0"));

    return 0;
}
