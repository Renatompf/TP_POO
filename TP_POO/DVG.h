#ifndef DVG_H
#define DVG_H

#include <istream>
#include <string>
#include <ostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <fstream>
#include "carros.h"
#include "pilotos.h"
#include "Autodromo.h"

using namespace std;

class crazy;
class surpresa;
class rapido;

class DVG
{

public:
	DVG();

	vector <pilotos*> vec_pilotos;
	vector <carros*> vec_carros;
	vector <Autodromo*> vec_autodromos;

	//PILOTOS
	pilotos* addPiloto(string nome_pi, string tipo_pi);
	pilotos* searchPiloto(string nome_pi) const;
	void readfilePilotos(string filename);
	void readfileCarros(string filename);
	void deletePiloto(string nome);
	int ObtemNPilotos();
	void stop(string nome);

	//CARROS
	void addCarro(int inicialCap, int maxCap, string label, string model);
	void deleteCarro(char identifier);
	carros* searchCarro(char identifier);
	int obtemNCarros();
	void carregaTudo();
	void carregaBat(char car_id, int energy);
	void acidente(char car_id);

	//AUTODROMO
	void readfileAutodromo(string filename);
	void deleteAutodromo(string nome);
	Autodromo* searchAutodromo(string name);
	void addAutodromo(int ncars, int lenght, string name);
	void getAutodromoAsString();
	
	void listaConteudo();
	~DVG();

	void emparelha(char car_id, string pilot_name);
	void desemparelha(char car_id);
};

#endif