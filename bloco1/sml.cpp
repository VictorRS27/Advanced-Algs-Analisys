/* 
 * Victor Rofrigues da Silva  NUSP: 12566140
 * 
 * StabMatch Algorithm
 *  */


#include <iostream>
#include <vector>
using namespace std;

int sz;

class Pessoa
{
public:
    bool is_single = true;
    int id = -1, partner = -1, partner_rank = -1;
    vector<int> preferences;
    int read_prefs()
    {
        id = -1;
        partner = -1;
        partner_rank = -1;
        is_single = true;
        int x;
        cin >> x;
        id = x - 1;
        for (int i = 0; i < sz; i++)
        {
            cin >> x;
            preferences.push_back(x - 1);
        }
        return 0;
    }
    int print_pessoa()
    {
        cout << id;
        cout << is_single;
        cout << partner;
        cout << partner_rank;
        for (int i = 0; i < sz; i++)
        {
            cout << preferences[i];
        }
        return 1;
    }
};

int engage(Pessoa &woman, Pessoa &man, int prefs_counter)
{
    woman.partner = man.id;
    woman.is_single = false;
    man.partner_rank = prefs_counter;
    man.is_single = false;
    man.partner = woman.id;
    for (int i = 0; i < sz; i++)
    {
        if (woman.preferences[i] == man.id)
        {
            woman.partner_rank = i;
            break;
        }
    }
    return 1;
}

int divorce(Pessoa &woman, vector<Pessoa> &man)
{
    int solteiro = woman.partner;
    man[woman.partner].is_single = true;
    man[woman.partner].partner = -1;
    man[woman.partner].partner_rank = -1;
    woman.is_single = true;
    woman.partner = -1;
    woman.partner_rank = -1;
    return solteiro;
}

int main(int argc, char const *argv[])
{
    int test_cases;
    cin >> test_cases;
    int single;
    vector<Pessoa> man, woman;
    for (int i = 0; i < test_cases; i++)
    {
        cin >> sz;
        man.clear();
        woman.clear();

        single = sz;
        for (int j = 0; j < sz; j++)
        {
            Pessoa cuie;
            cuie.read_prefs();
            woman.push_back(cuie);
        }
        for (int j = 0; j < sz; j++)
        {
            Pessoa bundao;
            bundao.read_prefs();
            man.push_back(bundao);
        }
        int mans_counter = 0;
        while (single > 0)
        {
            if (mans_counter >= sz)
            {
                mans_counter = 0;
            }
            if (man[mans_counter].is_single)
                for (int prefs_counter = 0; prefs_counter < sz; prefs_counter++)
                {

                    int aux = man[mans_counter].preferences[prefs_counter];
                    if (woman[aux].is_single)
                    {
                        engage(woman[aux], man[mans_counter], prefs_counter);
                        single--;
                        break;
                    }
                    else
                    {
                        for (int j = 0; j < woman[aux].partner_rank; j++)
                        {
                            if (woman[aux].preferences[j] == mans_counter)
                            {
                                int aux2 = divorce(woman[aux], man);
                                engage(woman[aux], man[mans_counter], j);
                                mans_counter = aux2;
                                break;
                            }
                        }
                        
                    }
                }
            mans_counter++;
        }
        for (int j = 0; j < sz; j++)
        {
            cout << j + 1 << " " << man[j].partner + 1 << "\n";
        }
    }
    return 0;
}
