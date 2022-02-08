#include "pista.h"
#include "garagem.h"
#include "DVG.h"

pista::pista(int length, Autodromo* a) {
	comprimento = length;
	tempo_decorrido = 0;
	autodromo_pista = a;
};

int pista::getComprimento() {
	return comprimento;
}

void pista::AdicionaCarrosPista(DVG& dvg){
	autodromo_pista->getGaragem()->adicionaCarroGaragem(dvg);
	for (int i = 0; i < autodromo_pista->getGaragem()->getvecsize() ; i++){
		if (autodromo_pista->getGaragem()->carros_gar[i]->getPiloto() != nullptr && autodromo_pista->getGaragem()->carros_gar[i]->getEstado() == 0 && i <= autodromo_pista->getGaragem()->getCapmax()) {
			carros_pista.push_back(autodromo_pista->getGaragem()->carros_gar[i]);
			pilotos_pista.push_back(autodromo_pista->getGaragem()->carros_gar[i]->getPiloto());
			cout << carros_pista[i]->getAsString() << endl;
			cout << pilotos_pista[i]->getNome() << endl;
		}
		else
			++i;
	}
}


void pista::AtualizaPosicao() {
	for (int i = 0; i < carros_pista.size()-1; i++){
		if (i == 0) 
			carros_pista[i]->getPiloto()->setPosicao(1);
		else
		{
			for (int j = 1; j < carros_pista.size(); j++) {
				if (carros_pista[j]->getX_carros() > carros_pista[i]->getX_carros()) {
					carros_pista[j]->getPiloto()->setPosicao(i - 1);
					i++;
				}
			}
		}
	}
}

void pista::Passatempo(int receivedTime) {
	tempo_decorrido += receivedTime;

	for (int i = 0; i < pilotos_pista.size(); i++) {
		pilotos_pista[i]->pPassasegundo(receivedTime, tempo_decorrido, this ,pilotos_pista[i]->getNome());
	}

	for (int i = 0; i < carros_pista.size(); i++) {
		carros_pista[i]->cPassasegundo(receivedTime);
	}

	AtualizaPosicao();
}

void pista::preparaCorrida(DVG& dvg) {
	AdicionaCarrosPista(dvg);
	//cout << "\nInformacao sobre a corrida no autodromo " << autodromo_pista->getNomeA() << "(" << autodromo_pista->getDistancia() << ")" << endl;
}

void pista::terminaCorrida(DVG& dvg) {
	for (int i = 0; i < pilotos_pista.size(); i++) { //METE OS PILOTOS APEADOS
		dvg.desemparelha(pilotos_pista[i]->getCarro()->getId());
	}
	for (int i = 0; i < carros_pista.size(); i++) { //ELIMINA OS CARROS DA PISTA(VÃO PARA A GARAGEM)
		delete carros_pista[i];
		carros_pista.erase(carros_pista.begin() + i);
	}
}

void pista::Corrida(DVG& dvg) {
	preparaCorrida(dvg);
	int aux = 0, aux2 = 0;
	string decisao;
	
	do {
		cout << "Menu Corrida: " << endl;
		cout << "1 - Passatempo <n> " << endl;
		cout << "2 - Stop <nomePiloto> " << endl;
		cout << "3 - Destroi <letraCarro> " << endl;
		cout << "4 - Acidente <letraCarro> " << endl;

		getline(cin, decisao);
		istringstream iss(decisao);

		do {
			string word, word1;
			iss >> word >> word1;

			if (word == "Passatempo")
				Passatempo(stoi(word1));

			if (word == "Stop") {
				for (int i = 0; i < pilotos_pista.size(); i++) {
					if (pilotos_pista[i]->getNome() == word1) {
						dvg.stop(word1);
					}
				}
			}
				
			if (word == "Destroi") {
				for (int i = 0; i < carros_pista.size(); i++) {
					if (carros_pista[i]->getId() == word1[0]) {
						dvg.deleteCarro(word1[0]);
					}
				}
			}

			if (word == "Acidente") {
				for (int i = 0; i < carros_pista.size(); i++) {
					if (carros_pista[i]->getId() == word1[0]) {
						dvg.acidente(word1[0]);
					}
				}
			}

		} while (iss);

		for (int i = 0; i < pilotos_pista.size(); i++) {
			if (pilotos_pista[i]->getCarro()->getEstado() == 0)
				aux++;
		}

		for (int i = 0; i < pilotos_pista.size(); i++) {
			if (pilotos_pista[i]->getCarro()->getX_carros() >= comprimento)
				aux2++;
		}
	} while (aux != aux2);
	terminaCorrida(dvg);
}

void pista::desenhaPista(int num)
{
	int y3 = 10;
	for (int i = 0; i < num; i++) {
		Consola::drawLine(5, y3, 500, y3, RGB(255, 0, 0));
		cout << pilotos_pista[i]->pilotos::getNome() << endl;
		y3 = y3 + 30;
	}
	/*Consola::clrscr();
	cout << "Pressione uma tecla para sair do modo de desenho!" << endl;*/
}