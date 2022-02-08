#include "surpresa.h"
#include "carros.h"

surpresa::surpresa(string tipe, string name):pilotos(tipe, name) {};

void surpresa::pPassasegundo(int receivedSec, int totalTime, pista* p, string pilot_name) {
	int i = 0;
	while (i < receivedSec) {
		if (getPosicao() == p->carros_pista.size()) {
			getCarro()->setAcelerador(0);
			getCarro()->setVelocidade(0);
			getCarro()->setTravao(0);
			getCarro()->setEstado(1);
		}
		i++;
	}
}