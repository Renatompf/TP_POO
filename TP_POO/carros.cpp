#include "carros.h"
#include "pilotos.h"

char carros::idInicial = 'A';

carros::carros(int inicialCap, int maxCap, string label, string model) {
	marca = label;
	modelo = model;
	id = idInicial;
	idInicial++;
	if (idInicial > 'Z') {
		idInicial = '?';
	}
	cap_inicial = inicialCap;
	cap_max = maxCap;
	movimento = 0;
	p = nullptr;
	posx = 0;
	posy = 0;
	velocidade = 0;
	acelerador = 0; //porque acelerador não está a ser pressionado
	travao = 0; //porque travao não está a ser pressionado
	sinal_emerg = 0; //porque o sinal não está ativado
	estado = 0; //porque está operacional
}

/* carros::carros(string label) {
	marca = label;
	modelo = "modelo base";
	id = idInicial;
	idInicial++;
	if (idInicial > 'Z') {
		idInicial = '?';
	}
	cap_inicial = 100;
	cap_max = 100;
	/*acelerador = 0; //porque acelerador não está a ser pressionado
	travao = 0; //porque travao não está a ser pressionado
	sinal_emerg = 0; //porque o sinal não está ativado
	estado = 0; //porque o carro está parado
}*/

//Funçoes set
void carros::setMarca(string label) {
	marca = label;
}

void carros::setModelo(string model) {
	modelo = model;
}

void carros::setID(char ID) {
	id = ID;
}

void carros::setPiloto(pilotos* newp) {
	p = newp;
}

void carros::setAcelerador(bool novoacelera) {
	acelerador = novoacelera;
}

void carros::setTravao(bool slow) {
	travao = slow;
}

void carros::setCap_max(int maxCap) {
	cap_max = maxCap;
}

void carros::setCap_inicial(int inicialCap) {
	cap_inicial = inicialCap;
}

void carros::setSinalEmergencia(bool emergencySig) {
	sinal_emerg = emergencySig;
}

void carros::setEstado(bool state) {
	estado = state;
}

void carros::setVelocidade(int speed) {
	velocidade = speed;
}

void carros::set_X(int x) {
	this->posx = x;
}
void carros::set_Y(int y) {
	this->posx = y;

}

//Funcoes get
string carros::getMarca() {
	return marca;
}

string carros::getModelo() {
	return modelo;
}

char carros::getId() {
	return id;
}

int carros::getCap_max() {
	return cap_max;
}

int carros::getCap_inicial() {
	return cap_inicial;
}

pilotos* carros::getPiloto() {
	return p;
}

int carros::getAcelerador() {
	return acelerador;
}

int carros::getTravao() {
	return travao;
}

int carros::getSinalEmergencia() {
	return sinal_emerg;
}

int carros::getEstado() {
	return estado;
}

int carros::getVelocidade() {
	return velocidade;
}

int carros::getX_carros() {
	return posx;
}
int carros::getY_carros() {
	return posy;
}

//OBTER NUMA STRING
string carros::getAsString()const {
	ostringstream oss;
	oss << "\nID: " << id << " Marca: " << marca << " Modelo: " << modelo  << endl;
	return oss.str();
}

void carros::MovimentaCarro() {
	set_X(getX_carros() + getVelocidade());
	if(getCap_inicial() > 0)
		setCap_inicial(getCap_inicial() - 0.1);
	else
		setVelocidade(getVelocidade() - 1);
}

void carros::cPassasegundo(int receivedSec) {
	int i = 0;
	while (i < receivedSec) {
		MovimentaCarro();
		i++;
	}
}