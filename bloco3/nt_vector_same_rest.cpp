/*
 * Victor Rofrigues da Silva  NUSP: 12566140
 *
 * find gdc of some numbers where the rest is the same
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

class nt_vector_same_rest
{
private:
    vl diference;
    vl line;

public:
    nt_vector_same_rest();
    ll find_mdc_with_module();
    void insert_number(ll x);
};

nt_vector_same_rest::nt_vector_same_rest()
{
}

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll nt_vector_same_rest::find_mdc_with_module()
{
    ll result = diference[0];
    for (long unsigned int i = 1; i < diference.size(); i++)
    {
        result = gcd(result, diference[i]);
    }
    return result;
}

void nt_vector_same_rest::insert_number(ll x)
{
    if (!line.empty())
    {
        diference.push_back(abs(line.back()-x));
        line.push_back(x);
    }else
    {
        line.push_back(x);
    }
    
    
}

int main(int argc, char const *argv[])
{
    ll tmp;
    while (cin >> tmp)
    {
        if (tmp == 0)
        {
            break;
        }
        
        nt_vector_same_rest better_divisor;
        while (tmp != 0)
        {
            better_divisor.insert_number(tmp);
            cin >> tmp;
        }
        cout << better_divisor.find_mdc_with_module() << "\n";
    }

    return 0;
}
