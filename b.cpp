#include <iostream>
#include <string>
#include <vector>
#include "distribuicao.cpp"
#include "jogar.cpp"

using namespace std;

int main()
{
	vector<string> b;
	vector<string> bolo;
	b = {"AC", "2C", "3C", "4C", "5C", "6C", "7C",
		"8C", "9C", "10C", "JC", "QC", "KC", "AC",
		"AP", "2P", "3P", "4P", "5P", "6P", "7P",
		"8P", "9P", "10P", "JP", "QP", "KP", "AP",
		"AO", "2O", "3O", "4O", "5O", "6O", "7O",
		"8O", "9O", "10O", "JO", "QO", "KO", "AO",
		"AE", "2E", "3E", "4E", "5E", "6E", "7E",
		"8E", "9E", "10E", "JE", "QE", "KE", "AE"};
	bolo = b;
	
	vector<vector<int>> p;
	vector<int> p1;
	vector<int> p2;
	vector<int> p3;
	vector<int> p4;
	p.push_back(p1);
	p.push_back(p2);
	p.push_back(p3);
	p.push_back(p4);
	int q;

	do{
		cout << "numero de jogadores: " << endl;
		cin >> q;
	}while(q <= 1 || q > 4);

	distribuicao(b, bolo, p, q);
	//jogar(b, bolo, p, q);

	for (int i = 0; i < q; ++i)
	{
		cout << "Jogador " << i+1 << ": " << endl;
		for (auto it : p[i])
		{
			cout << b[it] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (auto it : bolo)
		{
			cout << it << " ";
		}
	cout << endl;
	cout << bolo.size() << endl;
}