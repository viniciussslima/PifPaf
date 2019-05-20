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
	for (unsigned int i = 0; i < prob.size(); i++)
	{
		for (unsigned int j = 0; j < bolo.size(); j++)
		{
			if (bolo[j] == b[prob[i]])
			{
				bolo.erase(bolo.begin()+j);
			}
		}
		
	}
	//random_shuffle(bolo.begin(), bolo.end());
}