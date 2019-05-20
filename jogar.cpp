#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool verificar_vitoria()
{
	return true;
}

void jogar(vector<string> &bolo,
	vector<vector<string>> &p, int &q)
{
	string lixo;
	int v = 0;
	int jogadas = 0;
	bool loop = true;
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

		if (jogadas == 0)
		{
			cout << "[1] Puxar do bolo" << endl;
		}
		else
		{
			cout << "Lixo: " << lixo << endl;
				<< "[1] Puxar do bolo" << endl
				<< "[2] Puxar do lixo" << endl;
		}
		
		cin << escolha;
		switch(escolha)
		{
			case '1':
				puxa();
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