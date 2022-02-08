#ifndef pista_h 
#define pista_h
#include <istream>
#include <string>
#include <ostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <fstream>
#include "garagem.h"
#include "consola.h"

class Autodromo;
class carros;
class DVG;
class pilotos;

using namespace std;

class pista
{
	int comprimento;
	int tempo_decorrido;
	Autodromo* autodromo_pista;
public:
	vector <carros*> carros_pista;
	vector <pilotos*> pilotos_pista;

	pista(int length, Autodromo* a);

	int getComprimento();

	void AdicionaCarrosPista(DVG& dvg);
	void AtualizaPosicao();
	void Passatempo(int receivedTime);
	void preparaCorrida(DVG& dvg);
	void terminaCorrida(DVG& dvg);
	void Corrida(DVG& dvg);
	void desenhaPista(int num);
};

#endif