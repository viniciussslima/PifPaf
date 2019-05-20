#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

void distribuicao(vector<string> &bolo,
	vector<vector<string>> &p, int &q)
{
	vector<int> rn;
	vector<int> prob;
	random_device rd;
	int n;
	int r1, r2;

	for (int j = 0; j < q; j++)
	{
		for (int i = 0; i < 9; ++i)
		{
			n = rd() % 56;
			for (auto it : rn)
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
				rn.push_back(n);
				prob.push_back(n);
			}
			else
			{
				i--;
			}
			r1 = 0;
			r2 = 0;
		}
		sort(rn.begin(), rn.end());
		for (auto it : rn)
		{
			p[j].push_back(bolo[it]);
		}
		rn.clear();
	}
	for (unsigned int i = 0; i < prob.size(); i++)
	{
		bolo.erase(bolo.begin()+prob[i]);
	}
}