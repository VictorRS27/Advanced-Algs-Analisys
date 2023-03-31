/*
 * Victor Rofrigues da Silva  NUSP: 12566140
 *
 * calculate the perimeter of a convex hull
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

typedef pair<long long int, long long int> pii;
typedef vector<pii> vpii;

long long int cross_p(pii U, pii V)
{
    return (U.first * V.second) - (V.first * U.second); // determinant
}

pii less_vectors(pii U, pii V)
{
    return make_pair((U.first - V.first), (V.second - U.second)); // determinant
}

long long int dist_sqr_calc(pii D)
{
    return pow(D.first, 2) + pow(D.second, 2);
}

long double convex_hull(vpii marks)
{
    sort(marks.begin(), marks.end());
    vector<double> dists;

    vpii lw{marks[0], marks[1]};
    dists.push_back(dist_sqr_calc(less_vectors(lw[0], lw[1])));
    int n = (int)marks.size();

    for (int i = 2; i < n; i++)
    {
        while (lw.size() >= 2u)
        {
            pii A = lw[lw.size() - 2];
            pii B = lw[lw.size() - 1];
            pii C = marks[i];
            if (cross_p(less_vectors(B, A), less_vectors(C, A)) < 0)
            {
                lw.pop_back();
                dists.pop_back();
            }
            else
                break;
        }
        pii aux = lw.back();
        lw.push_back(marks[i]);
        dists.push_back(dist_sqr_calc(less_vectors(aux, lw.back())));
    }
    vpii up{marks[n - 1], marks[n - 2]};
    dists.push_back(dist_sqr_calc(less_vectors(up[0], up[1])));
    for (int i = n - 3; i >= 0; i--)
    {
        while (up.size() >= 2u)
        {
            pii A = up[up.size() - 2];
            pii B = up[up.size() - 1];
            pii C = marks[i];
            if (cross_p(less_vectors(B, A), less_vectors(C, A)) < 0)
            {
                up.pop_back();
                dists.pop_back();
            }
            else
                break;
        }
        pii aux = up.back();
        up.push_back(marks[i]);
        dists.push_back(dist_sqr_calc(less_vectors(aux, up.back())));
    }

    long double summon = 0;
    for (int i = 0; i < (int)dists.size(); i++)
    {
        summon += sqrt(dists[i]);
    }
    return summon;
}

int main(int argc, char const *argv[])
{
    int total;
    cin >> total;
    long long int X, Y;
    vpii cows;
    for (int i = 0; i < total; i++)
    {
        cin >> X;
        cin >> Y;
        cows.push_back(make_pair(X, Y));
    }

    printf("%.4Lf", convex_hull(cows));

    return 0;
}
