#include "Autodromo.h"

Autodromo::Autodromo(int n_cars, int lenght ,string a_name) {
	nome_a = a_name;
	n_carros = n_cars;
	comprimento = lenght;
	p = new pista(comprimento, this);
	g = new garagem(n_carros);

}

//FUNÇOES GET
string Autodromo::getNomeA() {
	return nome_a;
}

int Autodromo::getDistancia()const {
	return comprimento;
}

int Autodromo::getNcarros() {
	return n_carros;
}

pista* Autodromo::getPista() {
	return p;
}

garagem* Autodromo::getGaragem() {
	return g;
}

//FUNÇOES SET
void Autodromo::setNomeA(string nome_auto) {
	nome_a = nome_auto;
}

void Autodromo::setNCarros(int numCarros) {
	n_carros = numCarros;
}

void Autodromo::setDistacia(int distance) {
	comprimento = distance;
}
