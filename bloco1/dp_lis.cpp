/*
 * Victor Rofrigues da Silva  NUSP: 12566140
 *
 * LIS (Longest Increasing Subsequence)
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int total, max_all = 0;
	cin >> total;
	int original[total];
	int dp_greater_seq[total];
	for (int i = 0; i < total; i++)
	{
		cin >> original[i];
		int j = i-1;
		int max_to_increasing = 0;
		while (j>=0)
		{
			if (original[j] < original[i] && max_to_increasing < dp_greater_seq[j])
			{
				max_to_increasing = dp_greater_seq[j];
			}

			j--;
		}
		dp_greater_seq[i] = max_to_increasing+1;
		if (max_all < max_to_increasing + 1)
		{
			max_all = max_to_increasing+1;
		}
	}
	cout << max_all;

	return 0;
}
