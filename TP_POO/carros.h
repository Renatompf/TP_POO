#ifndef carros_h 
#define carros_h

#include <istream>
#include <string>
#include <ostream>
#include <cstdlib>
#include <sstream>

using namespace std;

class pilotos;
class pista;

class carros
{
	static char idInicial;
	int cap_inicial, cap_max;
	string marca;
	string modelo;
	char id;
	int movimento; //DEFINE SE O CARRO EST� PARADO OU EM MOVIMENTO
	int posx, posy; //POSICAO ONDE SE ENCONTRAM
	int lugar; //CLASSIFICA��O NA CORRIDA
	pilotos* p;
	int segundos;
	bool acelerador, travao; //DEFINIR SE EST� A ACELERAR, OU N�O, E SE EST� A TRAVAR, OU N�O
	bool sinal_emerg; //DEFINIR SE EST� LIGADO, OU DESLIGADO
	bool estado; //SABER SE EST� OPERACIONAL, OU N�O
	int velocidade;
	

public:
	carros(int inicialCap, int maxCap, string label, string model =  "modelo base");

	//Fun�oes set
	void setMarca(string label);
	void setModelo(string model);
	void setID(char ID);
	void setPiloto(pilotos* newp);
	void set_X(int x);
	void set_Y(int y);
	void setAcelerador(bool novoacelera);
	void setSinalEmergencia(bool emergencySig);
	void setEstado(bool state);
	void setTravao(bool slow);
	void setVelocidade(int speed);
	void setCap_max(int maxCap);
	void setCap_inicial(int inicialCap);

	//Funcoes get
	string getMarca();
	string getModelo();
	int getCap_inicial();
	int getCap_max();
	char getId();
	pilotos* getPiloto();
	int getSinalEmergencia();
	int getAcelerador();
	int getEstado();
	int getTravao();
	int getVelocidade();
	int getX_carros();
	int getY_carros();

	//Tranformar em string
	string getAsString()const;

	void MovimentaCarro();
	void cPassasegundo(int receivedSec);
};

#endif