#ifndef rapido_h
#define rapido_h
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

class rapido : public pilotos
{
public:
	rapido(string tipe, string name);
	bool sofrePanico();
	void pPassasegundo(int receivedSec, int totalTime, pista* p, string pilot_name);
};

#endif