#ifndef surpresa_h
#define surpresa_h
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

class surpresa : public pilotos
{

public:
	surpresa(string tipe, string name);
	void pPassasegundo(int receivedSec, int totalTime, pista* p, string pilot_name);
};

#endif