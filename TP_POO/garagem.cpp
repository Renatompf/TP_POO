#include "garagem.h"
#include "DVG.h"

garagem::garagem(int max_cap) {
	cap_max = max_cap;
}

void garagem::adicionaCarroGaragem(DVG& dvg) {
	char inicial = 'A';
	for (int i = 0; i < dvg.obtemNCarros(); i++) {
		carros_gar.push_back(dvg.searchCarro(inicial));
		inicial++;
	}
}

carros* garagem::getCarrosGaragem(char identifier) {
	for (int i = 0; i < carros_gar.size(); i++) {
		if (carros_gar[i]->getId() == identifier) {
			return carros_gar[i];
		}
	}
}

int garagem::getvecsize() {
	return carros_gar.size();
}

int garagem::getCapmax() {
	return cap_max;
}