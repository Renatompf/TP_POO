#include "crazy.h"
#include "carros.h"

crazy::crazy(string tipe, string name):pilotos(tipe,name) {
	comeca_correr = comecaCorrer();
};

int crazy::comecaCorrer() {
	int comeca = (rand() % 5) + 1;
	return comeca;
}

bool crazy::danificaAutomovel() {
	int desastre = (rand() % 100) + 1;
	if (desastre >= 1 && desastre <= 5)
		return true;
	return false;
}

void crazy::pPassasegundo(int receivedSec, int totalTime, pista* p, string pilot_name) {
	int i = 0;
	int posicao_antiga = 0; //VAI GUARDAR A POSICAO DO PILOTO NO INSTANTE ANTERIOR
	for (int i = 0; i < p->pilotos_pista.size(); i++) {
		if (p->pilotos_pista[i]->getNome() == pilot_name){
			posicao_antiga = p->pilotos_pista[i]->getPosicao();
		}
	}

	p->AtualizaPosicao();

	if(comeca_correr >= totalTime){
		if (danificaAutomovel() == true) {
			getCarro()->setAcelerador(0);
			getCarro()->setVelocidade(0);
			getCarro()->setTravao(0);
			getCarro()->setEstado(1);
		}
		else{
			while (i < receivedSec) {
				if (getPosicao() == p->carros_pista.size()) {
					getCarro()->setAcelerador(0) ;
					getCarro()->setTravao(1);
					getCarro()->setVelocidade(0);
				}
				if (getPosicao() == 1) {
					getCarro()->setAcelerador(1);
					getCarro()->setTravao(0);
				}
				if (getPosicao() - posicao_antiga > 0 && getPosicao() == p->carros_pista.size()) {
					getCarro()->setAcelerador(0);
					getCarro()->setTravao(1);
					getCarro()->setVelocidade(2);
				}
				if (getPosicao() != p->carros_pista.size() && getPosicao() != 1) {
					getCarro()->setAcelerador(0);
					getCarro()->setTravao(1);
					getCarro()->setVelocidade(getCarro()->getVelocidade()+1);
				}
				i++;
			}
		}
	}
}
