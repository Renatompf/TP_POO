#include <iostream>
#include <string>
#include <ostream>
#include <cstdlib>
#include <sstream>
#include "carros.h"
#include "DVG.h"
#include "consola.h"

using namespace std;

int main() {

	DVG dvg;

	string comando;
	string cmd;

	Consola::gotoxy(10, 10);
	Consola::setTextSize(17, 17);
	Consola::setScreenSize(50, 80);
	Consola::setBackgroundColor(Consola::PRETO);
	Consola::setTextColor(Consola::AZUL_CLARO);
	Consola::clrscr();

	do {
		cout << "Introduza um comando." << endl << "As opcoes sao: " << endl;
		cout << "1 - carregaP <nomeFicheiro>" << endl;
		cout << "2 - carregaC <nomeFicheiro> " << endl;
		cout << "3 - carregaA <nomeFicheiro>" << endl;
		cout << "4 - cria <letraTipo> <dados do objeto>" << endl;
		cout << "5 - apaga <letraTipo> identificador" << endl;
		cout << "6 - entranocarro <letraCarro> <nomePiloto>" << endl;
		cout << "7 - saidocarro <letraCarro>" << endl;
		cout << "8 - lista" << endl;
		cout << "9 - corrida" << endl;
		cout << "10 - passatempo <n>" << endl;

		getline(cin, comando);
		istringstream iss(comando);

		do {
			string word, word1, word2, word3, word4;
			iss >> word >> word1 >> word2 >> word3 >> word4;

			if (comando == "carregaP")
				dvg.readfilePilotos("pilotos.txt");

			if (comando == "carregaC")
				dvg.readfileCarros("carros.txt");

			if (comando == "carregaA")
				dvg.readfileAutodromo("autodromos.txt");

			if (word == "cria") {
				if (word1 == "p") {
					dvg.addPiloto(word2, word3);
				}
				else if (word1 == "c") {
					dvg.addCarro(stoi(word1), stoi(word2), word3, word4);
				}
				else if (word1 == "a") {
					dvg.addAutodromo(stoi(word1), stoi(word2), word3);
				}
			};
			if (word == "apaga") {
				if (word1 == "p") {
					dvg.deletePiloto(word2);
				}
				else if (word1 == "c") {
					dvg.deleteCarro(word1[0]);
				}
				else if (word1 == "a") {
					dvg.deleteAutodromo(word1);
				}
			};
			if (word == "entranocarro")
				dvg.emparelha(word1[0],word2);

			if (word == "saidocarro")
				dvg.desemparelha(word1[0]);

			if (comando == "lista") {
				cout << "Pilotos:" << endl;
				for (int i = 0; i < dvg.vec_pilotos.size(); i++)
					cout << dvg.vec_pilotos[i]->GetPilotoAsString() << endl;
				cout << "Carros:" << endl;
				for (int i = 0; i < dvg.vec_carros.size(); i++)
					cout << dvg.vec_carros[i]->getAsString() << endl;
				cout << "Autodromos:" << endl;
				for (int i = 0; i < dvg.vec_autodromos.size(); i++)
					cout << dvg.vec_autodromos[i]->getNomeA() << endl;
			};
			if (word == "corrida") {
				int z = 0;
				dvg.vec_autodromos[z]->getPista()->Corrida(dvg);

			}
			fflush(stdin);
			cout << endl;
		} while (iss);
	} while (comando != "sair");
}