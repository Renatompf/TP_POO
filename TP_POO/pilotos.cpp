#include "pilotos.h"

pilotos::pilotos(string tipe, string name) {
	nome_p = name;
	tipo = tipe;
	c = nullptr;
};


//FUNCOES SET
void pilotos::setNome(const string nome_pi) {
	nome_p = nome_pi;
}

void pilotos::setTipo(string tipo_pi) {
	tipo = tipo_pi;
}

void pilotos::setCarro(carros* newc) {
	c = newc;
}

void pilotos::setPosicao(int position) {
	posicao = position;
}

//FUNCOES GET
string pilotos::getNome() {
	return nome_p;
}

string pilotos::getTipo() {
	return tipo;
}

carros* pilotos::getCarro() {
	return c;
}

int pilotos::getPosicao() {
	return posicao;
}

string pilotos::GetPilotoAsString() {
	stringstream oss;
	oss << "Nome: " << nome_p << " " << "Tipo: " << tipo;
	return oss.str();
}