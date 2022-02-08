#ifndef Autodromo_h
#define Autodromo_h
#include <vector>
#include <fstream>
#include <istream>
#include <iostream>
#include <cstdlib>
#include <ostream>
#include <sstream>
#include "pilotos.h"
#include "pista.h"
#include "garagem.h"

using namespace std;

class DVG;

class Autodromo
{
	string nome_a;
	int n_carros;
	int comprimento;
	pista* p;
	garagem* g;

public:
	Autodromo(int n_cars, int lenght, string a_name);
	
	//GET FUNCTIONS
	string getNomeA();
	int getDistancia()const;
	int getNcarros();
	pista* getPista();
	garagem* getGaragem();

	//SET FUNCTIONS
	void setNomeA(string nome_auto);
	void setNCarros(int numCarros);
	void setDistacia(int distance);
};

#endif