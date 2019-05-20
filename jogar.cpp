#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool verificar_vitoria()
{
	return true;
}

void puxar(vector <string> &b,
	vector <string> &bolo,
	vector <int> &p)
{
	for (unsigned int i = 0; i < b.size(); i++)
	{
		if (b[i] == bolo[0])
		{
			p.push_back(i);
			break;
		}
	}
	sort(p.begin(), p.end());
}

int descartar(vector<int> &p, vector<string> &b)
{
	string carta;
	do{
		cout << "Qual carta você quer discartar: " << endl;
		cin >> carta;
		for (unsigned int i = 0; i < b.size(); i++)
		{
			if (b[i] == carta)
			{
				return i;	
			}
		}
		cout << "Carta invalida" << endl;
	}while(true);
}

void jogar(vector<string> &b,
	vector<string> &bolo,
	vector<vector<int>> &p, int &q)
{
	int lixo = 123;
	int v = 0;
	int jogadas = 0;
	bool loop = true;
	char escolha;
	do{
		//clear
		cout << "Vez do jogador " << v+1 << ":" << endl
			<< "Aperte enter para vez sua mão" << endl;
		cin.ignore();
		cin.get();
		for (auto it : p[v])
		{
			cout << b[it] << " ";
		}
		cout << endl;

		if (jogadas == 0)
		{
			cout << "[1] Puxar do bolo" << endl;
		}
		else
		{
			cout << "Lixo: " << lixo << endl
				<< "[1] Puxar do bolo" << endl
				<< "[2] Puxar do lixo" << endl;
		}
		
		cin >> escolha;
		switch(escolha)
		{
			case '1':
				puxar(b, bolo, p[v]);
				lixo = descartar(p[v]);
				break;
			case '2':
				//pegar do lixo
				break;
		}
		
		if(verificar_vitoria())
		{
			loop = false;
		}
		jogadas++;


		if (v+1 == q)
		{
			v = 1;
		}
		else
		{
			v++;
		}
	}while(loop);
}