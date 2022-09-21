/*
 * Victor Rodrigues da Silva  NUSP: 12566140
 *
 * counting crossings between a ordered vector and other shuffle
 *  */
#include <iostream>
using namespace std;

long long int total_crossings;

int divide(int *con, int size_start, int size_end)
{
    //cout << size_start << " " << size_end << "\n";
    if (size_end - size_start == 1)
    {
        return 0;
    }
    int mid = (size_end - size_start) / 2 + size_start;

    //cout << mid << "\n";
    divide(con, size_start, mid);
    divide(con, mid, size_end);

    int copy[size_end - size_start];
    for (int k = 0; k < size_end - size_start; k++)
    {
        copy[k] = con[k+size_start];
    }

    int i = size_start, j = mid, k = size_start;
    while (i < mid && j < size_end)
    {
        if (copy[j-size_start] <= copy[i-size_start])
        {
            con[k] = copy[j-size_start];
            total_crossings += mid - i;
            j++;
        }
        else
        {
            con[k] = copy[i-size_start];
            i++;
        }
        k++;
    }

    while (i < mid)
    {
        con[k] = copy[i-size_start];
        i++;
        k++;
    }
    while (j < size_end)
    {
        con[k] = copy[j-size_start];
        j++;
        k++;
    }

    //printf("[%d, %d]  inversoes = %d\n", size_start, size_end, total_crossings);

    return 1;
}

int main(int argc, char const *argv[])
{
    int test_cases;
    cin >> test_cases;
    while(test_cases--)
    {
        int total_samples;
        cin >> total_samples;
        int connections[total_samples];
        for (int i = 0; i < total_samples; i++)
        {
            cin >> connections[i];
        }

        total_crossings = 0;
        divide(connections, 0, total_samples);
        cout << total_crossings << "\n";

        for (int i = 0; i < total_samples; i++)
        {
        //    cout << connections[i] << "\n";
        }
    }
    return 0;
}
