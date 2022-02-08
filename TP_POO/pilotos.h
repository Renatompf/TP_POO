#ifndef pilotos_h
#define pilotos_h

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <istream>
#include <cstdlib>
#include <ostream>
#include <sstream>
class carros;
class pista;

using namespace std;

class pilotos
{
	string nome_p;
	string tipo; //SABER SE É CRAZY, SURPRESA OU RÁPIDO
	carros* c;
	int posicao;
	//int segundos;

public:
	pilotos(string tipe, string name);

	//FUNCOES SET
	void setNome(const string name);
	void setTipo(string tipe);
	void setCarro(carros* carro);
	void setPosicao(int position);

	//FUNCOES GET
	int getPosicao();
	string getNome();
	string getTipo();
	carros* getCarro();
	string GetPilotoAsString();

	virtual void pPassasegundo(int receivedSec, int totalTime, pista* p, string pilot_name) = 0;
};
#endif