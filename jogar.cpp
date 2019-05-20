#include <iostream>
#include <string>
#include <vector>


using namespace std;

bool verificar_vitoria(vector <int> &p)
{
	if (p[1] == p[0] + 1 && p[1] == p[2] - 1 &&
		p[4] == p[3] + 1 && p[4] == p[5] - 1 &&
		p[7] == p[6] + 1 && p[7] == p[8] - 1)
	{
		return true;
	}
	else{
		return false;
	}
}

void puxar(vector <string> &b,
	vector <string> &bolo,
	vector <int> &p)
{
	if (bolo.size() == 0)
	{
		cout << "As cartas acabaram!! Niguém ganhou" << endl;
		return;
	}
	for (unsigned int i = 0; i < b.size(); i++)
	{
		if (b[i] == bolo[0])
		{
			p.push_back(i);
			break;
		}
	}
	sort(p.begin(), p.end());
	bolo.erase(bolo.begin());
}

void puxar_lixo(vector<int> &p, int lixo)
{
	p.push_back(lixo);
	sort(p.begin(), p.end());
}

int descartar(vector<int> &p, vector<string> &b)
{
	string carta;
	do{
		cout << "Qual carta você quer descartar: " << endl;
		cin >> carta;
		for (unsigned int i = 0; i < b.size(); i++)
		{
			if (b[i] == carta)
			{
				for (unsigned int j = 0; j < p.size(); j++)
				{
					if (p[j] == i)
					{
						p.erase(p.begin()+j);
					}
				}
				return i;	
			}
		}
		cout << "Carta invalida" << endl;
	}while(true);
}

void mao(vector<int> &p, vector<string> &b)
{
	for (auto it : p)
	{
		cout << b[it] << " ";
	}
	cout << endl;
}

void jogar(vector<string> &b,
	vector<string> &bolo,
	vector<vector<int>> &p, int &q)
{
	int lixo;
	int v = 0;
	int jogadas = 0;
	bool loop = true;
	bool loop2;
	char escolha;
	do{
		system("clear");
		cout << "Vez do jogador " << v+1 << ":" << endl
			<< "Aperte enter para vez sua mão" << endl;
		cin.ignore();
		cin.get();
		mao(p[v], b);

		loop2 = true;
		while(loop2)
		{
			if (jogadas == 0)
			{
				cout << "[1] Puxar do bolo" << endl;
			}
			else
			{
				cout << "Lixo: " << b[lixo] << endl
					<< "[1] Puxar do bolo" << endl
					<< "[2] Puxar do lixo" << endl;
			}
		
		cin >> escolha;
			switch(escolha)
			{
				case '1':
					if(puxar(b, bolo, p[v]))
					{
						mao(p[v], b);
						lixo = descartar(p[v], b);
						loop2 = false;
					}
					else
					{
						loop2 = false;
						loop = false;
					}
					break;
				case '2':
					puxar_lixo(p[v], lixo);
					mao(p[v], b);
					lixo = descartar(p[v], b);
					loop2 = false;
					break;
				default:
					cout << "Opção invalida" << endl;
			}
		}
		
		if(verificar_vitoria(p[v]))
		{
			cout << "Jogador " << v+1 << "ganhou";
			loop = false;
		}
		jogadas++;


		if (v+1 == q)
		{
			v = 0;
		}
		else
		{
			v++;
		}
	}while(loop);
}