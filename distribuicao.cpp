#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

void distribuicao(vector<string> &b,
	vector<string> &bolo,
	vector<vector<int>> &p, 
	int &q)
{
	vector<int> prob;
	random_device rd;
	int n;
	int r = 0;

	for (int j = 0; j < q; j++)
	{
		for (int i = 0; i < 9; ++i)
		{
			n = rd() % 56;
			for (auto it : prob)
			{
				if (it == n)
				{
					r++;
				}
			} 
			if (r == 0)
			{
				p[j].push_back(n);
				prob.push_back(n);
			}
			else
			{
				i--;
			}
			r = 0;
		}
		sort(p[j].begin(), p[j].end());
	}
	sort(prob.begin(), prob.end());
	for (unsigned int i = 0; i < prob.size(); i++)
	{
		bolo.erase(bolo.begin()+prob[i]-i);
		
	}
	random_shuffle(bolo.begin(), bolo.end());
}