/*
 * Victor Rofrigues da Silva  NUSP: 12566140
 *
 * define if a number is a divisor of one other's factorial
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef vector<ull> vl;

#define tamCrivo 100010

class nt_factorial_divisor
{
private:
    vector<ull> primos;
    bitset<tamCrivo> crivo;

public:
    nt_factorial_divisor();
    vl fatoresPrimos(ull N);
};

nt_factorial_divisor::nt_factorial_divisor()
{
    crivo.set();
    crivo[0] = crivo[1] = 0;
    for (ull i = 2; i <= tamCrivo; ++i)
    {
        if (crivo[i])
        {
            for (ull j = i * i; j <= tamCrivo; j += i)
                crivo[j] = 0;
            primos.push_back(i);
        }
    }
}

vl nt_factorial_divisor::fatoresPrimos(ull N)
{
    vl vet;

    int ind = 0;
    ull FP = primos[ind];
    while (FP * FP <= N)
    {
        while (N % FP == 0)
        {
            vet.push_back(FP);
            N = N / FP;
        }

        FP = primos[++ind];
    }

    if (N != 1)
        vet.push_back(N);

    return vet;
}

int main(int argc, char const *argv[])
{
    ull factorial, divisor;
    nt_factorial_divisor primes;
    // exit(0);
    while (cin >> factorial >> divisor)
    {
        bool ok = false;
        if (divisor == 1)
        {
            ok =true;
        }
        
        if (!(factorial == 0 || factorial == 1 || divisor == 0 || divisor == 1))
        {
            
            vl divisor_factors = primes.fatoresPrimos(divisor);
            for (ull i = 2; i <= factorial; i++)
            {
                ull k = i;
                for (ull j = 0; j < divisor_factors.size(); j++)
                {
                    if (k % divisor_factors[j] == 0)
                    {
                        ull aux = divisor_factors[j];
                        divisor_factors.erase(divisor_factors.begin() + j);
                        j = -1;
                        if (k != aux)
                            k = k / aux;
                        else
                            break;
                    }
                }
                if (divisor_factors.size() == 0)
                {
                    ok = true;
                    break;
                }
            }
        }
        cout << divisor;
        if (ok)
        {
            cout << " divides ";
        }
        else
        {
            cout << " does not divide ";
        }
        cout << factorial << "!\n";
    }

    return 0;
}
