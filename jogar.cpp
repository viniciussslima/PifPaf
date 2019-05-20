#include <iostream>
#include <string>
#include <vector>

using namespace std;

void jogar(vector<string> &b,
	vector<vector<string>> &p, int &q)
{
	int v = 0;
	bool loop = true;
	char teste;
	do{
		//clear
		cout << "Vez do jogador " << v+1 << ":" << endl
			<< "Aperte enter para vez sua mão" << endl;
		cin.ignore();
		cin.get();
		for (auto it : p[v])
		{
			cout << it << " ";
		}
		cout << endl;
		if (v+1 == q)
		{
			v = 1;
		}
		else
		{
			v++;
		}
		loop = false;
	}while(loop);
}