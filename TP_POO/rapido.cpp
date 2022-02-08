#include "rapido.h"
#include "carros.h"

rapido::rapido(string tipe, string name) :pilotos(tipe, name) {};

bool rapido::sofrePanico() {
	int panico = (rand() % 100) + 1;
	if (panico >= 1 && panico <= 10)
		return true;
	else 
		return false;
}

void rapido::pPassasegundo(int receivedSec, int totalTime, pista* p, string pilot_name) {
	int i = 0;
	while (i < receivedSec) {
		if (getCarro()->getCap_inicial() <= getCarro()->getCap_max() / 2) {
			if (i % 3 == 0) {
				getCarro()->setAcelerador(1);
				getCarro()->setVelocidade(getCarro()->getVelocidade() + 1);
			}
		}
		else
		{
			getCarro()->setAcelerador(1);
			getCarro()->setVelocidade(i + 1);
		}
		i++;
	}
}

