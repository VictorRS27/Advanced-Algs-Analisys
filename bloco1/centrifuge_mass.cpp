/*
 * Victor Rofrigues da Silva  NUSP: 12566140
 *
 * Imbalance
 *  */
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int total_centri, tests_counter = 0;
    while (cin >> total_centri)
    {
        int total_samples, tmp;
        float mass_summoning = 0, mass_per_centri = 0, imbalance = 0;
        vector<int> samples;
        cin >> total_samples;
        for (int i = 0; i < total_samples; i++)
        {
            cin >> tmp;
            samples.push_back(tmp);
            mass_summoning += tmp;
        }

        mass_summoning = mass_summoning / total_centri;

        for (int i = total_samples; i < total_centri * 2; i++)
        {
            samples.push_back(0);
        }

        sort(samples.begin(), samples.end());
        reverse(samples.begin(), samples.end());

        cout << "Set #" << tests_counter + 1 << "\n";
        for (int i = 0; i < total_centri; i++)
        {
            mass_per_centri = samples[i] + samples[2 * total_centri - i - 1];
            imbalance += abs(mass_per_centri - mass_summoning);
            // pretty printer
            cout << " " << i << ": ";
            if (samples[2 * total_centri - i - 1] == 0)
            {
                if (samples[i] == 0)
                {
                    cout << "\n";
                }
                else
                {
                    cout << samples[i] << '\n';
                }
            }
            else
            {
                cout << samples[2 * total_centri - i - 1] << " " << samples[i] << '\n';
            }
        }
        printf("IMBALANCE = %.5lf\n\n", imbalance);

        tests_counter++;
    }

    return 0;
}
