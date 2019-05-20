#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

void distribuicao(vector<string> &bolo,
	vector<vector<int>> &p, int &q)
{
	vector<int> prob;
	random_device rd;
	int n;
	int r1, r2;

	for (int j = 0; j < q; j++)
	{
		for (int i = 0; i < 9; ++i)
		{
			n = rd() % 56;
			for (auto it : p[j])
			{
				if (it == n)
				{
					r1++;
				}
			} 
			for (auto it : prob)
			{
				if (it == n)
				{
					r2++;
				}
			} 
			if (r1 == 0 && r2 == 0)
			{
				p[j].push_back(n);
				prob.push_back(n);
			}
			else
			{
				i--;
			}
			r1 = 0;
			r2 = 0;
		}
		sort(p[j].begin(), p[j].end());
	}
	for (unsigned int i = 0; i < prob.size(); i++)
	{
		bolo.erase(bolo.begin()+prob[i]);
	}
	random_shuffle(bolo.begin(), bolo.end());
}