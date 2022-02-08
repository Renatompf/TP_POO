#ifndef GARAGEM_H
#define GARAGEM_H
#include <istream>
#include <string>
#include <ostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

class carros;
class DVG;
class pista;

class garagem
{
	int cap_max;
public:
	garagem(int max_cap);
	vector <carros*> carros_gar;
	void adicionaCarroGaragem(DVG &dvg);
	int getvecsize();
	carros* getCarrosGaragem(char identifier);
	int getCapmax();
};

#endif