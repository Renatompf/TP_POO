#ifndef crazy_h
#define crazy_h
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <istream>
#include <cstdlib>
#include <ostream>
#include <sstream>
#include "pilotos.h"
#include "pista.h"

using namespace std;


class carros;
class dvg;

class crazy : public pilotos
{
	int comeca_correr;
public:
	crazy(string tipe, string name);
	int comecaCorrer();
	bool danificaAutomovel();
	void pPassasegundo(int receivedSec, int totalTime, pista* p, string pilot_name);

};

#endif